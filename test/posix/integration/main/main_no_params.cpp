#include <cstdio>
#include <os>

int main()
{
	printf("Hello main - %s\n", os::cmdline_args());
	assert(os::cmdline_args() ==
	       std::string("test_main booted with vmrunner"));
	return 0;
}
