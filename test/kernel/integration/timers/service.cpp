
#include <cassert>
#include <os>
#include <stdio.h>

void Service::start()
{
}
void Service::ready()
{
	INFO("Timers", "Testing APIC timers");
	extern void test_timers();
	test_timers();
}
