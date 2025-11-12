add_executable(pub-web)

target_sources(pub-web
	PRIVATE
		main.cpp
)

target_link_libraries(pub-web
	PUBLIC pub
)
