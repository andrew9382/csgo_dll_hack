#include "pch.h"
#include "includes.h"

void NoFlash()
{
	Beep(400, 300);
	while (isNoFlashActive)
	{
		if (*MyPlayer->flash_duration > 0)
			*MyPlayer->flash_duration = 0;
		Sleep(2);
	}
	Beep(300, 300);
}