#include "ZSpider.hpp"
#include "ClientNode.hpp"
#include "Parser.hpp"
#include "zlog.hpp"

ZLOG_INIT(spider.log);
ZSpider::ZSpider()
{
    m_status = false;
    std::string url = "http://www.the9.com/";
    //std::string url = "http://www.sina.com.cn/";
    m_todolist.push_back(url);
}

void ZSpider::Run()
{
    m_status = true;

    char buf[128];
    int n=1;
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

        sprintf(buf, "%d", n++);
        std::string filename(buf);
        page.ProcessResponse();
        page.Output(filename);
        parser.Parse(page, m_todolist, m_visitedlist);	

        m_visitedlist.push_back(url);
        m_todolist.pop_front();
        sleep(1);
        //break;
    }
}
