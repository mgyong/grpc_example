#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "proto/hello_world.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hello_world::HelloRequest;
using hello_world::HelloReply;
using hello_world::Greeter;

class GreeterClient {

    public:
    GreeterClient(std::shared_ptr<Channel> channel) : stub_(Greeter::NewStub(channel)) {}
    // Assembles the client's payload, sends it and presents the response back
    // from the server.

    std::string SayHello(const std::string& user){
        HelloRequest request;
        request.set_name(user);

        HelloReply reply;
        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;
        // The actual RPC.
        Status status = stub_->SayHello(&context, request, &reply);
    // Act upon its status.
        if (status.ok()) {
        return reply.message();
            } else {
                std::cout << status.error_code() << ": " << status.error_message()
                            << std::endl;
                return "RPC failed";
            }
        }
    private:
        std::unique_ptr<Greeter::Stub> stub_ ;
    };//end greeterclient

    int main(int argc, char** argv) {
        GreeterClient greeter(grpc::CreateChannel("localhost:10001", grpc::InsecureChannelCredentials()));
        std::string user("world");
        std::string reply = greeter.SayHello(user);
        std::cout << "Greeter received: " <<reply <<std::endl;
        return 0;

    }