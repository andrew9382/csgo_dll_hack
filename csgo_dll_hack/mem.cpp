#include "pch.h"
#include "includes.h"

void MemClass::Copy(LPVOID src, LPVOID dst, DWORD bytes_to_copy)
{
	for (DWORD i = 0; i < bytes_to_copy; i++)
	{
		*((BYTE*)dst + i) = *((BYTE*)src + i);
	}
}

DWORD MemClass::FindDMAAddress(DWORD module_base, std::vector<DWORD>& offsets)
{
	DWORD addr = module_base + offsets[0];

	for (DWORD i = 1; i < offsets.size(); i++)
	{
		addr = *(DWORD*)addr;
		addr += offsets[i];
	}

	return addr;
}

bool MemClass::Detour32(BYTE* src, BYTE* dst, DWORD len)
{
	if (len < 5) return FALSE;

	DWORD oldProtection;
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtection);

	memset(src, 0x90, len);

	DWORD dstRelAddress = (DWORD)(dst - src - 5);

	*src = (BYTE)0xE9;
	*(DWORD*)(src + 1) = dstRelAddress;

	DWORD temp;
	VirtualProtect(src, len, oldProtection, &temp);

	return TRUE;
}

BYTE* MemClass::TrampHook32(BYTE* src, BYTE* dst, DWORD len)
{
	if (len < 5) return FALSE;

	BYTE* gateway = (BYTE*)VirtualAlloc(NULL, (len + 5), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	Copy(src, gateway, len);
	
	DWORD srcRelAddress = (DWORD)(src - gateway - 5);
	
	*(gateway + len) = (BYTE)0xE9;
	*(DWORD*)(gateway + len + 1) = srcRelAddress;

	if (Detour32(src, dst, len))
		return gateway;
	else
		return nullptr;
}

void MemClass::Patch(BYTE* src, BYTE* dst, DWORD len)
{
	DWORD oldProtection;
	VirtualProtect(dst, len, PAGE_EXECUTE_READWRITE, &oldProtection);

	Copy(src, dst, len);

	DWORD temp;
	VirtualProtect(dst, len, oldProtection, &temp);
}