#include "common.hpp"
#include <sys/types.h>
#include <unistd.h>

static long sys_ftruncate(int /*fd*/, off_t /*length*/)
{
	return -EROFS;
}

extern "C" long syscall_SYS_ftruncate(int fd, off_t length)
{
	return strace(sys_ftruncate, "ftruncate", fd, length);
}
