#ifndef CLI_APP_HPP
#define CLI_APP_HPP

#include <iostream>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace cli {

struct BoolOption {
	std::vector<const char*> flag_names_true;
	std::vector<const char*> flag_names_false;
	bool                     set;
	bool                     value;
	bool                     value_default;
};

class App {
public:
	App(int argc, char* argv[]);

	BoolOption& add_bool_option(std::vector<const char*> flag_names_true, std::vector<const char*> flag_names_false, bool value_default);
private:

	std::vector<std::string_view> args_;
	std::vector<BoolOption> bool_options_;
};

} // namespace cli

#endif // CLI_APP_HPP

