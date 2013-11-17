#ifndef _UTIL_H__
#define _UTIL_H__

#include "Common.hpp"

void gethosturl(std::string& url, std::string& hosturl);    
void getip(std::string& host, char ipstr[]);
void removehttphead(std::string& url, std::string& nohttp);
void gethtmlfile(std::string& url, std::string& html);
void removelastquote(std::string& url);
bool isInvalidateURL(std::string& url);

#endif
