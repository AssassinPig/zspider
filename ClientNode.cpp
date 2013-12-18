#include "ClientNode.hpp"
#include "zlog.hpp"


ClientNode::ClientNode()
{
}

ClientNode::~ClientNode()
{
}


void ClientNode::Fetch(CPage& page)
{
    //parse url get host
    //get ip
    //connection building
    //get request head
    //fetch web page
    //record to cpage 

    struct sockaddr_in sin;
    memset( (void *)&sin, 0, sizeof(struct sockaddr_in) );
    sin.sin_family = AF_INET;
    sin.sin_port = htons(page.GetPort());

    std::string hostaddr;
    page.GetHostIP(hostaddr);
    sin.sin_addr.s_addr = inet_addr(hostaddr.c_str());

    std::string& strRequestHead = page.GetRequestHead();	
    ZDEBUG_LOG("page head %s", strRequestHead.c_str());

    int m_socket = socket( AF_INET, SOCK_STREAM, 0 );
    if( m_socket < 0 ) {
        ZDEBUG_LOG( "Socket creation failed");
        perror( "Socket creation failed\n");
        return ;
    }

    int ret = connect(m_socket, (struct sockaddr *)&sin, sizeof(struct sockaddr_in));
    if(ret) {
        ZDEBUG_LOG("connect failed");			
        perror("connect failed\n");			
        return ;
    }

    int n = send(m_socket, strRequestHead.c_str(), BUF_MAX, 0); 
    if( n<=0 ) {
        perror("send failed");			
        ZDEBUG_LOG("send failed");			
    }
    else {

        std::string& content = page.GetContent();
        char buf[BUF_MAX];

        do{
            memset(buf, 0, BUF_MAX);
            n = recv(m_socket, buf, BUF_MAX, 0);
            //printf("recv %d :%s", n, buff);

            if(n) {
                content += buf;	
            }

        }while(n==BUF_MAX || n!=0);
        ZDEBUG_LOG("recv all");
    }

    close(m_socket);
}

