#pragma once

#include <memory>

namespace Race
{
    class Log
    {

    public:
        static void Init();


    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };

    void Log::Init()
    {
#ifdef _DEBUG

#endif
    }


};

// define logger macros
// TIP: 使用空指针的成员函数会导致程序崩溃嘛？
// 如果在空指针上调用成员函数，只要不使用this指针，程序就不会崩溃。
#define RC_CORE_ERROR(...)
#define RC_CORE_INFO(...)
#define RC_CORE_TRACE(...)
#define RC_CORE_WARN(...)
#define RC_CORE_FATAL(...)

#define RC_ERROR(...)
#define RC_INFO(...)
#define RC_TRACE(...)
#define RC_WARN(...)
#define RC_FATAL(...)
