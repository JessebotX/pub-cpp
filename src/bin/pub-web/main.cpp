#include "cli.hpp"

#include <array>
#include <iostream>

int
main(int argc, char* argv[])
{
	cli::App app(argc, argv);

	cli::BoolOption& flag_help = app.add_bool_option(std::vector{"-h"}, std::vector{"-no-h"}, false);

	std::cout << "Hello, world!" << "\n" << "\n";
	std::cout << "-h: " << flag_help.value_default << "\n";
}
