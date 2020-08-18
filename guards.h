#ifndef WARLOCK_GUARDS_H
#define WARLOCK_GUARDS_H

#include <iostream>

#ifndef WARLOCK_DISABLE_EGLCALL
    #define eglCall(x) x; ASSERT(Warlock::eglLogError(#x, __FILE__, __LINE__));
#else
    #define eglCall(x) x;
#endif // WARLOCK_DISABLE_EGLCALL

namespace Warlock
{
    static bool eglLogError(const char* a_functionName, const char* a_fileName, const int a_line)
    {
        switch (eglGetError())
        {
            case EGL_SUCCESS:
                break;

            case EGL_NOT_INITIALIZED:
                std::cerr << "[EGL Error] {EGL_NOT_INITIALIZED}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_ACCESS:
                std::cerr << "[EGL Error] {EGL_BAD_ACCESS}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_ALLOC:
                std::cerr << "[EGL Error] {EGL_BAD_ALLOC}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_ATTRIBUTE:
                std::cerr << "[EGL Error] {EGL_BAD_ATTRIBUTE}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_CONTEXT:
                std::cerr << "[EGL Error] {EGL_BAD_CONTEXT}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_CONFIG:
                std::cerr << "[EGL Error] {EGL_BAD_CONFIG}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_CURRENT_SURFACE:
                std::cerr << "[EGL Error] {EGL_BAD_CURRENT_SURFACE}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_DISPLAY:
                std::cerr << "[EGL Error] {EGL_BAD_DISPLAY}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_SURFACE:
                std::cerr << "[EGL Error] {EGL_BAD_SURFACE}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_MATCH:
                std::cerr << "[EGL Error] {EGL_BAD_MATCH}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_PARAMETER:
                std::cerr << "[EGL Error] {EGL_BAD_PARAMETER}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_NATIVE_PIXMAP:
                std::cerr << "[EGL Error] {EGL_BAD_NATIVE_PIXMAP}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_BAD_NATIVE_WINDOW:
                std::cerr << "[EGL Error] {EGL_BAD_NATIVE_WINDOW}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;

            case EGL_CONTEXT_LOST:
                std::cerr << "[EGL Error] {EGL_CONTEXT_LOST}\ncaused by " << a_functionName << "\non line number " << a_line << "\nin " << a_fileName << std::endl;
                return false;
        }

        return true;
    }
};

#endif
