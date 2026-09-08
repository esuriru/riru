#pragma once

#include "core/core.hpp"

namespace riru::core
{
    class app
    {
    public:
        app();
        ~app();

        [[maybe_unused]]
        riru::result init();

        [[maybe_unused]]
        riru::result run();

    private:
        bool is_running;
    };
}