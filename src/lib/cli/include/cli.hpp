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

using IntValue = long long;
using FloatValue = long double;
using StringValue = std::string;
using BoolValue = bool;

template <typename T>
class Option {
public:
	Option(std::vector<const char*> flag_names_, T value_default_)
		: flag_names{std::move(flag_names_)},
		set{false},
		value{value_default_},
		value_default{value_default_}
		{}

	bool
	is_set() const noexcept
	{
		return this->set;
	}

	T
	get_value() const noexcept
	{
		return this->value;
	}

	void
	set_value(T value_) noexcept
	{
		this->value = value_;
		this->set = true;
	}

	std::vector<const char*> flag_names;
private:
	bool                     set;
	T                        value;
	T                        value_default;
};

template <>
class Option<BoolValue> {
public:
	Option(std::vector<const char*> flag_names_true_, std::vector<const char*> flag_names_false_, BoolValue value_default_)
		: flag_names_true{flag_names_true_},
		flag_names_false{flag_names_false_},
		set{false},
		value{value_default_},
		value_default{value_default_}
		{}

	bool
	is_set() const noexcept
	{
		return this->set;
	}

	BoolValue
	get_value() const noexcept
	{
		return this->value;
	}

	void
	set_value(BoolValue value_) noexcept
	{
		this->value = value_;
		this->set = true;
	}

	std::vector<const char*> flag_names_true;
	std::vector<const char*> flag_names_false;
private:
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
	template <typename T>
	struct ErrParseInvalidOptValue {
		char* flag;
		char* value;
	};

	struct ErrParseMissingValue {
		char* flag;
	};

	using NoErrParse = std::monostate;

	using ParseError = std::variant<NoErrParse, ErrParseInvalidOptValue<FloatValue>, ErrParseInvalidOptValue<IntValue>, ErrParseMissingValue>;

	App(std::string name_, std::string description_)
		: name{std::move(name_)},
		description{std::move(description_)}
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

	std::string_view
	get_name() const noexcept
	{
		return this->name;
	}

	std::vector<std::string_view>
	get_pos_args() const noexcept
	{
		return this->pos_args;
	}
private:
	std::string name;
	std::string description;

	std::vector<std::string_view> pos_args;
	std::vector<BoolOption>       bool_options;
	std::vector<FloatOption>      float_options;
	std::vector<IntOption>        int_options;
	std::vector<StringOption>     string_options;
};

} // namespace cli

#endif // CLI_APP_HPP

