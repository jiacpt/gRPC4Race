#include <string>

#include <fmt/core.h>
#include <fmt/color.h>

#include <grpcpp/grpcpp.h>
#include "mathtest.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using mathtest::MathReply;
using mathtest::MathRequest;
using mathtest::MathTest;

class MathServiceImplementation final : public MathTest::Service
{
    Status sendRequest(
        ServerContext *context,
        const MathRequest *request,
        MathReply *reply) override
    {
        int a = request->a();
        int b = request->b();

        reply->set_result(a * b);
        std::cout << "get !" << std::endl;

        return Status::OK;
    }
};

void Run()
{
    std::string address("127.0.0.1:12345");
    MathServiceImplementation service;

    ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());

    std::cout << "Server listening on port: " << address << std::endl;

    server->Wait();
}

int main(int argc, char **argv)
{
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "Hello, {}!\n", "world");
    Run();

    return 0;
}
