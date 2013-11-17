#include "ZSpider.hpp"
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

//	ClientNode client;
//	Parser parser;
//	std::list<std::string> todolist;
//	std::list<std::string> visitedlist;
//	std::string url = "http://www.sina.com.cn/";
//	todolist.push_back(url);
//	
//	while(!todolist.empty()) {
//		url = todolist.front();
//
//		if(client.InitConnect(url))
//			client.Fetch();
//		
//		parser.ParseHtmlFile(client.GetFileName(), todolist);	
//
//		visitedlist.push_back(url);
//		todolist.pop_front();
//		sleep(3);
//	}
	
//	std::list<std::string>::iterator it = todolist.begin();
//	for(;it!=todolist.end();++it) {
//		printf("%s\n", (*it).c_str());
//	}

	
	ZSpider spider;
	spider.Run();

	return 0;
}
