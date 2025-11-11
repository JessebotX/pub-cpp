#ifndef PUB_CONTENT_HPP
#define PUB_CONTENT_HPP


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


} // namespace pub


#endif // PUB_CONTENT_HPP
