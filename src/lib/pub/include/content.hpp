#ifndef PUB_CONTENT_HPP
#define PUB_CONTENT_HPP

#include "common.hpp"

#include <string>
#include <vector>

namespace pub {

using ContentData = StrongAlias<std::string, struct ContentDataTag>;

class Content {
public:
	Content(ContentData raw);
	Content(FileName file_name);

	ContentData raw() const noexcept;

private:
	ContentData              raw_;
	std::vector<ContentData> parsed_;
};

} // namespace pub

#endif // PUB_CONTENT_HPP
