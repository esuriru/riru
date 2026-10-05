#pragma once

#include "core/window.hpp"

struct GLFWwindow;

namespace riru::gfx
{
    class ogl_ctx final
    {
    public:
        ogl_ctx() = default;

        void make_current(const core::window& window);
        void present(const core::window& window);
        void begin_frame();
    };
}