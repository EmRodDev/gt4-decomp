/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Camera { char pad[0x2C0]; };
struct Pillar { char pad[0x30]; };
struct Entity { char pad[0x178]; };
struct Mtx { float m[4][4]; };
struct Category { char pad[0xA88]; Mtx *mtxA; Mtx *mtxB; char pad2[0xAA4 - 0xA90]; };
struct Team { char pad[0xA0]; };
struct Tiny { char pad[0x12EC]; };
struct Pair { int a, b; };
struct Pitmen {
    int mode;
    Camera camera;
    Pillar pillar[6];
    Entity entity[6][6];
    Category category[6];
    Team team[6];
    Tiny tiny;
    int u8F48[6][3];
    int u8F90[6][3];
    int u8FD8[6][4];
    int u9038[6][4];
    int u9098[6][4];
    char pad90F8[0x108];
    int u9200[6][4];
    int u9260[6];
    int u9278[6];
    int u9290[6];
    int u92A8[6];
    Mtx mtxA[4];
    Mtx mtxB[4];
    int u94C0[4];
    int u94D0[4];
    float u94E0[4];
    int u94F0[4];
    int u9500[4];
    float u9510[4];
    int u9520[6][4];
    int u9580[6][4];
    int u95E0[6][4];
    int u9640[6];
    int u9658[6];
    int u9670;
    int u9674;
    int u9678;
    int u967C;
    int u9680;
    int u9684[6];
    int u969C[6];
    int u96B4[6];
    int u96CC;
    int u96D0;
    int u96D4;
    int u96D8[6][4][2];
    int u9798[6][4][2];
    int u9858[6][4];
    Pair u98B8[6];
};

extern "C" void Pitmen__Camera__clear(Camera *) throw();
extern "C" void Pitmen__StatusCategory__clear(Category *) throw();
extern "C" int Pitmen__is_tireman(unsigned int) throw() __attribute__((const));
extern "C" void Pitmen__StatusEntity__clear(Entity *) throw();
extern "C" void Pitmen__StatusTeam__clear(Team *) throw();
extern "C" void PitmenTiny__clear(Tiny *);
extern "C" void PitinPillar__clear(Pillar *);

#define IDENTITY(mt) \
    (mt)->m[0][0] = 1.0f; (mt)->m[1][0] = 0.0f; (mt)->m[2][0] = 0.0f; (mt)->m[3][0] = 0.0f; \
    (mt)->m[0][1] = 0.0f; (mt)->m[1][1] = 1.0f; (mt)->m[2][1] = 0.0f; (mt)->m[3][1] = 0.0f; \
    (mt)->m[0][2] = 0.0f; (mt)->m[1][2] = 0.0f; (mt)->m[2][2] = 1.0f; (mt)->m[3][2] = 0.0f; \
    (mt)->m[0][3] = 0.0f; (mt)->m[1][3] = 0.0f; (mt)->m[2][3] = 0.0f; (mt)->m[3][3] = 1.0f

static inline int numTire() { return 4; }
static inline int numTeam() { return 6; }

extern "C" void Pitmen__clear(Pitmen *self, int mode) {
    int i, k;

    self->mode = mode;
    self->u96D4 = self->u96D0 = self->u96CC;
    Pitmen__Camera__clear(&self->camera);
    self->u9670 = 0;
    self->u9674 = -1;
    self->u9678 = -1;
    self->u967C = 0;
    self->u9680 = 1;
    PitmenTiny__clear(&self->tiny);
    for (i = 0; i < 6; i++) {
        char *b = (char *)self + i * sizeof(Category);
        Pitmen__StatusCategory__clear((Category *)(b + 0x38C4));
        if (Pitmen__is_tireman(i)) {
            ((Category *)(b + 0x38C4))->mtxA = &self->mtxA[i];
            ((Category *)(b + 0x38C4))->mtxB = &self->mtxB[i];
            IDENTITY(&self->mtxA[i]);
            IDENTITY(&self->mtxB[i]);
        } else {
            ((Category *)(b + 0x38C4))->mtxA = 0;
            ((Category *)(b + 0x38C4))->mtxB = 0;
        }
        for (k = 0; k < 6; k++) {
            Pitmen__StatusEntity__clear(&self->entity[k][i]);
        }
    }
    for (i = 0; i < numTire(); i++) {
        self->u94C0[i] = 0;
        self->u94D0[i] = 0;
        self->u94E0[i] = 1.0f;
        self->u94F0[i] = 0;
        self->u9500[i] = 0;
        self->u9510[i] = 1.0f;
        for (k = 0; k < numTeam(); k++) {
            self->u8FD8[k][i] = 0;
            self->u9038[k][i] = 0;
            self->u9098[k][i] = 0;
            self->u9200[k][i] = 0;
            self->u9520[k][i] = 0;
            self->u9580[k][i] = 0;
            self->u95E0[k][i] = 0;
            self->u96D8[k][i][0] = 0;
            self->u96D8[k][i][1] = 0;
            self->u9798[k][i][0] = 0;
            self->u9798[k][i][1] = 0;
            self->u9858[k][i] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        self->u8F48[i][0] = 0;
        self->u8F48[i][1] = 0;
        self->u8F48[i][2] = 0;
        self->u8F90[i][0] = 0;
        self->u8F90[i][1] = 0;
        self->u8F90[i][2] = 0;
        self->u9260[i] = 0;
        self->u92A8[i] = 0;
        self->u9290[i] = 0;
        self->u9278[i] = 0;
        PitinPillar__clear(&self->pillar[i]);
        self->u9684[i] = 0;
        self->u969C[i] = 0;
        self->u9640[i] = 0;
        self->u9658[i] = 0;
        self->u96B4[i] = -1;
        Pitmen__StatusTeam__clear(&self->team[i]);
        self->u98B8[i].a = self->u98B8[i].b = 0;
    }
}
