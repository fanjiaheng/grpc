#include "Client.h"
#include <grpcpp/grpcpp.h>

namespace cli
{

Client::Client()
{
    ;
}

Client::~Client()
{
    ;
}

bool Client::init()
{
    m_stub = std::make_unique<Stub>(grpc::CreateChannel(m_address, grpc::InsecureChannelCredentials()));
    if (m_stub == nullptr) {
        std::cout << "create grpc client stub failed." << std::endl;
        return false;
    }
}

bool Client::unInit()
{
    ;
}

void Client::sayHello(const std::string& text)
{
    Request req;
    Response resp;

    req.set_name(text);

    grpc::ClientContext context;

    grpc::Status status = m_stub->SayHello(&context, req, &resp);
    if (status.ok()) {
        std::cout << "resp info: " << resp.message() << std::endl;
    } else {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
    }

    return;
}

} // namespace jh
