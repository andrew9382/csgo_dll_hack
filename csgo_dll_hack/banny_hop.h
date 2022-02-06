#pragma once

#include "includes.h"

#define JUMP 5
#define MINUS_JUMP 4
#define STAND 257
#define IN_AIR 256

void BannyHop();

bool CanJump(Ent_t* Player);