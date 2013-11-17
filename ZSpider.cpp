#include "ZSpider.hpp"
#include "ClientNode.hpp"
#include "Parser.hpp"

ZSpider::ZSpider()
{
	m_status = false;
	std::string url = "http://www.sina.com.cn/";
	//std::string url = "http://www.baidu.com/s?wd=fpermissive&rsv_bp=0&ch=&tn=baidu&bar=&rsv_spt=3&ie=utf-8&rsv_n=2&rsv_sug3=1&rsv_sug=0&rsv_sug1=1&rsv_sug4=15&inputT=265";
	m_todolist.push_back(url);
}

void ZSpider::Run()
{
	m_status = true;

	ClientNode client;
	Parser parser;
	while(m_status)	{
		if(m_todolist.empty()) {
			break;
		}
		
		std::string url = m_todolist.front();	
		//if this page need to be fetched
		
		CPage page(url);		
		client.Fetch(page);	
		parser.Parse(page, m_todolist, m_visitedlist);	
	
		m_visitedlist.push_back(url);
		m_todolist.pop_front();
		sleep(2);
		break;
	}
}
