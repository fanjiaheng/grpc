#include "Server.h"

int main()
{
    //启动服务
    srv::Server::instance()->start();
    return 0;
}