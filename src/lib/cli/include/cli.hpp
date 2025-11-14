#ifndef CLI_APP_HPP
#define CLI_APP_HPP

#include <cstdint>
#include <iostream>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace cli {

using IntValue = int;
using FloatValue = double;
using StringValue = std::string;
using BoolValue = bool;

template <typename ValueType>
struct Option {
	std::vector<const char*> flag_names;
	bool                     set;
	ValueType                value;
	ValueType                value_default;
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
	App(int argc, char* argv[]);

	IntOption& add_int_option(std::vector<const char*> flag_names, IntValue value_default);
	FloatOption& add_float_option(std::vector<const char*> flag_names, FloatValue value_default);
	BoolOption& add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, BoolValue value_default);
	StringOption& add_string_option(std::vector<const char*> flag_names, StringValue value_default);
private:
	std::vector<std::string_view> args_;

	std::vector<BoolOption> bool_options_;
	std::vector<FloatOption> float_options_;
	std::vector<IntOption> int_options_;
	std::vector<StringOption> string_options_;
};

} // namespace cli

#endif // CLI_APP_HPP

