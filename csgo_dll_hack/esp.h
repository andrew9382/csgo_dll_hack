#pragma once

namespace ESP
{
	void SnapLine(Ent_t& ent, Vector2& screen_ent_coords);
	void ESP2dBox(Ent_t& ent, Vector2& ent_head_pos, Vector2& ent_pos);
	void ESP3dBox(Ent_t& ent, Vector2& screen_ent_coords);
}