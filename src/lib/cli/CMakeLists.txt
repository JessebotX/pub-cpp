add_library(cli)

target_sources(cli
	PRIVATE cli.cpp
)

target_include_directories(cli
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(cli
	PUBLIC cxx_std_20
)
