#include "book.hpp"
#include "content.hpp"

#include <fstream>
#include <iostream>

using namespace pub;

Content::Content(ContentData raw)
: raw_{raw}
{}

Content::Content(FileName file_path)
{
	std::ifstream infile{file_path.value.c_str()};
	raw_ = ContentData{std::string{std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>()}};
}

ContentData
Content::raw() const noexcept
{
	return raw_;
}
