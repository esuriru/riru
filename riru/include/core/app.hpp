#pragma once

#include <memory>

#include "core/core.hpp"
#include "core/window.hpp"
#include "gfx/ogl_ctx.hpp"

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

        // Graphics 
        std::unique_ptr<gfx::ogl_ctx> gfx_ctx;
    };
}