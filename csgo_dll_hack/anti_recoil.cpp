#include "pch.h"
#include "includes.h"

void AntiRecoil()
{
	Beep(400, 300);
	
	Vector3 oPunch;
	while (isAntiRecoilActive)
	{
		Vector3 punchAngle = *MyPlayer->aim_punch_angle * 2;
		if (*MyPlayer->i_shots_fired > 1)
		{
			Vector3 newAngle = (*Hack->rotation_ang + oPunch - punchAngle);
			newAngle.Normalize();
			Mem.Copy(&newAngle, Hack->rotation_ang, 12);
		}
		oPunch = punchAngle;
		Sleep(3);
	}
	Beep(300, 300);
}