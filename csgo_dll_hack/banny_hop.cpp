#include "pch.h"
#include "includes.h"

void BannyHop()
{
	Beep(400, 300);
	while (isBannyHopActive)
	{
		if (GetAsyncKeyState(VK_SPACE) && (*MyPlayer->i_flags == STAND))
			if (CanJump(MyPlayer))
				*Hack->jump = JUMP;
		else
			*Hack->jump = MINUS_JUMP;
		Sleep(2);
	}
	*Hack->jump = MINUS_JUMP;
	Beep(300, 300);
}

bool CanJump(Ent_t* MyPlayer)
{
	Vector3* Velocity = MyPlayer->velocity;
	if (Velocity->x + Velocity->y + Velocity->z != 0)
		return TRUE;
	return FALSE;
}