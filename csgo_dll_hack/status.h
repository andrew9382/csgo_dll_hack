#pragma once

extern bool isBannyHopActive;
extern bool isNoFlashActive;
extern bool isRadarHackActive;
extern bool isAntiRecoilActive;
extern bool isSnapLineActive;
extern bool isRecoilCrosshairActive;
extern bool isESP2dActive;
extern bool isAimBotActive;

namespace Status
{
	void AllFalse();
	void PrintState();
}