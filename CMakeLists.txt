cmake_minimum_required(VERSION 3.2.0)

project(gRPC4Race 
        VERSION 0.1.0 
        LANGUAGES CXX
)

find_package(gRPC REQUIRED)

add_subdirectory(Proto)
add_subdirectory(Service)
add_subdirectory(Middleware)
add_subdirectory(Test)


set(ProjectRootDir "${CMAKE_CURRENT_SOURCE_DIR}")
set(MiddlewareDir "${ProjectRootDir}/Middleware")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")




