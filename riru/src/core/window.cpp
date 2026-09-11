#include "core/window.hpp"
#include "core/app.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

namespace riru::core
{
    window::window(uint32_t width, uint32_t height, std::string_view title)
        : width(width) 
        , height(height)
        , title(title)
        , handle(nullptr)
    {
    }

    window::~window()
    {
        if (handle)
        {
            glfwDestroyWindow(handle);
            handle = nullptr;
        }
    }

    window::result window::init()
    {
        if (handle)
        {
            return window::result::window_already_init;
        }

        int glfw_init_result = glfwInit();
        if (glfw_init_result == GLFW_FALSE)
        {
            return window::result::glfw_init_fail;
        }

        glfwSetErrorCallback([](int error, const char* desc)
        {
            std::cout << "GLFW error: (" << error << "): " << desc << "\n";
        });

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        handle = glfwCreateWindow(
            width,
            height,
            title.c_str(),
            nullptr,
            nullptr
        );

        std::cout << "Window created\n";

        if (handle == 0)
        {
            return window::result::window_init_fail;
        }

        // Store a pointer to the wrapper such that we can
        // access it later on in callbacks
        glfwSetWindowUserPointer(handle, this);

        // Handle callbacks
        glfwSetWindowSizeCallback(handle, on_resize);
        glfwSetWindowCloseCallback(handle, on_close);

        return window::result::success;
    }

    void window::update()
    {
        glfwPollEvents();
    }

    void window::on_resize(GLFWwindow* handle, int width, int height)
    {
        auto wrapper = reinterpret_cast<riru::core::window*>(
            glfwGetWindowUserPointer(handle));
        
        wrapper->width = width;
        wrapper->width = height;
    }

    void window::on_close(GLFWwindow* handle)
    {
        app::get().close();
    }
}