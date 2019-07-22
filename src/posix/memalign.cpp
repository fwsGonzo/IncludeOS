// -*-C++-*-

#include <cstdlib>
#include <kernel/memory.hpp>
#include <malloc.h>
#include <util/bitops.hpp>

extern "C" int posix_memalign(void **memptr, size_t alignment, size_t size)
{
	if (!util::bits::is_pow2(alignment) or alignment < sizeof(void *))
		return EINVAL;

	auto *mem = memalign(alignment, size);
	if (mem == nullptr) {
		return errno;
	}
	*memptr = mem;
	return 0;
}
