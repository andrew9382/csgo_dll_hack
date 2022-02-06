#pragma once

namespace Drawing
{
	void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color);
	void DrawLine(float x1, float y1, float x2, float y2, float thickness, D3DCOLOR color);
	void DrawLine(Vector2 src, Vector2 dst, float thickness, D3DCOLOR color);
	void DrawESPbox2d(Vector2 top, Vector2 bottom, float thickness, D3DCOLOR color);
	void DrawRecoilCrosshair();
}