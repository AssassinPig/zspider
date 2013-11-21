#include "Util.hpp"
#include "Common.hpp"
void gethosturl(std::string& url, std::string& hosturl) 
{
	char* start = (char*)strstr(url.c_str(), "http://");
	if(!start) {
		hosturl = url;
	}
 
	start += strlen("http://");
	hosturl = start;
	size_t pos = hosturl.find("/");
	if(pos!=std::string::npos) {
		hosturl = hosturl.substr(0, pos);
	}
}

void getip(std::string& host, char ipstr[])
{
	struct hostent *answer;
	answer = gethostbyname(host.c_str());
	for (int i = 0; (answer->h_addr_list)[i] != NULL; i++) {
		inet_ntop(AF_INET, (answer->h_addr_list)[i], ipstr, 16);
		break;
	}
}

void removehttphead(std::string& url, std::string& nohttp)
{
	size_t pos = url.find("http://");
	pos += strlen("http://");
	if(pos!=std::string::npos) {
		nohttp = url.substr(pos, url.length()-pos-1);
	}
}

void gethtmlfile(std::string& url, std::string& html)
{
	size_t pos = url.find_last_of("/");
	if(pos!=std::string::npos) {
		html = url.substr(pos+1, url.length()-pos);
	}
}
	
void removelastquote(std::string& url)
{
	size_t pos = url.find_last_of("/");
	if(pos!=std::string::npos) {
		url = url.substr(pos+1, url.length()-pos);
	}
}

bool isInvalidateURL(std::string& url)
{
	size_t pos = url.find("http://");		
	if(pos == std::string::npos) {
		printf("is InvalidateURL\n", url.c_str());
		return false;
	}
	
	pos = url.find_last_of("/");	
	char* szIndex = (char*)(url.c_str() + pos);
	char* szEnd = NULL;

	if( (szEnd = strstr(szIndex, "/")) == NULL
		|| (szEnd = strstr(szIndex, "html")) == NULL
		|| (szEnd = strstr(szIndex, "htm")) == NULL
		|| (szEnd = strstr(szIndex, "php")) == NULL
		|| (szEnd = strstr(szIndex, "jsp")) == NULL
		|| (szEnd = strstr(szIndex, "HTML")) == NULL
		|| (szEnd = strstr(szIndex, "HTM")) == NULL)
	{
		return true;
	}
      
	return false;
}
