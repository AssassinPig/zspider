#ifndef _CLIENT_NODE_H__ 
#define _CLIENT_NODE_H__

#include "Common.hpp"
#include "CPage.hpp"

class ClientNode
{
public:
    ClientNode();
    virtual ~ClientNode();
    void Fetch(CPage& page);
private:
};

#endif //_CLIENT_NODE_H__ 
