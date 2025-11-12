#ifndef PUB_BOOK_HPP
#define PUB_BOOK_HPP

#include "common.hpp"
#include "chapter.hpp"
#include "content.hpp"
#include "copyright.hpp"
#include "externalreference.hpp"
#include "profile.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace pub {

class Book {
private:
	std::string                                  unique_id_;
	std::string                                  title_;
	std::string                                  subtitle_;
	std::vector<std::string>                     titles_alternate_;
	std::string                                  edition_;
	std::vector<std::string>                     tags_;
	std::string                                  language_code_;
	std::vector<Profile>                         authors_;
	std::vector<Profile>                         contributors_;
	std::vector<Profile>                         publishers_;
	std::vector<ExternalReference>               links_external_;
	std::vector<ExternalReference>               links_funding_;
	std::vector<ExternalReference>               links_mirrors_;
	std::unordered_map<std::string, std::string> ids_;
	Content                                      content_;
	std::vector<Chapter>                         chapters_;
	Copyright                                    copyright_;
};

} // namespace pub

#endif // PUB_BOOK_H
