#ifndef WARLOCK_CONTEXT_H
#define WARLOCK_CONTEXT_H

namespace Warlock
{
    class Context
    {
    public:
        #ifdef WARLOCK_OPENGL_ES
            EGLDisplay eglDisplay;
            EGLSurface eglSurface;
            EGLContext eglContext;
        #endif // WARLOCK_OPENGL_ES

        void makeCurrent(const bool a_vsync = true)
        {
            #ifdef WARLOCK_OPENGL_ES
                eglCall(eglMakeCurrent(this->eglDisplay, this->eglSurface, this->eglSurface, this->eglContext));
                eglCall(eglSwapInterval(this->eglDisplay, a_vsync));
            #endif // WARLOCK_OPENGL_ES
        }

        void swapBuffers()
        {
            #ifdef WARLOCK_OPENGL_ES
                eglCall(eglSwapBuffers(this->eglDisplay, this->eglSurface));
            #endif // WARLOCK_OPENGL_ES
        }

        #ifdef __linux__
        Context(Display* const a_xDisplay, const ::Window a_xWindow, const int a_depth = 24)
        {
            #ifdef WARLOCK_OPENGL_ES
                EGLint attr[] = {
                    EGL_BUFFER_SIZE, 16,
                    EGL_DEPTH_SIZE, a_depth,
                    EGL_STENCIL_SIZE, 8,
                    EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
                    EGL_NONE
                };
                EGLint ctxattr[] = {
                    EGL_CONTEXT_CLIENT_VERSION,
                    2,
                    EGL_NONE
                };

                eglCall(this->eglDisplay = eglGetDisplay((EGLNativeDisplayType) a_xDisplay));
                eglCall(eglInitialize(this->eglDisplay, NULL, NULL));

                EGLConfig ecfg;
                EGLint num_config;
                eglCall(eglChooseConfig(this->eglDisplay, attr, &ecfg, 1, &num_config));
                if (num_config != 1)
                {
                    std::cerr << "[WARLOCK]{ERROR} Didn't get exactly one config, but " << num_config << std::endl;
                }

                eglCall(this->eglSurface = eglCreateWindowSurface(this->eglDisplay, ecfg, a_xWindow, NULL));
                eglCall(this->eglContext = eglCreateContext(this->eglDisplay, ecfg, EGL_NO_CONTEXT, ctxattr));
            #endif // WARLOCK_OPENGL_ES
        }
        #endif // __linux__

        ~Context()
        {
            #ifdef WARLOCK_OPENGL_ES
                eglCall(eglMakeCurrent(this->eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT));
                eglCall(eglDestroySurface(this->eglDisplay, this->eglSurface));
                eglCall(eglDestroyContext(this->eglDisplay, this->eglContext));
                eglCall(eglTerminate(this->eglDisplay));
            #endif // WARLOCK_OPENGL_ES
        }
    };
}

#endif
