#ifndef _PARSER_H__
#define _PARSER_H__

#include "CPage.hpp"

class Parser
{
public:
	void Parse(CPage& page, 
	std::list<std::string>& todolist,
	std::list<std::string>& visitedlist);	

//	void ParseHtmlFile(std::string& filename, std::list<std::string>& todolist); 

//	void ParseContent(const char* szStart, const char* szEnd, std::list<std::string>& todolist);

};
#endif //_PARSER_H__
