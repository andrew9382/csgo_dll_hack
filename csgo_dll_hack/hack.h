#pragma once

class Hack_t
{
public:
	static ID3DXLine* LineL;
	static float* viewMatrix;
	static Vector3* rotation_ang;
	static BYTE* jump;
	static int crosshair_size;
	static Vector2 crosshair_2d_pos;

	bool WorldToScreen(Vector3& pos, Vector2& screen_pos);
	Vector3 GetBonePos(Ent_t& ent, int bone);
	bool IsInGame();
} extern* Hack;