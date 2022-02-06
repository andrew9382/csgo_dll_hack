#include "pch.h"
#include "includes.h"

bool isBannyHopActive = false;
bool isNoFlashActive = false;
bool isRadarHackActive = false;
bool isAntiRecoilActive = false;
bool isSnapLineActive = false;
bool isRecoilCrosshairActive = false;
bool isESP2dActive = false;
bool isAimBotActive = false;

void Status::AllFalse()
{
    isBannyHopActive = false;
    isNoFlashActive = false;
    isRadarHackActive = false;
    isAntiRecoilActive = false;
    isSnapLineActive = false;
    isRecoilCrosshairActive = false;
    isESP2dActive = false;
    isAimBotActive = false;
}

void Status::PrintState()
{
    if (isBannyHopActive)
        cout << "{num 1} BannyHop [ON]" << endl;
    else
        cout << "{num 1} BannyHop [OFF]" << endl;
    if (isNoFlashActive)
        cout << "{num 2} NoFlash [ON]" << endl;
    else
        cout << "{num 2} NoFlash [OFF]" << endl;
    if (isRadarHackActive)
        cout << "{num 3} RadarHack [ON]" << endl;
    else
        cout << "{num 3} RadarHack [OFF]" << endl;
    if (isAntiRecoilActive)
        cout << "{num 4} AntiRecoil [ON]" << endl;
    else
        cout << "{num 4} AntiRecoil [OFF]" << endl;
    if (isSnapLineActive)
        cout << "{num 5} SnapLine [ON]" << endl;
    else
        cout << "{num 5} SnapLine [OFF]" << endl;
    if (isRecoilCrosshairActive)
        cout << "{num 6} RecoilCrosshair [ON]" << endl;
    else
        cout << "{num 6} RecoilCrosshair [OFF]" << endl;
    if (isESP2dActive)
        cout << "{num 7} 2dESPbox [ON]" << endl;
    else
        cout << "{num 7} 2dESPbox [OFF]" << endl;
    if (isAimBotActive)
        cout << "{num 8} AimBot [ON]" << endl;
    else
        cout << "{num 8} AimBot [OFF]" << endl;
}