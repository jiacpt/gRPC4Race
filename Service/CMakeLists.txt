
add_executable(RMServer Server.cpp)

target_include_directories(RMServer 
    PUBLIC "${MiddlewareDir}"
    PUBLIC "${ProjectRootDir}"
)


##########################################################################################

target_link_libraries(RMServer PUBLIC protobuf-objects gRPC::grpc++ RMware)


find_package(fmt CONFIG REQUIRED)
target_link_libraries(RMServer PUBLIC fmt::fmt-header-only)

