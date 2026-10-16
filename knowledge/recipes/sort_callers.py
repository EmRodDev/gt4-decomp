#!/usr/bin/env python3
"""Reproduce garage sort callers from the already verified 001475A8 source model.

Writes drafts only. Public algorithm bodies remain in include/stl/; see
THIRD_PARTY.md. Constructor/destructor asm labels name existing functions,
not assembly instructions. Address-specific model types avoid ODR collisions.
"""
import argparse
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
BASE = ROOT / 'src/gamedata/unit_0013B5F8/func_001475A8.cpp'
TARGETS = {'005C5D18': 'callback', '005C60A0': 'callback',
           '005C6868': 'callback', '005C6428': 'float',
           '005C6BF0': 'string', '005C54F0': 'sequence'}

CALLBACK_DECLS = '''/* The input has three 64-bit words; their meanings remain unidentified. */
struct SortCallbackInput { long long words[3]; };
/* The record selector returns a cell containing a full 64-bit database id. */
extern "C" const long long *func_00441248(void *);
extern "C" long long func_004454C0(const long long *);
extern "C" int func_00448820(long long rowId, SortCallbackInput *);
typedef int (*ScoreCallback)(const SortCallbackInput &);'''
CALLBACK_BODY = '''    Vec values(hArray__size(array.value));
    for (unsigned int i = 0; i < values.size(); ++i) {
        SortCallbackInput input;
        /* Keep the temporary garage handle alive until the input is read. */
        func_00448820(func_004454C0(func_00441248(
            func_00147D80(GarageRef(array[i])))), &input);
        values[i] = make_score(array[i], (float)score(input));
    }
    sort(values.begin(), values.end(), Less());
    func_005C6428(array, values, ascending);
'''
WRITEBACK_BODY = '''    unsigned int count = values.size();
    for (unsigned int i = 0; i < count; ++i) {
        array[i] = values[ascending ? i : count - i - 1].ref;
    }
    /* The original ABI destroys both by-value parameters in this callee. */
'''
SEQUENCE_MODEL = '''
extern "C" Heap *func_005C1368();
template<class T> struct SequenceAlloc : Alloc<T> {
    template<class U> struct rebind { typedef SequenceAlloc<U> other; };
    T *allocate(size_t count, const void * = 0) {
        return (T *)func_00326750(count * sizeof(T), 4, func_005C1368()->name);
    }
    void deallocate(T *p, size_t count) {
        func_00326798(p, count * sizeof(T), 4, func_005C1368()->name);
    }
};
struct SequenceKey {
    vector<unsigned short, SequenceAlloc<unsigned short> > values;
};
struct Elem {
    GarageRef ref;
    SequenceKey key;
};
'''


