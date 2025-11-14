#include "cli.hpp"

using namespace cli;

BoolOption&
App::add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, BoolValue value_default)
{
	bool_options.push_back(
		(BoolOption){
			.flag_names_true = flag_names_true,
			.flag_names_false = flag_names_false,
			.value_default = value_default,
		}
	);

	return bool_options.back();
}

StringOption&
App::add_string_option(std::vector<const char*> flag_names, StringValue value_default)
{
	string_options.push_back(
		(StringOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return string_options.back();
}

FloatOption&
App::add_float_option(std::vector<const char*> flag_names, FloatValue value_default)
{
	float_options.push_back(
		(FloatOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return float_options.back();
}

IntOption&
App::add_int_option(std::vector<const char*> flag_names, IntValue value_default)
{
	int_options.push_back(
		(IntOption){
			.flag_names = flag_names,
			.value_default = value_default,
		}
	);

	return int_options.back();
}

std::expected<std::monostate, App::ParseError>
App::parse(std::span<char*> program_args, std::size_t start_index)
{
	for (std::size_t i = start_index; i < program_args.size(); i++) {
		char* curr = program_args[i];
		auto is_flag_equal = [&](auto flag) -> bool {
			return std::strcmp(curr, flag) == 0;
		};

		// boolean true options
		{
			auto it = std::find_if(bool_options.begin(), bool_options.end(), [&](auto& opt) {
				auto it = std::find_if(opt.flag_names_true.begin(), opt.flag_names_true.end(), is_flag_equal);
				return it != opt.flag_names_true.end();
			});
			if (it != bool_options.end()) {
				it->set = true;
				it->value = true;
				continue;
			}
		}

		// boolean false options
		{
			auto it = std::find_if(bool_options.begin(), bool_options.end(), [&](auto& opt) {
				auto it = std::find_if(opt.flag_names_false.begin(), opt.flag_names_false.end(), is_flag_equal);
				return it != opt.flag_names_false.end();
			});
			if (it != bool_options.end()) {
				it->set = true;
				it->value = false;
				continue;
			}
		}

		// string options
		{
			auto it = std::find_if(string_options.begin(), string_options.end(), [&](auto& opt) {
				auto it = std::find_if(opt.flag_names.begin(), opt.flag_names.end(), is_flag_equal);
				return it != opt.flag_names.end();
			});
			if (it != string_options.end()) {
				if (i + 1 >= program_args.size()) {
					return std::unexpected{App::ParseError::ArgumentMissing};
				}

				it->set = true;
				it->value = StringValue{program_args[i + 1]};
				i++;
				continue;
			}
		}

		// positional arg
		{
			pos_args.push_back(curr);
		}
	}

	return std::monostate{};
}
