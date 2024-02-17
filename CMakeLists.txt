project(Slae)

cmake_minimum_required(VERSION 3.20)

add_subdirectory(src)

if (WITH_TESTS)
	add_subdirectory(test)
	enable_testing()
endif ()


