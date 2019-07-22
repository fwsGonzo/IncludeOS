
#include <cmath>
#include <kernel/context.hpp>
#include <os>

extern "C" uintptr_t get_cpu_esp();

constexpr auto STACK_SIZE = 0x20000;
static const double float1 = 0.987;
static const double float2 = 0.654;
static const double float3 = 0.321;

static double much_float(double d)
{
	return sqrt(2) * d;
}

void Service::start(const std::string &)
{
	INFO("Context", "Testing stack switches");

	auto esp0 = get_cpu_esp();

	auto res1 = much_float(float1);
	auto res2 = much_float(float2);
	auto res3 = much_float(float3);

	Context::create(STACK_SIZE, [res1, res2]() {
		const auto esp1 = get_cpu_esp();
		printf("Context 1, stack at %p\n", (void *)esp1);
		Expects(esp1 >= OS::heap_begin() and esp1 <= OS::heap_end());

		const volatile double my_float = much_float(float1);

		Context::create(STACK_SIZE, [esp1, res2]() {
			const auto esp2 = get_cpu_esp();

			Expects(esp2 >= OS::heap_begin() and
				esp2 <= OS::heap_end());
			Expects(std::abs(long(esp2 - esp1)) >= STACK_SIZE);

			auto my_float = much_float(float2);
			Expects(my_float == res2);

			printf("Context 2, stack at %p\n", (void *)esp2);
		});

		Expects(my_float == res1);
	});

	// Stack should be back to where it was.
	auto esp3 = get_cpu_esp();
	Expects(esp0 == esp3);

	auto my_float = much_float(float3);
	Expects(my_float == res3);

	INFO("Context", "SUCCESS");
}
