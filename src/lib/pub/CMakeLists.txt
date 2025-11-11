add_library(pub)

target_sources(pub
	PRIVATE book.cpp
)

target_include_directories(pub
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(pub
	PUBLIC
		cxx_std_20
)

