#pragma once

#include "includes.h"

struct ClientDLLOffsets
{
	const DWORD player_base = 0xDB458C;
	const DWORD ent_list = 0x4DCFA64;
	const DWORD jump = 0x526B5A0;
	const DWORD health = 0x100; // player_base
	const DWORD i_flags = 0x104; // player_base
	const DWORD id = 0x64; // player_base
	const DWORD radar = 0x93D; // player_base
	const DWORD coords = 0x138; // player_base
	const DWORD rotation_ang = 0x351C; // player_base
	const DWORD flash_duration = 0x10470; // player_base
	const DWORD i_team = 0xF4; // player_base
	const DWORD velocity = 0x114; // player_base
	const DWORD player_size = 0x10;
	const DWORD aim_punch_angle = 0x303c; // player_base
	const DWORD i_shots_fired = 0x103e0; // player_base
	const DWORD view_matrix = 0x4DC1364;
	const DWORD bone_matrix = 0x2924; // player_base
	const DWORD armor = 0x117CC; // player_base
	const DWORD view_offset = 0x108; // player_base

} static ClientDLL;

struct EngineDLLOffsets
{
	std::vector<DWORD> rotation_ang = { 0x589FC4, 0x4D90 };
} static EngineDLL;