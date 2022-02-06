#include "pch.h"
#include "includes.h"

#define CROSSHAIR_SIZE 4

Hack_t* Hack = nullptr;

Vector3* Hack_t::rotation_ang = (Vector3*)(Mem.FindDMAAddress(engine_dll_base, EngineDLL.rotation_ang));
float* Hack_t::viewMatrix = (float*)(client_dll_base + ClientDLL.view_matrix);
BYTE* Hack_t::jump = (BYTE*)(client_dll_base + ClientDLL.jump);
ID3DXLine* Hack_t::LineL = nullptr;
int Hack_t::crosshair_size = CROSSHAIR_SIZE;
Vector2 Hack_t::crosshair_2d_pos = { 0 };

bool Hack_t::WorldToScreen(Vector3& pos, Vector2& screen_pos)
{
	Vector4 clip_coords;
	clip_coords.x = pos.x * viewMatrix[0] + pos.y * viewMatrix[1] + pos.z * viewMatrix[2] + viewMatrix[3];
	clip_coords.y = pos.x * viewMatrix[4] + pos.y * viewMatrix[5] + pos.z * viewMatrix[6] + viewMatrix[7];
	clip_coords.w = pos.x * viewMatrix[8] + pos.y * viewMatrix[9] + pos.z * viewMatrix[10] + viewMatrix[11];

	if (clip_coords.w < 0.1f)
		return false;

	Vector2 NDC;
	NDC.x = clip_coords.x / clip_coords.w;
	NDC.y = clip_coords.y / clip_coords.w;

	screen_pos.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	screen_pos.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);

	return true;
}

Vector3 Hack_t::GetBonePos(Ent_t& ent, int bone)
{
	Vector3 bone_pos;

	bone_pos.x = *(float*)(*ent.bone_matrix + 0x30 * bone + 0x0C);
	bone_pos.y = *(float*)(*ent.bone_matrix + 0x30 * bone + 0x1C);
	bone_pos.z = *(float*)(*ent.bone_matrix + 0x30 * bone + 0x2C);

	return bone_pos;
}

bool Hack_t::IsInGame()
{
	return (*(DWORD*)(client_dll_base + ClientDLL.ent_list) != NULL);
}