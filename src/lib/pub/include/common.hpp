#ifndef PUB_COMMON_HPP
#define PUB_COMMON_HPP

#include <string>

namespace pub {

template <typename Value, typename Tag>
struct StrongAlias {
	Value value;
};

using FileName = StrongAlias<std::string, struct FileNameTag>;

} // namespace pub

#endif // PUB_COMMON_HPP
