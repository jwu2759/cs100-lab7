CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(
	calculator
	./src/base.hpp
	./src/factory.hpp
	./src/main.cpp
)
ADD_EXECUTABLE(
	test
	./tests/test.cpp
	./tests/base_test.hpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
