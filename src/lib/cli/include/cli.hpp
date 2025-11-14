#ifndef CLI_APP_HPP
#define CLI_APP_HPP

#include <cstring>
#include <cstdint>
#include <expected>
#include <iostream>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace cli {

using IntValue = int;
using FloatValue = double;
using StringValue = std::string;
using BoolValue = bool;

template <typename T>
struct Option {
	std::vector<const char*> flag_names;
	bool                     set;
	T                        value;
	T                        value_default;
};

template <>
struct Option<BoolValue> {
	std::vector<const char*> flag_names_true;
	std::vector<const char*> flag_names_false;
	bool                     set;
	BoolValue                value;
	BoolValue                value_default;
};

using BoolOption = Option<BoolValue>;
using StringOption = Option<StringValue>;
using FloatOption = Option<FloatValue>;
using IntOption = Option<IntValue>;

class App {
public:
	enum class ParseError {
		ArgumentMissing,
	};

	App(std::string_view name_)
		: name{name_}
		{}

	IntOption&
	add_int_option(std::vector<const char*> flag_names, IntValue value_default);

	FloatOption&
	add_float_option(std::vector<const char*> flag_names, FloatValue value_default);

	BoolOption&
	add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, BoolValue value_default);

	StringOption&
	add_string_option(std::vector<const char*> flag_names, StringValue value_default);

	std::expected<std::monostate, ParseError>
	parse(std::span<char*> program_args, std::size_t start_index = 1);

	std::vector<std::string_view> get_pos_args() const noexcept
	{
		return this->pos_args;
	}
private:
	std::string name;

	std::vector<std::string_view> pos_args;
	std::vector<BoolOption> bool_options;
	std::vector<FloatOption> float_options;
	std::vector<IntOption> int_options;
	std::vector<StringOption> string_options;
};

} // namespace cli

#endif // CLI_APP_HPP

