#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include<sys/stat.h>
#include<fcntl.h>

#include <string>

#include <list>

#include "ClientNode.hpp"
#include "Util.hpp" 
#include "Parser.hpp"

int main(int argc, char** args)
{
	//www.sina.com.cn
//	std::string url = "http://www.sina.com.cn/";
//	std::string hosturl;
//	gethosturl(url, hosturl);
//	printf("%s\n", hosturl.c_str());
//
// 	char ipstr[16];
//	getip(hosturl, ipstr);
// 	printf("ip:%s\n", ipstr);

//	if( argc != 3 )
//	{
//		for(int i=0; i<argc; ++i)
//		{
//			printf( "argc[%d]: %s\n", i, args[i]);
//		}
//		printf( "Usage: <hostname> <url>\n" );
//		return 1;
//	}

	ClientNode client;
	Parser parser;
	std::list<std::string> todolist;
	std::list<std::string> visitedlist;
	std::string url = "http://www.sina.com.cn/";
	todolist.push_back(url);
	
	while(!todolist.empty()) {
		url = todolist.front();

		if(client.InitConnect(url))
			client.Fetch();
		
		parser.ParseHtmlFile(client.GetFileName(), todolist);	

		visitedlist.push_back(url);
		todolist.pop_front();
		sleep(3);
		//break;
	}
	
//	std::list<std::string>::iterator it = todolist.begin();
//	for(;it!=todolist.end();++it) {
//		printf("%s\n", (*it).c_str());
//	}

	return 0;
}
