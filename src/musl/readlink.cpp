#include "common.hpp"
#include <sys/types.h>
#include <unistd.h>

static long sys_readlink(const char * /*path*/, char * /*buf*/,
			 size_t /*bufsiz*/)
{
	return -EIO;
}

extern "C" long syscall_SYS_readlink(const char *path, char *buf, size_t bufsiz)
{
	return strace(sys_readlink, "readlink", path, buf, bufsiz);
}
