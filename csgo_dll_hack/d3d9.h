#pragma once

static void* d3d9Device[119]; // d3d9 vTable pointer
static BYTE endSceneStolenBytes[7]{ 0 };

typedef HRESULT(APIENTRY* tEndScene)(LPDIRECT3DDEVICE9 o_pDevice);

extern HWND window;
extern RECT rectSize;
extern tEndScene oEndScene;
extern LPDIRECT3DDEVICE9 pDevice;
extern int windowHeight;
extern int windowWidth;

bool GetD3D9Device(void** pTable, int size);
HWND GetProcessWindow();
BOOL CALLBACK enumWindows(HWND hWind, LPARAM lp);
HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 o_pDevice);