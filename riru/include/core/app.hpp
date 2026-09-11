#pragma once

#include "core/core.hpp"
#include "core/window.hpp"

namespace riru::core
{
    class app
    {
    public:
        app();
        ~app();

        static app& get();

        [[maybe_unused]]
        riru::result init();

        [[maybe_unused]]
        riru::result run();

        void close();

    private:
        static app* instance;
        window* window;

        bool is_running;
    };
}