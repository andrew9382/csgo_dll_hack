#include "pch.h"
#include "includes.h"

void RadarHack()
{
	Beep(400, 300);

	while (isRadarHackActive)
	{
		for (int i = 1; i < MAX_PLAYERS; i++)
		{
			DWORD entBase = GetValidEntBase(i);
			if (!entBase)
				continue;

			Ent_t ent(entBase);

			if ((*ent.radar == FALSE) && (*ent.team_num != *MyPlayer->team_num) && (*ent.health > 0))
			{
				*ent.radar = TRUE;
			}
		}

		Sleep(5);
	}

	Beep(300, 300);
}