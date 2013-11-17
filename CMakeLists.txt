PROJECT(zspider)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)
#AUX_SOURCE_DIRECTORY(. DIR_SRCS)

INCLUDE_DIRECTORIES(/usr/local/include/)
LINK_DIRECTORIES(/usr/local/lib/)

#SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O3 -Wall -g")

ADD_EXECUTABLE(main
		main.cpp
		Util.cpp 
		ZSpider.cpp 
		CPage.cpp 
		ClientNode.cpp 
		Parser.cpp)
