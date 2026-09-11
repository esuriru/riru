#pragma once

#include <cstdint>
#include <string>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace riru::core
{
    class window
    {
    public:
        enum class result
        {
            success = 0,
            glfw_init_fail,
            window_already_init,
            window_init_fail,
        };

        window(uint32_t width, uint32_t height, std::string_view title);
        virtual ~window();

        result init();
        void update();
        
    protected:
        GLFWwindow* handle;

        uint32_t width;
        uint32_t height;
        std::string title;

        static void on_resize(GLFWwindow* handle, int width, int height);
        static void on_close(GLFWwindow* handle);
    };
}