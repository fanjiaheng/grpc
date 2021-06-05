#pragma once
#include <string>
#include <memory>
#include "./../include/helloworld.grpc.pb.h"

namespace cli
{

using Stub = zhst::Greeter::Stub;
using Request = ::zhst::HelloRequest;
using Response = ::zhst::HelloReply;

class Client
{
public:
    Client();
    ~Client();

    bool init();
    bool unInit();
    void sayHello(const std::string& text);

private:
    std::unique_ptr<Stub> m_stub{ nullptr };
    std::string m_address{ "127.0.0.1:9000" };
};

} //jh