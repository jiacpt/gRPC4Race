# 将列表文件添加到源代码库当中
macro(MIDDLEWARE_ADD_SOURCE)
	set(SOURCE_FILES "")
    foreach(SOURCE_FILE ${ARGN})
        if(SOURCE_FILE MATCHES "^/.*")
            list(APPEND SOURCE_FILES ${SOURCE_FILE})
        else()
            list(APPEND SOURCE_FILES
                 "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}")
        endif()
    endforeach()
    set(MiddlewareSourceFiles ${MiddlewareSourceFiles} ${SOURCE_FILES} PARENT_SCOPE)
endmacro(MIDDLEWARE_ADD_SOURCE)

# 将列表文件添加到头文件库当中方便导入
set(MiddlewareSourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/Middleware.h" "${CMAKE_CURRENT_SOURCE_DIR}/Middleware.cpp")

add_subdirectory(Log)
add_library(RMware SHARED ${MiddlewareSourceFiles})

target_include_directories(RMware 
    PUBLIC "${MiddlewareDir}"
    PUBLIC "${ProjectRootDir}"
)

##########################################################################################

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(RMware PUBLIC spdlog::spdlog spdlog::spdlog_header_only)
