#include "pch.h"
#include "includes.h"

#define THREADS_COUNT 5

DWORD client_dll_base = Mem.GetModuleBase<DWORD>("client.dll");
DWORD engine_dll_base = Mem.GetModuleBase<DWORD>("engine.dll");

DWORD WINAPI HackThread(LPVOID hModule)
{
    HANDLE ThreadsHandlers[THREADS_COUNT] = { 0 };

    // hook end scene
    if (GetD3D9Device(d3d9Device, sizeof(d3d9Device)))
    {
        Mem.Copy(d3d9Device[42], endSceneStolenBytes, 7);
        oEndScene = (tEndScene)Mem.TrampHook32((BYTE*)d3d9Device[42], (BYTE*)hkEndScene, 7);
    }

    // allocating console
    AllocConsole();
    FILE* outConsole;
    freopen_s(&outConsole, "CONOUT$", "w", stdout);

    // init global vars
    Hack = new Hack_t();
    
    // hack loop
    while (!GetAsyncKeyState(VK_END))
    {
        if (Hack->IsInGame())
        {
            if (MyPlayer != nullptr)
            {
                if (MyPlayer->player_base != *(DWORD*)(client_dll_base + ClientDLL.player_base))
                {
                    delete MyPlayer;
                    MyPlayer = new Ent_t(*(DWORD*)(client_dll_base + ClientDLL.player_base));
                }
            }
            else { MyPlayer = new Ent_t(*(DWORD*)(client_dll_base + ClientDLL.player_base)); }
           
            if (GetAsyncKeyState(VK_NUMPAD1))
            {
                if (!isBannyHopActive)
                {
                    isBannyHopActive = true;
                    ThreadsHandlers[0] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BannyHop, 0, 0, 0);
                }
                else
                {
                    isBannyHopActive = false;
                    CloseHandle(ThreadsHandlers[0]);
                    ThreadsHandlers[0] = NULL;
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD2))
            {
                if (!isNoFlashActive)
                {
                    isNoFlashActive = true;
                    ThreadsHandlers[1] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)NoFlash, 0, 0, 0);
                }
                else
                {
                    isNoFlashActive = false;
                    CloseHandle(ThreadsHandlers[1]);
                    ThreadsHandlers[1] = NULL;
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD3))
            {
                if (!isRadarHackActive)
                {
                    isRadarHackActive = true;
                    ThreadsHandlers[2] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)RadarHack, 0, 0, 0);
                }
                else
                {
                    isRadarHackActive = false;
                    CloseHandle(ThreadsHandlers[2]);
                    ThreadsHandlers[2] = NULL;
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD4))
            {
                if (!isAntiRecoilActive)
                {
                    isAntiRecoilActive = true;
                    ThreadsHandlers[3] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)AntiRecoil, 0, 0, 0);
                }
                else
                {
                    isAntiRecoilActive = false;
                    CloseHandle(ThreadsHandlers[3]);
                    ThreadsHandlers[3] = NULL;
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD5))
            {
                if (!isSnapLineActive)
                {
                    isSnapLineActive = true;
                    Beep(400, 300);
                }
                else
                {
                    isSnapLineActive = false;
                    Beep(300, 300);
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD6))
            {
                if (!isRecoilCrosshairActive)
                {
                    isRecoilCrosshairActive = true;
                    Beep(400, 300);
                }
                else
                {
                    isRecoilCrosshairActive = false;
                    Beep(300, 300);
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD7))
            {
                if (!isESP2dActive)
                {
                    isESP2dActive = true;
                    Beep(400, 300);
                }
                else
                {
                    isESP2dActive = false;
                    Beep(300, 300);
                }
                Sleep(135);
            }
            if (GetAsyncKeyState(VK_NUMPAD8))
            {
                if (!isAimBotActive)
                {
                    isAimBotActive = true;
                    ThreadsHandlers[4] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)AimBot, 0, 0, 0);
                }
                else
                {
                    isAimBotActive = false;
                    CloseHandle(ThreadsHandlers[4]);
                    ThreadsHandlers[4] = NULL;
                }
                Sleep(135);
            }
        }
        else
        {
            Status::AllFalse();
        }

        Status::PrintState();
        system("cls");
        Sleep(5);
    }
    // unhook and cleanup
    Status::AllFalse();
    for (int i = 0; i < THREADS_COUNT; i++)
    {
        if (ThreadsHandlers[i])
            WaitForSingleObject(ThreadsHandlers[i], INFINITE);
    }
    if (oEndScene != nullptr)
    {
        Mem.Patch(endSceneStolenBytes, (BYTE*)d3d9Device[42], 7);
        VirtualFree(oEndScene, NULL, MEM_RELEASE);
    }

    delete MyPlayer;
    delete Hack; 

    fclose(outConsole);
    FreeConsole();
    FreeLibraryAndExitThread((HMODULE)hModule, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&HackThread, hModule, 0, 0));

    return TRUE;
}