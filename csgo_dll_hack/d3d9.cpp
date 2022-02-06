#include "pch.h"
#include "includes.h"

HWND window;
int windowHeight;
int windowWidth;

tEndScene oEndScene = nullptr;
LPDIRECT3DDEVICE9 pDevice = nullptr;

RECT rectSize;

BOOL isFullScreen(HWND window)
{
	MONITORINFO m_info;
	m_info.cbSize = sizeof(MONITORINFO);

	if (!GetMonitorInfoA(MonitorFromWindow(window, MONITOR_DEFAULTTOPRIMARY), &m_info))
		return FALSE;

	RECT window_rect;

	if (!GetWindowRect(window, &window_rect))
		return FALSE;

	return (m_info.rcMonitor.left == window_rect.left &&
		    m_info.rcMonitor.right == window_rect.right &&
		    m_info.rcMonitor.bottom == window_rect.bottom &&
		    m_info.rcMonitor.top == window_rect.top);
}

BOOL CALLBACK enumWindows(HWND hWind, LPARAM lp)
{
	DWORD procId;
	GetWindowThreadProcessId(hWind, &procId);

	if (GetCurrentProcessId() != procId)
		return TRUE;

	window = hWind;

	return FALSE;
}

HWND GetProcessWindow()
{
	window = NULL;
	EnumWindows(enumWindows, NULL);
	return window;
}

bool GetD3D9Device(void** pTable, int size)
{
	if (pTable == nullptr) return FALSE;

	IDirect3D9* pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (pD3D9 == nullptr) return FALSE;

	IDirect3DDevice9* pDummyDevice = nullptr;
	
	D3DPRESENT_PARAMETERS d3dpp = { 0 };
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = GetProcessWindow();
	if (!isFullScreen(window))
		d3dpp.Windowed = true;
	else
		d3dpp.Windowed = false;

	HRESULT hr = pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pDummyDevice);
	if (hr != S_OK)
	{
		printf("Error: %s error description: %s\n", DXGetErrorStringA(hr), DXGetErrorDescriptionA(hr));
		pD3D9->Release();
		return FALSE;
	}
	Mem.Copy(*(void***)(pDummyDevice), pTable, size);
	
	pDummyDevice->Release();
	pD3D9->Release();
	return TRUE;
}

HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 o_pDevice)
{
	if (pDevice == nullptr)
		pDevice = o_pDevice;

	GetWindowRect(window, &rectSize);

	if (!isFullScreen(window))
	{ 
		windowHeight = rectSize.bottom - rectSize.top - 29;
		windowWidth = rectSize.right - rectSize.left - 5;
	}
	else
	{
		windowHeight = rectSize.bottom - rectSize.top;
		windowWidth = rectSize.right - rectSize.left;
	}

	if (Hack->IsInGame())
	{
		if (isSnapLineActive || isESP2dActive)
		{
			for (int i = 1; i < 32; i++)
			{
				DWORD ent_base;
				if (!(ent_base = GetValidEntBase(i)))
					continue;

				Ent_t ent(ent_base);
				
				Vector2 ent_pos_2d;
				if (Hack->WorldToScreen(*ent.xyz, ent_pos_2d))
				{
					if (isSnapLineActive)
						ESP::SnapLine(ent, ent_pos_2d);

					if (isESP2dActive)
					{
						Vector3 ent_head_3d = Hack->GetBonePos(ent, 8);
						Vector2 ent_head_2d;

						ent_head_3d.z += 8.0f;

						if (Hack->WorldToScreen(ent_head_3d, ent_head_2d))
							ESP::ESP2dBox(ent, ent_head_2d, ent_pos_2d);
					}
				}
			}
		}
		if (isRecoilCrosshairActive)
			Drawing::DrawRecoilCrosshair();
	}
	return oEndScene(o_pDevice);
}