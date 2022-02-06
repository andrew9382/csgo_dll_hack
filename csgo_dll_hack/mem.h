#pragma once

#include "includes.h"

class MemClass
{
public:

	template<typename dataT>
	dataT GetModuleBase(std::string module_name)
	{
		return (dataT)GetModuleHandleA(module_name.c_str());
	}

	void Copy(LPVOID src, LPVOID dst, DWORD bytes_to_copy);

	DWORD FindDMAAddress(DWORD module_base, std::vector<DWORD>& offsets);

	bool Detour32(BYTE* src, BYTE* dst, DWORD len);

	BYTE* TrampHook32(BYTE* src, BYTE* dst, DWORD len);

	void Patch(BYTE* src, BYTE* dst, DWORD len);

} static Mem;