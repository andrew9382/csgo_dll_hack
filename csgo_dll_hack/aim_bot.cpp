#include "pch.h"
#include "includes.h"

void AimBot()
{
	Beep(400, 300);
	std::vector<Target_t> target_vec;
	while (isAimBotActive)
	{
		if (GetAsyncKeyState(VK_RBUTTON))
		{
			for (int i = 1; i < 31; ++i)
			{
				DWORD ent_base;
				if (!(ent_base = GetValidEntBase(i)))
					continue;

				Ent_t ent(ent_base);
				if ( (*ent.health <= 1) || (*ent.team_num == 1) || (*ent.team_num == *MyPlayer->team_num) )
					continue;

				Vector3 ent_head = Hack->GetBonePos(ent, 8);
				Vector3 my_head_pos = *MyPlayer->xyz + *MyPlayer->view_offset;

				Target_t target(&my_head_pos, &ent_head);

				CalcAngles(&my_head_pos, &ent_head, &target.angles);

				target_vec.push_back(target);
			}
			
			if (!target_vec.empty())
			{
				std::sort(target_vec.begin(), target_vec.end(),
				[](Target_t& left, Target_t& right) -> bool
				{
					return left.dist_3d < right.dist_3d;
				});

				Mem.Copy(&target_vec[0].angles, Hack->rotation_ang, 12);

				target_vec.clear();
			}
		}
	}
	Beep(300, 300);
}

void CalcAngles(Vector3* src, Vector3* dst, Vector3* angles)
{
	Vector3 delta = *dst - *src;
	float hyp = sqrtf( powf(delta.x, 2) + powf(delta.y, 2) + powf(delta.z, 2) );

	float pitch = -asinf(delta.z / hyp) * (180 / PI);
	float yaw = atan2f(delta.y, delta.x) * (180 / PI);
	float roll = 0;

	if (pitch >= -89 && pitch <= 89 && yaw >= -180 && yaw <= 180)
	{
		angles->x = pitch;
		angles->y = yaw;
		angles->z = roll;
	}
}

// for compiler
Target_t& Target_t::operator=(Target_t tar)
{
	this->angles = tar.angles;
	this->dist_3d = tar.dist_3d;
	return *this;
}

Target_t::Target_t(Vector3* src, Vector3* dst)
{
	dist_3d = Calc3DDistance(src, dst);
}

float Target_t::Calc3DDistance(Vector3* src, Vector3* dst)
{
	Vector3 delta = *dst - *src;
	return sqrtf( powf(delta.x, 2) + powf(delta.y, 2) + powf(delta.z, 2) );
}