#ifndef PUB_PROFILE_HPP
#define PUB_PROFILE_HPP

#include <string>
#include <vector>

class Profile {
public:
	std::string name;
	std::string role;
	std::vector<ExternalReference> links_external;
	std::vector<ExternalReference> links_funding;
};


#endif // PUB_PROFILE_HPP
