#include "Parser.hpp"
#include "Util.hpp"

void Parser::Parse(CPage& page, 
        std::list<std::string>& todolist,
        std::list<std::string>& visitedlist)	
{
    //if this page need to be fetched
    std::string& content = page.GetContent(); 	

    char* szIndex = (char*)content.c_str();
    char* szStart = NULL;
    char* szEnd = NULL;
    do{
        szStart = strstr(szIndex, "<");
        if(szStart) {
            szEnd = strstr(szStart, ">");	
            if(!szEnd) {
                printf("no match >\n");
                break;	
            }

            const char* szHref = strstr(szStart, "href=\"");
            if(!szHref || szHref > szEnd) {
                printf("no href=\n");
                szIndex = szEnd;
                szStart = NULL;
                szEnd = NULL;
                continue;
            }

            szHref += strlen("href=\"");
            const char* szHrefEnd = NULL;
            if(szHref) {
                szHrefEnd = strstr(szHref, "\"");	
            } else {
                printf("no href \" \n");
                szIndex = szEnd;
                szStart = NULL;
                szEnd = NULL;
                continue;
            }

            if(szHref && szHrefEnd) {
                std::string strURL(szHref, szHrefEnd-szHref);
                if(isInvalidateURL(strURL)) {
                    todolist.push_back(strURL);
                }
            }

            szIndex = szEnd;
            szStart = NULL;
            szEnd = NULL;
        } else {
            printf("parse : no match < or end\n");		
            break;
        }
    }while(true);

}
