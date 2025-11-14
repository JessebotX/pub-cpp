#include "cli.hpp"

#include <array>
#include <iostream>

int
main(int argc, char* argv[])
{
	cli::App app(argv[0]);

	cli::BoolOption& flag_help = app.add_bool_option(std::vector{"-h"}, std::vector{"-no-h"}, false);
	cli::StringOption& flag_str = app.add_string_option(std::vector{"-s", "--str"}, "hi");

	std::vector<char*> args(argv, argv + argc);
	app.parse(args);

	std::cout << "Hello, world!" << "\n" << "\n";
	std::cout << "-help:   " << flag_help.value << "\n";
	std::cout << "-string: " << flag_str.value << "\n";
}
