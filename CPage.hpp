#ifndef _PAGE_H__
#define _PAGE_H__

#include "Common.hpp"

class CPage
{
public:
    CPage(std::string& strURL);	
    ~CPage();	

    bool Output(std::string& filename);
    bool Input(std::string& filename);

    int GetPort();
    void GetHostIP(std::string& hostip);

    std::string& GetRequestHead();
    std::string& GetContent();

    void ClearInfo();

private:
    void BuildHeadInfo();
    std::string m_strURL;
    std::string m_strRequestHead;
    std::string m_strResponseHead;

    std::string m_strPageContent;
};

#endif
