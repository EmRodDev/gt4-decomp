#!/usr/bin/env python3
"""Recreate handle/key sorting instantiations without modifying src/ or judging them.

Uses the public SGI headers already in include/stl/ (see THIRD_PARTY.md).
The descriptive type names identify layouts, not recovered original class names.
"""
import argparse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MEMBERS = (
    'introsort_loop', 'unguarded_partition', 'partial_sort', 'insertion_sort',
    'sort_heap', 'make_heap', 'adjust_heap', 'push_heap',
    'unguarded_linear_insert', 'unguarded_insertion_sort_aux',
)
FAMILIES = {
    'float': ('005C65E0', '005C7988', '005C7AD8', '005C7C48', '005C8AA8',
              '005C8BE0', '005C8C88', '005C9550', '005C8E20', '005C7DF0'),
    'string': ('005C6DA8', '005C7E68', '005C7F98', '005C80F0', '005C8F18',
               '005C9050', '005C90F8', '005C9698', '005C9288', '005C8288'),
    'sequence': ('005C5908', '005C7098', '005C7300', '005C75A0', '005C8300',
                 '005C8588', '005C86C0', '005C9378', '005C8950', '005C7888'),
}
# These helpers were already present upstream; preserve their implementations.
EXISTING = {'005C8BE0', '005C8E20', '005C7DF0', '005C9050', '005C9288', '005C8288'}
RETURNING_CTOR = {'005C75A0', '005C7E68', '005C7F98', '005C8300',
                  '005C8AA8', '005C8F18', '005C90F8'}
SIGNATURES = {
    'introsort_loop': 'void|V *, V *, V *, int, C',
    'unguarded_partition': 'V *|V *, V *, V, C',
    'partial_sort': 'void|V *, V *, V *, V *, C',
    'insertion_sort': 'void|V *, V *, C',
    'sort_heap': 'void|V *, V *, C',
    'make_heap': 'void|V *, V *, C, V *, int *',
    'adjust_heap': 'void|V *, int, int, V, C',
    'push_heap': 'void|V *, int, int, V, C',
    'unguarded_linear_insert': 'void|V *, V, C',
    'unguarded_insertion_sort_aux': 'void|V *, V *, V *, C',
}
HEADERS = '''#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
'''
HANDLE = '''
/* Existing game helpers: copy/destroy a handle, then retain/release an object. */
extern "C" CTOR_RETURN func_0013BD50(void *, const void *);
extern "C" void func_0013BD68(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

struct ScoreHandle_TAG {
    void *object;
    ScoreHandle_TAG(const ScoreHandle_TAG &other) {
        func_0013BD50(this, &other);
    }
    ~ScoreHandle_TAG() { func_0013BD68(this, 2); }
    ScoreHandle_TAG &operator=(const ScoreHandle_TAG &other) {
        if (this != &other) {
            /* Retain first: distinct handles may refer to the same object. */
            void *incomingObject = other.object;
            if (incomingObject) func_003285A8(incomingObject);
            if (object) func_003285F8(object);
            object = incomingObject;
        }
        return *this;
    }
};
'''
SEQUENCE = '''
struct TypeInfo { const char *name; };
extern "C" void *func_005C1368();
extern "C" void *func_00326750(int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void *func_005C5790(void *, const void *)ASSIGN_THROW;
extern "C" bool func_005C97E0(const unsigned short *, const unsigned short *,
                             const unsigned short *, const unsigned short *);

template <class T>
class SortAlloc_TAG {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef SortAlloc_TAG<U> other; };
    SortAlloc_TAG() throw() {}
    SortAlloc_TAG(const SortAlloc_TAG &) throw() {}
    template <class U> SortAlloc_TAG(const SortAlloc_TAG<U> &) throw() {}
    ~SortAlloc_TAG() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4,
                                 ((TypeInfo *)func_005C1368())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)func_005C1368())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct ScoreKey_TAG {
    vector<unsigned short, SortAlloc_TAG<unsigned short> > values;
    ScoreKey_TAG &operator=(const ScoreKey_TAG &other) {
        if (this != &other) func_005C5790(this, &other);
        return *this;
    }
};
'''
VALUE = '''
struct ScoreValue_TAG {
    ScoreHandle_TAG handle;
    KEY_FIELD
};
struct ScoreLess_TAG {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const ScoreValue_TAG &a,
                    const ScoreValue_TAG &b) const {
        return COMPARE;
    }
};
'''


def source(family, member):
    mapping = dict(zip(MEMBERS, FAMILIES[family]))
    address = mapping[member]
    description = {'float': 'floating-point score', 'string': 'string key',
                   'sequence': 'unsigned-short sequence key'}[family]
    text = ('/* compiler: ee-gcc2.96-stl */\n'
            f'/* SGI STL {member}: handle and {description}.\n'
            '   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */\n')
    for name, target in mapping.items():
        text += f'#define {name if name == "sort_heap" else "__" + name} func_{target}\n'
    text += HEADERS
    if family == 'sequence':
        text += '#include <stl_alloc.h>\n#include <stl_vector.h>\n'
    text += '#include <stl_algo.h>\n' + HANDLE
    if family == 'sequence':
        text += SEQUENCE
        field = 'ScoreKey_TAG key;'
        compare = ('func_005C97E0(a.key.values.begin(), a.key.values.end(), '
                   'b.key.values.begin(), b.key.values.end())')
    elif family == 'string':
        text += '\nextern "C" int func_0057F238(const char *, const char *);\n'
        field, compare = 'const char *key;', 'func_0057F238(a.key, b.key) < 0'
    else:
        field, compare = 'float score;', 'a.score < b.score'
    text += VALUE.replace('KEY_FIELD', field).replace('COMPARE', compare)
    result, params = SIGNATURES[member].split('|')
    result = result.replace('V', 'ScoreValue_TAG')
    params = params.replace('V', 'ScoreValue_TAG').replace('C', 'ScoreLess_TAG')
    text += f'template {result} func_{address}({params});\n'
    entry = {'float': 'FloatSortEntry', 'string': 'StringSortEntry',
             'sequence': 'SequenceSortEntry'}[family]
    comparator = {'float': 'FloatScoreLess', 'string': 'StringKeyLess',
                  'sequence': 'SequenceKeyLess'}[family]
    text = (text.replace('ScoreHandle', 'RefCountedHandle')
            .replace('ScoreValue', entry).replace('ScoreLess', comparator)
            .replace('ScoreKey', 'SequenceKey').replace('SortAlloc', 'TaggedSequenceAllocator'))
    return (text.replace('CTOR_RETURN', 'void *' if address in RETURNING_CTOR else 'void')
            .replace('ASSIGN_THROW', ' throw()' if address == '005C75A0' else '')
            .replace('TAG', address).replace('void * func_', 'void *func_'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path,
                        default=ROOT / 'build/swarm/scored-sort/reproduced')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    for family, addresses in FAMILIES.items():
        for member, address in zip(MEMBERS, addresses):
            if address not in EXISTING:
                path = args.output / f'func_{address}.cpp'
                path.write_text(source(family, member))
                print(path)


if __name__ == '__main__':
    main()
