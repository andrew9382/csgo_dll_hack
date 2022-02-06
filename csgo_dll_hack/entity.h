#pragma once

class Ent_t
{
public:
	DWORD player_base;
	DWORD* health;
	DWORD* armor;
	BOOL* radar;
	DWORD* team_num;
	Vector3* xyz;
	Vector3* velocity;
	Vector3* aim_punch_angle;
	Vector3* rotation_ang;
	Vector3* view_offset;
	DWORD* id;
	DWORD* bone_matrix;
	DWORD* i_flags;
	DWORD* i_shots_fired;
	DWORD* flash_duration;
	
	Ent_t(DWORD player_base);
} extern* MyPlayer;

DWORD GetValidEntBase(int id_in_list);