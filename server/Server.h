#pragma once
#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "./../include/helloworld.grpc.pb.h"


namespace srv
{

class Server
{
public:
    Server();
    ~Server();

    static Server* instance() {
        static Server inst;
        return &inst;
    }

public:
    void start();

private:
    std::shared_ptr<grpc::Server> m_server{ nullptr };
    grpc::ServerBuilder m_builder;

    std::string m_address{ "127.0.0.1:9000" };
};

} // namespace name
