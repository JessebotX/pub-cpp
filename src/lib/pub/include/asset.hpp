#ifndef PUB_ASSET_HPP
#define PUB_ASSET_HPP

#include "common.hpp"
#include "content.hpp"

#include <string>

namespace pub {

using AssetFileType = std::string;

struct Asset {
	FileName           name;
	AssetFileType      type;
	std::string        fallback_text;
	Content            caption;
	std::vector<Asset> fallback_assets;
};

} // namespace pub

#endif // PUB_ASSET_HPP
