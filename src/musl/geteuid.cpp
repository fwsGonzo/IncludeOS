#include "common.hpp"
#include <sys/types.h>
#include <unistd.h>

static long sys_geteuid()
{
	return 0;
}

extern "C" long syscall_SYS_geteuid()
{
	return strace(sys_geteuid, "geteuid");
}
