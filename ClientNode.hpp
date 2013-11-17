#ifndef _CLIENT_NODE_H__ 
#define _CLIENT_NODE_H__

#include "Common.hpp"
#include "CPage.hpp"

class ClientNode
{
public:
	ClientNode();
	virtual ~ClientNode();
	//bool InitConnect(std::string& url);
	//std::string& GetFileName() { return m_strFileName; }
	void Fetch(CPage& page);

private:
//	std::string m_strURL;
//	char m_szHost[HOST_MAX];
//	int m_socket;
//	FILE* m_pFile;
//	std::string m_strFileName;
};



#endif //_CLIENT_NODE_H__ 
