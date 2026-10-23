/* compiler: ee-gcc2.96-no-strict-aliasing */
#pragma interface
/* Partial layout of the onboard HUD, reconstructed from its constructor and
 * reverse-order cleanup. Original RTTI identifies each member's class. Storage
 * not needed by cleanup remains opaque; these are ABI views, not full classes.
 * Vtables belong to the original class translation units.
 * This is RaceOnboardPanel::~RaceOnboardPanel (0x005FA130); the source filename
 * follows the address database, which also attaches several inlined member aliases.
 * Member ownership supplies reverse-order destruction and the deleting-destructor
 * flag through the compiler ABI; no manual member cleanup is needed. */
class RaceDisplayObjectBase {
    char displayState[0x14];
public:
    virtual ~RaceDisplayObjectBase() __asm__("func_003AEBF8");
};
class RacePanel : public RaceDisplayObjectBase {
    char panelState[0x38];
public:
    ~RacePanel() {}
};
class RaceTexturePanel : public RaceDisplayObjectBase {
    char textureState[4];
public:
    ~RaceTexturePanel() __asm__("func_003A52C8");
};
class RaceMeterBase : public RaceDisplayObjectBase {
    int state18, state1C, state20;
public:
    ~RaceMeterBase() {}
};
// Intermediate meter classes add no storage used by this cleanup.
class RaceRoundMeterBase : public RaceMeterBase {
public:
    ~RaceRoundMeterBase() {}
};
class RaceRoundTachometerBase : public RaceRoundMeterBase {
public:
    ~RaceRoundTachometerBase() {}
};
#define HUD_MEMBER_VIEW(Name, Base, BaseSize, Size) \
    class Name : public Base { \
        char memberState[(Size) - (BaseSize)]; \
    public: ~Name() {} \
    }
HUD_MEMBER_VIEW(RaceOnboardSpeedmeter, RaceRoundMeterBase, 0x24, 0x5C);
HUD_MEMBER_VIEW(RaceOnboardTachometer, RaceRoundTachometerBase, 0x24, 0x89C);
HUD_MEMBER_VIEW(RaceBoostmeter, RaceRoundMeterBase, 0x24, 0x5C);
HUD_MEMBER_VIEW(RaceOdometer, RaceDisplayObjectBase, 0x18, 0x28);
HUD_MEMBER_VIEW(RaceDigitalSpeedmeter, RaceDisplayObjectBase, 0x18, 0x38);
HUD_MEMBER_VIEW(RaceShiftPositionDisplay, RaceDisplayObjectBase, 0x18, 0x58);
HUD_MEMBER_VIEW(RaceSuggestedGearDisplay, RaceDisplayObjectBase, 0x18, 0x58);
HUD_MEMBER_VIEW(RaceShiftTimingLampDisplay, RaceDisplayObjectBase, 0x18, 0x3C);
HUD_MEMBER_VIEW(RaceTireWearDisplay, RaceDisplayObjectBase, 0x18, 0x30);
HUD_MEMBER_VIEW(RaceIndicator, RaceDisplayObjectBase, 0x18, 0x44);
#undef HUD_MEMBER_VIEW
class RaceSideGravityMeter : public RaceDisplayObjectBase {
    char sideGravityState[0xC];
public:
    ~RaceSideGravityMeter() {}
};
class RaceOnboardPanel : public RacePanel {
public:
    RaceTexturePanel texturePanel;                // 0x050
    RaceOnboardSpeedmeter speedmeter;              // 0x06C
    RaceOnboardTachometer tachometer;              // 0x0C8
    RaceBoostmeter boostmeter;                    // 0x964
    RaceOdometer odometer;                        // 0x9C0
    RaceDigitalSpeedmeter digitalSpeedmeter;       // 0x9E8
    RaceShiftPositionDisplay shiftPosition;        // 0xA20
    RaceSuggestedGearDisplay suggestedGear;        // 0xA78
    RaceShiftTimingLampDisplay shiftTiming;        // 0xAD0
    RaceTireWearDisplay tireWear;                  // 0xB0C
    RaceIndicator indicatorB3C;                   // 0xB3C: roles still unknown
    RaceIndicator indicatorB80;                   // 0xB80
    RaceIndicator indicatorBC4;                   // 0xBC4
    RaceTexturePanel secondaryTexturePanel;        // 0xC08
    RaceSideGravityMeter sideGravity;              // 0xC24
    ~RaceOnboardPanel() __asm__("func_005FA130");
};
RaceOnboardPanel::~RaceOnboardPanel() {}
