#include "cli.hpp"

using namespace cli;

App::App(int argc, char* argv[])
{
	args_ = std::vector<std::string_view>(argv, argv + argc);
}

BoolOption&
App::add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, BoolValue value_default)
{
	bool_options_.push_back(
		(BoolOption){
			.flag_names_true = flag_names_true,
			.flag_names_false = flag_names_false,
			.value_default = value_default,
		}
	);

	return bool_options_.back();
}

StringOption&
App::add_string_option(std::vector<const char*> flag_names, StringValue value_default)
{
	string_options_.push_back(
		(StringOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return string_options_.back();
}

FloatOption&
App::add_float_option(std::vector<const char*> flag_names, FloatValue value_default)
{
	float_options_.push_back(
		(FloatOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return float_options_.back();
}

IntOption&
App::add_int_option(std::vector<const char*> flag_names, IntValue value_default)
{
	int_options_.push_back(
		(IntOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return int_options_.back();
}

