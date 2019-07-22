// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015-2016 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cstdarg>
#include <errno.h>
#include <fcntl.h>
#include <posix/fd.hpp>

int FD::fcntl(int cmd, va_list list)
{
	// PRINT("fcntl(%d)\n", cmd);
	switch (cmd) {
	case F_GETFD:
		// return descriptor flags
		return dflags;
	case F_SETFD:
		// set desc flags from va_list
		dflags = va_arg(list, int);
		return 0;
	case F_GETFL:
		// return file access flags
		return fflags;
	case F_SETFL:
		// set file access flags
		fflags = va_arg(list, int);
		return 0;
	case F_DUPFD:
	case F_DUPFD_CLOEXEC:
	default:
		errno = EINVAL;
		return -1;
	}
}

int FD::ioctl(int /*req*/, void * /*arg*/)
{
	// PRINT("ioctl(%d, %p) = -1\n", req, arg);
	errno = ENOSYS;
	return -1;
}

int FD::getsockopt(int /*fd*/, int, void *__restrict__, socklen_t *__restrict__)
{
	// PRINT("getsockopt(%d) = -1\n", fd);
	errno = ENOTSOCK;
	return -1;
}
int FD::setsockopt(int /*fd*/, int, const void *, socklen_t)
{
	// PRINT("setsockopt(%d) = -1\n", fd);
	errno = ENOTSOCK;
	return -1;
}
