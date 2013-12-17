#ifndef __ZSPIDER_H__
#define __ZSPIDER_H__

#include "Common.hpp"

class ZSpider 
{
    public:
        ZSpider();
        void Run();

    private:
        bool m_status;
        std::list<std::string> m_todolist;
        std::list<std::string> m_visitedlist;
};


#endif //__ZSPIDER_H__
