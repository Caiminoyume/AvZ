#include <avz.h>
#define flytime 373
#define delay 110
#define fired 295
#define jingwu 359
#define ice3 181
void PD(int wave)
{
    AConnect(ATime(wave, jingwu - flytime), [] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(wave, jingwu + delay - flytime), [] {
        aCobManager.Fire({{1, 7.6}, {5, 7.6}});
    });
}
void ICE3(int wave)
{
    AConnect(ATime(wave, fired - flytime), [] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(wave, fired - flytime + ice3), [] {
        aIceFiller.Coffee();
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
}
void PSD(int wave)
{
    AConnect(ATime(wave, fired - flytime), [] {
        aCobManager.Fire({{2, 9}, {5, 9}, {2, 9}, {5, 9}});
    });
    AConnect(ATime(wave, fired + delay - flytime), [] {
        aCobManager.Fire({{1, 9}, {5, 9}});
    });
}
void shouwei(int wave)
{
    AConnect(ATime(wave, 690), [] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
}
void shanhu(int wave)
{
    AConnect(ATime(wave, 230 - flytime), [] {
        aCobManager.Fire(4, 6.625);
    });
}
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI_OR_FIGHT_UI);
    ASetGameSpeed(5);
    ASetZombies({AZOMBIE, AFLAG_ZOMBIE, ACONEHEAD_ZOMBIE, APOLE_VAULTING_ZOMBIE, ABUCKETHEAD_ZOMBIE, ANEWSPAPER_ZOMBIE, ASCREEN_DOOR_ZOMBIE, AFOOTBALL_ZOMBIE, ADANCING_ZOMBIE, ABACKUP_DANCER, ADUCKY_TUBE_ZOMBIE, ASNORKEL_ZOMBIE, AZOMBONI, AZOMBIE_BOBSLED_TEAM, ADOLPHIN_RIDER_ZOMBIE, AJACK_IN_THE_BOX_ZOMBIE, ABALLOON_ZOMBIE, ADIGGER_ZOMBIE, APOGO_ZOMBIE, AZOMBIE_YETI, ABUNGEE_ZOMBIE, ALADDER_ZOMBIE, ACATAPULT_ZOMBIE, AGARGANTUAR, AIMP, AGIGA_GARGANTUAR});
    ASelectCards({
        AICE_SHROOM,
        AM_ICE_SHROOM,
        ACOFFEE_BEAN,
        ADOOM_SHROOM,
        ALILY_PAD,
        ASQUASH,
        ACHERRY_BOMB,
        ABLOVER,
        APUMPKIN,
        APUFF_SHROOM,
    });
    AConnect(ATime(1, -599), [] {
        aCobManager.AutoGetList();
        aIceFiller.Start({{4, 9}});
        aPlantFixer.Start(ANGT_30, {{3, 9}, {4, 9}}, 300);
        // aItemCollector.Start();
    });
    for (auto wave : {1, 4, 7, 11, 14, 17}) {
        PD(wave);
    }
    for (auto wave : {2, 5, 8, 12, 15, 18}) {
        ICE3(wave);
    }
    for (auto wave : {3, 6, 9, 10, 13, 16, 19, 20}) {
        PSD(wave);
    }
    for (auto wave : {9, 19, 20}) {
        shouwei(wave);
    }
    for (auto wave : {20}) {
        shanhu(wave);
    }
}