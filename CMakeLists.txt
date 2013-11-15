PROJECT(zspider)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)
#AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#INCLUDE_DIRECTORIES(/usr/local/include/)

#SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_C_FLAGS_DEBUG "-O3 -Wall -g -std=c99")

INCLUDE_DIRECTORIES(/usr/local/include/)
LINK_DIRECTORIES(/usr/local/lib/)

#ADD_EXECUTABLE(test_boost test_boost.cpp)
#TARGET_LINK_LIBRARIES(test_boost boost_thread)

#TARGET_LINK_LIBRARIES(main boost_thread)
#SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O3 -Wall -g")

#ADD_EXECUTABLE(gethost gethost.cpp)
#ADD_EXECUTABLE(parse parse.cpp)
#ADD_EXECUTABLE(get get.cpp)

#ADD_EXECUTABLE(zspider zspider.cpp)
ADD_EXECUTABLE(main main.cpp ClientNode.hpp Util.hpp Parser.hpp)
