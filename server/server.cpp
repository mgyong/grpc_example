#include <grpc++/grpc++.h>

#include "proto/hello_world.pb.h"
#include "proto/hello_world.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using hello_world::HelloRequest;
using hello_world::HelloReply;
using hello_world::Greeter;
using std::string;

class GreeterServiceImpl final : public Greeter::Service {
    Status SayHello(ServerContext* context, const HelloRequest* request,
    HelloReply* reply) override {
    string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:10001");
    GreeterServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
RunServer();

return 0;
}