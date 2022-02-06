#include "pch.h"
#include "includes.h"

Ent_t* MyPlayer = nullptr;

Ent_t::Ent_t(DWORD player_base)
{
	this->player_base = player_base;
	health = (DWORD*)(player_base + ClientDLL.health);
	team_num = (DWORD*)(player_base + ClientDLL.i_team);
	id = (DWORD*)(player_base + ClientDLL.id);
	radar = (BOOL*)(player_base + ClientDLL.radar);
	rotation_ang = (Vector3*)(player_base + ClientDLL.rotation_ang);
	xyz = (Vector3*)(player_base + ClientDLL.coords);
	velocity = (Vector3*)(player_base + ClientDLL.velocity);
	bone_matrix = (DWORD*)(player_base + ClientDLL.bone_matrix);
	i_flags = (DWORD*)(player_base + ClientDLL.i_flags);
	i_shots_fired = (DWORD*)(player_base + ClientDLL.i_shots_fired);
	aim_punch_angle = (Vector3*)(player_base + ClientDLL.aim_punch_angle);
	flash_duration = (DWORD*)(player_base + ClientDLL.flash_duration);
	armor = (DWORD*)(player_base + ClientDLL.armor);
	view_offset = (Vector3*)(player_base + ClientDLL.view_offset);
}

DWORD GetValidEntBase(int id_in_list)
{
	DWORD player_base = *(DWORD*)(client_dll_base + ClientDLL.ent_list + id_in_list * ClientDLL.player_size);

	if (!player_base)
		return NULL;

	return player_base;
}