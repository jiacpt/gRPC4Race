
add_executable(client client.cpp)

target_include_directories(client 
    PUBLIC "${MiddlewareDir}"
    PUBLIC "${ProjectRootDir}"
)


##########################################################################################
target_link_libraries(client PUBLIC protobuf-objects gRPC::grpc++ RMware)



