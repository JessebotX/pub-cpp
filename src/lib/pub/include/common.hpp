#ifndef PUB_COMMON_HPP
#define PUB_COMMON_HPP

#include <nlohmann/json.hpp>

#include <string>

namespace pub {

template <typename Value, typename Tag>
struct StrongAlias {
	Value value;
};

using FileName = StrongAlias<std::string, struct FileNameTag>;
using JSON = nlohmann::json;

} // namespace pub

#endif // PUB_COMMON_HPP
