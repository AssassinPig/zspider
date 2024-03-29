#include "CPage.hpp"
#include "Common.hpp"
#include "Util.hpp"

CPage::CPage(std::string& strURL)
{
	m_strURL = strURL;
	BuildHeadInfo();
}
	
CPage::~CPage()
{
}

bool CPage::Output(std::string& filename)
{
    std::string record = "./website/" + filename; 
    FILE* file = fopen(record.c_str(), "w+");
    fwrite(m_strPageContent.c_str(), sizeof(char), m_strPageContent.length(), file); 
    fclose(file);

    return true;
}

bool CPage::Input(std::string& filename)
{
    return true;
}

int CPage::GetPort()
{
    return 80;	
}

void CPage::GetHostIP(std::string& hostip)
{
    std::string hosturl;
    gethosturl(m_strURL, hosturl);
    char buf[IP_MAX];
    getip(hosturl, buf);
    hostip = buf;
}

std::string& CPage::GetRequestHead()
{
    return m_strRequestHead;
}

std::string& CPage::GetContent()
{
    return m_strPageContent;
}

void CPage::ClearInfo()
{
    m_strURL.clear();
    m_strRequestHead.clear();
    m_strResponseHead.clear();

    m_strPageContent.clear();;
}

void CPage::ProcessResponse()
{
    size_t pos = m_strPageContent.find("<");    
    if(pos != std::string::npos) {
        m_strResponseHead = m_strPageContent.substr(0, pos);
        m_strPageContent = m_strPageContent.substr(pos, std::string::npos);
    }
}

void CPage::BuildHeadInfo()
{
    std::string hostip;
    GetHostIP(hostip);	

    char buf[URL_MAX];
    sprintf(buf, "GET %s HTTP/1.1\r\n"\
            "Host: %s \r\n"\
            "Accept: */*\r\n"\
            "Connection: close\r\n\r\n", m_strURL.c_str(), hostip.c_str() 
           );

    m_strRequestHead = buf;
}
