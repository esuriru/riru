#include "gfx/ogl_ctx.hpp"

#include "GLFW/glfw3.h"

namespace riru::gfx
{
    void ogl_ctx::present(const core::window& window)
    {
        glfwSwapBuffers(window.get_native_handle());
    }
}