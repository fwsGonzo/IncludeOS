
#include <fs/vfs.hpp>
#include <os>
#include <service>
#include <sys/stat.h>

int ftw_tests();
int stat_tests();

int main()
{
	INFO("POSIX stat", "Running tests for POSIX stat");

	fs::print_tree();

	stat_tests();
	ftw_tests();

	INFO("POSIX STAT", "All done!");
}
