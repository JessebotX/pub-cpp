#ifndef PUB_COPYRIGHT_HPP
#define PUB_COPYRIGHT_HPP

#include "common.hpp"

#include <string>

namespace pub {

struct CopyrightLicense {
	FileName    file_name;
	std::string text;
};

struct Copyright {
	std::string      notice;
	CopyrightLicense license;
};

} // namespace pub

#endif // PUB_COPYRIGHT_HPP
