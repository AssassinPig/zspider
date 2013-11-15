#ifndef _CLIENT_NODE_H__ 
#define _CLIENT_NODE_H__

#include "Common.hpp"
#include "Util.hpp"

class ClientNode
{
public:
	ClientNode()
	{
		memset(m_szHost, 0, HOST_MAX);
	}

	virtual ~ClientNode(){
	}

	virtual bool InitConnect(std::string& url)
	{
		m_strURL = url;
		std::string urlhost;
		gethosturl(url, urlhost);
	//	printf("%s\n", m_strURL.c_str());
		getip(urlhost, m_szHost);
 	//	printf("ip:%s\n", m_szHost);

		struct sockaddr_in sin;
		memset( (void *)&sin, 0, sizeof( struct sockaddr_in) );
		sin.sin_family = AF_INET;
		sin.sin_port = htons(80);
		sin.sin_addr.s_addr = inet_addr(m_szHost);
		
		//printf("m_szHost:%s\n", m_szHost);
		m_socket = socket( AF_INET, SOCK_STREAM, 0 );
		if( m_socket < 0 )
		{
			perror( "Socket creation failed\n");
			return false;
		}
		
		int ret = connect(m_socket, (struct sockaddr *)&sin, sizeof(struct sockaddr_in));
		if(ret)
		{
			perror("connect failed\n");			
			return false;
		}

		std::string filename;
		std::string strurl;
		removehttphead(m_strURL, strurl);
		//removelastquote(strurl);
		//printf("m_strURL%s\nstrurl %s\n", m_strURL.c_str(), strurl.c_str());
		gethtmlfile(strurl, filename);
		printf("strurl:%s\nfilename:%s\n", strurl.c_str(), filename.c_str());
		
		if(filename.empty()) {
			removelastquote(strurl);
			filename = strurl;	
			printf("filename:%s\n", filename.c_str());
		}

		m_strFileName = filename;
		m_pFile = fopen(filename.c_str(), "wt");
		if(!m_pFile)
		{
			perror("open file failed\n");			
			return false;	
		}

		return true;	
	}
	
	virtual void Fetch()
	{
		char buff[BUF_MAX];
		memset(buff, 0, BUF_MAX);	

		sprintf(buff, "GET %s HTTP/1.0\r\n"\
				"Host: %s \r\n"\
				"Accept: */*\r\n"\
				"Connection: close\r\n\r\n", m_strURL.c_str(), m_szHost  	
				);
		
		//printf("buff:%s\n", buff);
		int n = send(m_socket, buff, BUF_MAX, 0); 
		if(n<=0)
		{
			perror("send failed");			
		}
		else
		{
			do{
				memset(buff, 0, BUF_MAX);	
				n = recv(m_socket, buff, BUF_MAX, 0);
				//printf("recv %d :%s", n, buff);

				if(m_pFile && n)
				{
					int nwrite = fwrite(buff, sizeof(char), n, m_pFile);	
					if(!nwrite)
					{
						perror("write failed");
						break;
					}
				}

			}while(n==BUF_MAX || n!=0);
			printf("recv all\n");
		}

		close(m_socket);
		fclose(m_pFile);
	}

	std::string& GetFileName() { return m_strFileName; }
private:
	std::string m_strURL;
	char m_szHost[HOST_MAX];
	int m_socket;
	FILE* m_pFile;
	std::string m_strFileName;
};



#endif //_CLIENT_NODE_H__ 
