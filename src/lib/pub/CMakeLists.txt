add_library(pub)

CPMAddPackage(
	NAME json
	GIT_REPOSITORY https://github.com/nlohmann/json.git
	GIT_TAG v3.12.0
)

target_link_libraries(pub
	PUBLIC nlohmann_json::nlohmann_json
)

target_sources(pub
	PRIVATE book.cpp
)

target_include_directories(pub
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(pub
	PUBLIC cxx_std_20
)

