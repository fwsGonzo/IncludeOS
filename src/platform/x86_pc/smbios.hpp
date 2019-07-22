
#pragma once
#include <arch.hpp>
#include <cstdint>
#include <string>

namespace x86
{
struct SMBIOS {
	static void init();

	static inline const arch_system_info_t &system_info()
	{
		return sysinfo;
	}

    private:
	static void parse(const char *);
	static arch_system_info_t sysinfo;
};
} // namespace x86
