#include <common.cxx>
#include <kernel/cpuid.hpp>
#include <os.hpp>

CASE("CPUID test")
{
	EXPECT(!CPUID::detect_features_str().empty());
}
