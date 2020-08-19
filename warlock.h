#ifndef WARLOCK_H
#define WARLOCK_H

#ifdef __linux__
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xatom.h>
#endif // __linux__

#ifdef WARLOCK_OPENGL_ES
    #include <EGL/egl.h>
#endif // WARLOCK_OPENGL_ES

#include "guards.h"
#include "context.h"

#endif
