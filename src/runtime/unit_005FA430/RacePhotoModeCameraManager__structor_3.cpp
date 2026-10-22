/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root { virtual ~Root(); };
struct Base : Root {
    virtual ~Base();
    char pad[0xF80 - 4];
    Base() __asm__("func_00377C98");
};
struct RacePhotoModeCameraManager : Base {
    const int fF80;
    int fF84;
    RacePhotoModeCameraManager(int) __asm__("func_005FD708");
    virtual ~RacePhotoModeCameraManager();
};
RacePhotoModeCameraManager::RacePhotoModeCameraManager(int a) : Base(), fF80(a), fF84(0) {}
