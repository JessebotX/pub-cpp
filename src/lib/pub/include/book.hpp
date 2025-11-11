#ifndef PUB_BOOK_HPP
#define PUB_BOOK_HPP

#include "content.hpp"
#include "externalreference.hpp"
#include "profile.hpp"

#include <string>
#include <vector>

namespace pub {

struct Book {
	std::string                    title;
	std::string                    subtitle;
	std::vector<std::string>       titles_alternate;
	std::string                    edition;
	std::vector<std::string>       tags;
	std::string                    language_code;
	std::vector<Profile>           authors;
	std::vector<Profile>           contributors;
	std::vector<Profile>           publishers;
	std::vector<ExternalReference> links_external;
	std::vector<ExternalReference> links_funding;
	std::vector<ExternalReference> links_mirrors;
	Content                        content;
};

} // namespace pub


#endif // PUB_BOOK_H
