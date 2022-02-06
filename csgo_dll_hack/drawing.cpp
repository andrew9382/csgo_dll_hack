#include "pch.h"
#include "includes.h"

void Drawing::DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void Drawing::DrawLine(float x1, float y1, float x2, float y2, float thickness, D3DCOLOR color)
{
	if (Hack->LineL == nullptr)
		D3DXCreateLine(pDevice, &Hack->LineL);

	D3DXVECTOR2 Line[2];
	Line[0] = D3DXVECTOR2(x1, y1);
	Line[1] = D3DXVECTOR2(x2, y2);
	Hack->LineL->SetWidth(thickness);
	Hack->LineL->Draw(Line, 2, color);
}

void Drawing::DrawLine(Vector2 src, Vector2 dst, float thickness, D3DCOLOR color)
{
	DrawLine(src.x, src.y, dst.x, dst.y, thickness, color);
}

void Drawing::DrawESPbox2d(Vector2 top, Vector2 bottom, float thickness, D3DCOLOR color)
{
	int height = abs(top.y - bottom.y);
	Vector2 tl, tr, bl, br;
	
	tl.x = top.x - height / 4;
	tr.x = top.x + height / 4;
	tl.y = tr.y = top.y;

	bl.x = bottom.x - height / 4;
	br.x = bottom.x + height / 4;
	bl.y = br.y = bottom.y;

	DrawLine(tl, tr, thickness, color);
	DrawLine(bl, br, thickness, color);
	DrawLine(tl, bl, thickness, color);
	DrawLine(tr, br, thickness, color);
}

void Drawing::DrawRecoilCrosshair()
{
	Vector2 l, r, t, b;
	Vector3* p_ang = MyPlayer->aim_punch_angle;

	Hack->crosshair_2d_pos.x = windowWidth / 2 - (windowWidth / 90 * p_ang->y);
	Hack->crosshair_2d_pos.y = windowHeight / 2 + (windowHeight / 90 * p_ang->x);

	l = r = t = b = Hack->crosshair_2d_pos;
	l.x -= Hack->crosshair_size;
	r.x += Hack->crosshair_size;
	t.y -= Hack->crosshair_size;
	b.y += Hack->crosshair_size;

	DrawLine(l, r, 2, D3DCOLOR_ARGB(255, 255, 255, 255));
	DrawLine(t, b, 2, D3DCOLOR_ARGB(255, 255, 255, 255));
}