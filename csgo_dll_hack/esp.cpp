#include "pch.h"
#include "includes.h"

void ESP::SnapLine(Ent_t& ent, Vector2& ent_pos)
{
	if (*ent.team_num != *MyPlayer->team_num)
		Drawing::DrawLine(ent_pos.x, ent_pos.y, windowWidth / 2, windowHeight, 2.0f, D3DCOLOR_ARGB(255, 255, 0, 0));
	else
		Drawing::DrawLine(ent_pos.x, ent_pos.y, windowWidth / 2, windowHeight, 2.0f, D3DCOLOR_ARGB(255, 0, 255, 0));
}

void ESP::ESP2dBox(Ent_t& ent, Vector2& ent_head_pos, Vector2& ent_pos)
{
	if (*ent.team_num != *MyPlayer->team_num)
		Drawing::DrawESPbox2d(ent_head_pos, ent_pos, 2, D3DCOLOR_ARGB(255, 255, 0, 0));
	else
		Drawing::DrawESPbox2d(ent_head_pos, ent_pos, 2, D3DCOLOR_ARGB(255, 0, 255, 0));

	int height = abs(ent_head_pos.y - ent_pos.y);
	int deltaX = ent_pos.x - ent_head_pos.x;

	float health_perc = *ent.health / 100.0f;
	float armor_perc = *ent.armor / 100.0f;

	Vector2 bot_health, top_health, bot_armor, top_armor;
	int health_height = height * health_perc;
	int armor_height = height * armor_perc;

	bot_health.y = bot_armor.y = ent_pos.y;

	bot_health.x = ent_pos.x - (height / 4) - 2;
	bot_armor.x = ent_pos.x + (height / 4) + 2;

	top_health.y = ent_head_pos.y + height - health_height;
	top_armor.y = ent_head_pos.y + height - armor_height;

	top_health.x = ent_pos.x - (height / 4) - 2 - (deltaX * health_perc);
	top_armor.x = ent_pos.x + (height / 4) + 2 - (deltaX * armor_perc);

	Drawing::DrawLine(bot_health, top_health, 3.2, D3DCOLOR_ARGB(255, 46, 139, 87));
	Drawing::DrawLine(bot_armor, top_armor, 3.2, D3DCOLOR_ARGB(255, 30, 144, 255));
}

void ESP::ESP3dBox(Ent_t& ent, Vector2& screen_ent_coords)
{
}