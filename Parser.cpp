#include "Parser.hpp"
#include "Util.hpp"

void Parser::Parse(CPage& page, 
	std::list<std::string>& todolist,
	std::list<std::string>& visitedlist)	
{
	//if this page need to be fetched
	std::string& content = page.GetContent(); 	
	//printf("%s\n", content.c_str());
	
	FILE* file = fopen("1.html", "w+");
	fwrite(content.c_str(), sizeof(char), content.length(), file); 
	fclose(file);

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
					FILE* file = fopen("1.link", "aw");
					fwrite(strURL.c_str(), sizeof(char), strURL.length(), file); 
					fwrite("\n", sizeof(char), 1, file); 
					fclose(file);
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
/*
void Parser::ParseHtmlFile(std::string& filename, std::list<std::string>& todolist) 
{
	FILE* pFile = fopen(filename.c_str(), "rb");
	if(pFile==NULL)	{
		perror("open file failed\n");
	}

	int nFileSize = fseek(pFile, 0, SEEK_END);
	nFileSize = ftell(pFile);
	//	printf("file size = %d\n", nFileSize);
	fseek(pFile, 0, SEEK_SET);

	char* szStart = NULL;
	char* szEnd = NULL;
	char* buf = (char*)malloc(nFileSize);
	memset(buf, 0, nFileSize);
	if(!buf) {
		perror("malloc failed");
	}

	int n = fread(buf, sizeof(char), nFileSize, pFile);
	if(n <= 0) {
		perror("read failed");
		return;	
	}
	fclose(pFile);

	char *szIndex = buf;
	do{
		szStart = strstr(szIndex, "<");
		if(szStart) {
			szEnd = strstr(szStart, ">");	
			ParseContent(szStart, szEnd, todolist);
			szIndex = szEnd;
			szStart = NULL;
			szEnd = NULL;
		} else {
			printf("parse : no match < or end\n");		
			break;
		}
	}while(true);
	free(buf);
}

void Parser::ParseContent(const char* szStart, const char* szEnd, std::list<std::string>& todolist)
{
	const char* szHref = strstr(szStart, "href=\"");
	if(!szHref || szHref > szEnd) {
		return;
	}

	szHref += strlen("href=\"");
	const char* szHrefEnd = NULL;
	if(szHref) {
		szHrefEnd = strstr(szHref, "\"");	
	} else {
		return;
	}

	if(szHref && szHrefEnd) {
		std::string strURL(szHref, szHrefEnd-szHref);
		todolist.push_back(strURL);
		//printf("%s\n", strURL.c_str());
		//SaveHrefFile(szHref, szHrefEnd);
	}

}
*/
