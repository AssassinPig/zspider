#ifndef _PARSER_H__
#define _PARSER_H__
class Parser
{
public:
	void ParseHtmlFile(std::string& filename, std::list<std::string>& todolist) 
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
			if(szStart)
			{
				szEnd = strstr(szStart, ">");	
				ParseContent(szStart, szEnd, todolist);
				szIndex = szEnd;
				szStart = NULL;
				szEnd = NULL;
			}
			else
			{
				printf("parse : no match < or end\n");		
				break;
			}
		}while(true);
		free(buf);
	}

private:	
	void ParseContent(const char* szStart, const char* szEnd, std::list<std::string>& todolist)
	{
		const char* szHref = strstr(szStart, "href=\"");
		if(!szHref || szHref > szEnd)
		{
			return;
		}

		szHref += strlen("href=\"");
		const char* szHrefEnd = NULL;
		if(szHref)
		{
			szHrefEnd = strstr(szHref, "\"");	
		}
		else
		{
			return;
		}


		if(szHref && szHrefEnd)
		{
			std::string strURL(szHref, szHrefEnd-szHref);
			todolist.push_back(strURL);
			//printf("%s\n", strURL.c_str());
			//SaveHrefFile(szHref, szHrefEnd);
		}

	}
};
#endif //_PARSER_H__