def source(address):
    mode = TARGETS[address]
    base = BASE.read_text()
    assert base.startswith('/* compiler: ee-gcc2.96-stl */')
    handles = base[:base.index('struct Elem;')]
    containers = base[base.index('struct ArrayRef'):base.index('inline bool operator<')]
    if mode == 'callback':
        text = base[:base.index('extern "C" void func_001475A8(')]
        text = text.replace('extern "C" float func_0043DDB0(void *);', CALLBACK_DECLS)
        body = CALLBACK_BODY
        params = 'ArrayRef array, int ascending, ScoreCallback score'
    else:
        # Writeback needs the value layout and lifetimes, without scoring helpers.
        for header in ('stl_function.h', 'stl_tempbuf.h', 'stl_heap.h', 'stl_algo.h'):
            handles = handles.replace(f'#include <{header}>\n', '')
        containers = containers.replace('extern "C" unsigned int hArray__size(void *);\n', '')
        containers = containers.replace('extern "C" void *func_00147D80(void *);\n', '')
        containers = containers.replace('extern "C" float func_0043DDB0(void *);\n', '')
        getter = {'float': '005C9B90', 'string': '005C9BD0', 'sequence': '005C9B50'}[mode]
        containers = containers.replace('005C9B90', getter)
        if mode == 'sequence':
            model = SEQUENCE_MODEL
        else:
            field = 'float score;' if mode == 'float' else 'const char *key;'
            model = '\nstruct Elem { GarageRef ref; ' + field + ' };\n'
        text = handles + containers + model + 'typedef vector<Elem, Alloc<Elem> > Vec;\n'
        body, params = WRITEBACK_BODY, 'ArrayRef array, Vec values, int ascending'
    text += f'extern "C" void func_{address}({params}) {{\n{body}}}\n'
    description = ('Calculate callback scores, sort, and write garage handles back.'
                   if mode == 'callback' else
                   f'Write garage handles back in forward/reverse {mode}-key order.')
    text = text.replace('/* compiler: ee-gcc2.96-stl */\n',
        '/* compiler: ee-gcc2.96-stl */\n'
        f'/* {description}\n'
        '   Reproduce with knowledge/recipes/sort_callers.py. Labels below bind\n'
        '   existing game functions; object lifetimes use ordinary C++. */\n', 1)
    # Document a real ownership requirement rather than a register-level idiom.
    text = text.replace('            void *p = other.value;',
        '            /* Retain first: two handles can reference the same object. */\n'
        '            void *incomingObject = other.value;')
    text = text.replace('if (p) func_003285A8(p);', 'if (incomingObject) func_003285A8(incomingObject);')
    text = text.replace('value = p;', 'value = incomingObject;')
    text = text.replace(
        '    GarageRef &operator=(const GarageRef &other) { Ref::operator=(other); return *this; }',
        '    GarageRef &operator=(const GarageRef &other) {\n'
        '        Ref::operator=(other);\n'
        '        return *this;\n'
        '    }')
    entry_name = {'callback': 'GarageScore', 'float': 'GarageScore',
                  'string': 'GarageStringKey', 'sequence': 'GarageSequenceKey'}[mode]
    names = {'Ref': 'ScriptHandle', 'GarageRef': 'GarageHandle',
             'ArrayRef': 'ScriptArrayHandle', 'Heap': 'TypeInfoName',
             'Mid': 'ScoredHandle', 'Elem': entry_name, 'Alloc': 'TaggedSortAllocator',
             'Vec': 'SortEntries', 'Less': 'AscendingScore',
             'SequenceAlloc': 'TaggedSequenceAllocator', 'SequenceKey': 'UnsignedShortKey'}
    # These translation-unit models do not assert a canonical shared game header.
    for old, new in names.items():
        text = re.sub(r'\b' + old + r'\b', new + '_' + address, text)
    text = re.sub(r'\bref\b', 'handle', text)
    text = re.sub(r'\bmake_score\b', 'makeScoredHandle', text)
    if mode == 'callback':
        # Aliases shorten template signatures without changing their types or ABI.
        start = text.index('inline bool operator<')
        end = text.index(f'extern "C" void func_{address}(')
        text = text[:start] + f'''inline bool operator<(const GarageScore_{address} &left,
                      const GarageScore_{address} &right) {{
    return left.score < right.score;
}}
typedef GarageScore_{address} SortEntry;
typedef less<SortEntry> AscendingScore_{address};
typedef vector<SortEntry, TaggedSortAllocator_{address}<SortEntry> > SortEntries_{address};

template<> SortEntry *__uninitialized_fill_n_aux<SortEntry *, size_t, SortEntry>(
    SortEntry *, size_t, const SortEntry &, __false_type) __asm__("func_005C6578");
template<> SortEntry *__uninitialized_copy_aux<const SortEntry *, SortEntry *>(
    const SortEntry *, const SortEntry *, SortEntry *, __false_type) __asm__("func_005C6800");
template<> void __introsort_loop<SortEntry *, SortEntry, ptrdiff_t, AscendingScore_{address}>(
    SortEntry *, SortEntry *, SortEntry *, ptrdiff_t, AscendingScore_{address})
    __asm__("func_005C65E0");
template<> void __final_insertion_sort<SortEntry *, AscendingScore_{address}>(
    SortEntry *, SortEntry *, AscendingScore_{address}) __asm__("func_005C6780");

extern "C" void func_005C6428(ScriptArrayHandle_{address}, SortEntries_{address}, int);
static inline ScoredHandle_{address} makeScoredHandle(
    const ScriptHandle_{address} &object, const float &score) {{
    return ScoredHandle_{address}(object, score);
}}
''' + text[end:]
    return text.replace('};\nstruct ', '};\n\nstruct ')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path,
                        default=ROOT / 'build/swarm/sort-callers/reproduced')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    for address in TARGETS:
        path = args.output / f'func_{address}.cpp'
        path.write_text(source(address))
        print(path)


if __name__ == '__main__':
    main()
