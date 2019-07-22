#include <arch.hpp>
#include <common.cxx>

CASE("Testing arch.hpp")
{
	// TODO: some way to verify these?
	__arch_hw_barrier(); // __builtin_sync_synchronize() equivalent
	__sw_barrier();
}
