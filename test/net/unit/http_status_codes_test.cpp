
#include <common.cxx>
#include <net/http/status_code_constants.hpp>
#include <net/http/status_codes.hpp>

CASE("code_description() returns textual description of status code")
{
	auto desc = http::code_description(http::Not_Found);
	EXPECT(desc == "Not Found");
}
