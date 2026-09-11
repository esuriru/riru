#include "core/app.hpp"

#include <iostream>

namespace riru::core
{
    app* app::instance = nullptr;

    app::app()
        : window(nullptr)
    {
    }

    app::~app()
    {
        if (window)
        {
            delete window;
            window = nullptr;
        }
    }

    app& app::get()
    {
        return *instance;
    }

    riru::result app::init()
    {
        if (instance)
        {
            std::cout << "App already created\n";
            return riru::result::failure;
        }
        instance = this;

        window = new class window(1280, 720, "test");
        if (!window)
        {
            std::cout << "Failed to create window\n";
            return riru::result::failure;
        }

        window->init();

        return riru::result::success;
    }

    riru::result app::run()
    {
        is_running = true;
        std::cout << "riru app is running" << std::endl;

        while (is_running)
        {
            window->update();
        }

        return riru::result::success;
    }

    void app::close()
    {
        is_running = false;
    }
}
