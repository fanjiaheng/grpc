#include "Server.h"
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>

namespace srv
{

// grpc interface
namespace internal {

using Request = ::zhst::HelloRequest;
using Response = ::zhst::HelloReply;

class GreeterImpl final : public zhst::Greeter::Service 
{
public:
    GreeterImpl() {};
    ~GreeterImpl() {};

public:
    virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const Request* request, Response* response) override {
        std::string prefix("Hello ");
        response->set_message(prefix + request->name());
        return grpc::Status::OK;
    }
};

} //internal

Server::Server()
{
    ;
}

Server::~Server()
{
    ;
}

void Server::start()
{
    ::grpc::EnableDefaultHealthCheckService(true);
    // ::grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    // Listen on the given address without any authentication mechanism.
    m_builder.AddListeningPort(m_address, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    internal::GreeterImpl service;
    m_builder.RegisterService(&service);

    // Finally assemble the server.
    m_server = std::shared_ptr<grpc::Server>(m_builder.BuildAndStart());

    std::cout << "Server listening on " << m_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    m_server->Wait();
}

}