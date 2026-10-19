typedef int s32;

struct RacePhotoModeCameraManagerLayout {
    char pad0[0xDD0];
    char camera_control[0x58];
};

extern "C" void CameraSys__CameraControl__init(void *arg0, void *arg1, s32 arg2);

extern "C" void RacePhotoModeCameraManager__virtual_57(RacePhotoModeCameraManagerLayout *arg0, void *arg1) {
    CameraSys__CameraControl__init(arg0->camera_control, arg1, 1);
}
