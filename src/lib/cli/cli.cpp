#include "cli.hpp"

using namespace cli;

App::App(int argc, char* argv[])
{
	args_ = std::vector<std::string_view>(argv, argv + argc);
}

BoolOption&
App::add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, bool value_default)
{
	bool_options_.push_back(
		(BoolOption){
			.flag_names_true = flag_names_true,
			.flag_names_false = flag_names_false,
			.value_default = value_default
		}
	);

	return bool_options_.back();
}
