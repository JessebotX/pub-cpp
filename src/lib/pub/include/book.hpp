#ifndef PUB_BOOK_HPP
#define PUB_BOOK_HPP


#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace pub {


template <typename Value, typename Tag>
struct StrongAlias {
	Value value;
};

using ContentFilePath = StrongAlias<std::string, struct ContentFilePathTag>;
using ContentData = StrongAlias<std::string, struct ContentDataTag>;

class Content {
public:
	Content(ContentData raw);

	Content(ContentFilePath file_name);

	ContentData raw() const noexcept;

private:
	ContentData raw_;
	std::vector<ContentData> parsed_;
};

class ExternalReference {
public:
	std::string name;
	std::string address;
};

class Profile {
public:
	std::string name;
	std::string role;
	std::vector<ExternalReference> links_external;
	std::vector<ExternalReference> links_funding;
};

class Book {
public:
	std::string title;
	std::string subtitle;
	std::vector<std::string> titles_alternate;
	std::string edition;
	std::vector<std::string> tags;
	std::string language_code;
	std::vector<Profile> authors;
	std::vector<Profile> contributors;
	std::vector<Profile> publishers;
	Content content;
};


} // namespace pub


#endif // PUB_BOOK_H
