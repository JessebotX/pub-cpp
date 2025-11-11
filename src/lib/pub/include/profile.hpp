#ifndef PUB_PROFILE_HPP
#define PUB_PROFILE_HPP

#include "asset.hpp"
#include "content.hpp"

#include <string>
#include <vector>

namespace pub {

struct Profile {
	std::string                    name;
	std::string                    role;
	std::vector<ExternalReference> links_external;
	std::vector<ExternalReference> links_funding;
	Asset                          image;
	Content                        about;
};

} // namespace pub

#endif // PUB_PROFILE_HPP
