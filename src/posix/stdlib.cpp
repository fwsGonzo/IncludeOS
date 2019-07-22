
#include <errno.h>
#include <malloc.h>

extern "C" {
int posix_memalign(void **memptr, size_t alignment, size_t size)
{
	if (alignment < sizeof(void *))
		return EINVAL;

	auto ptr = memalign(alignment, size);

	if (!ptr)
		return errno;

	*memptr = ptr;
	return 0;
};
}
