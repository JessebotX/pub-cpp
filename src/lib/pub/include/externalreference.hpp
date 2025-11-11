#ifndef PUB_EXTERNALREFERENCE_HPP
#define PUB_EXTERNALREFERENCE_HPP

#include <string>
#include <vector>

namespace pub {

struct ExternalReference {
	std::string                    name;
	std::string                    address;
	std::vector<ExternalReference> domains_alternate;
};

} // namespace pub

#endif // PUB_EXTERNALREFERENCE_HPP
