#include "include.h"
#include "Hooks.h"

void console()
{
    AllocConsole();
    FILE* f;
    freopen_s(&f ,"CONOUT$", "w", stdout);
    printf("Internal");
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        Hooks::initHook(hModule);
        console();
    }
    return TRUE;
}

