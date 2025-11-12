#ifndef PUB_CHAPTER_HPP
#define PUB_CHAPTER_HPP

#include "content.hpp"
#include "externalreference.hpp"
#include "profile.hpp"

#include <string>
#include <vector>
#include <unordered_map>

namespace pub {

struct Chapter {
	std::string                                  unique_id;
	std::string                                  title;
	std::string                                  subtitle;
	std::vector<std::string>                     titles_alternate;
	std::vector<std::string>                     tags;
	std::string                                  language_code;
	std::vector<Profile>                         authors;
	std::vector<Profile>                         contributors;
	std::vector<Profile>                         publishers;
	std::vector<ExternalReference>               links_external;
	std::vector<ExternalReference>               links_funding;
	std::vector<ExternalReference>               links_mirrors;
	std::unordered_map<std::string, std::string> ids;
	Content                                      content;
	std::vector<Chapter>                         chapters;
};

} // namespace pub

#endif // PUB_CHAPTER_HPP
