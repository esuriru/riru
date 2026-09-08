#include "core/app.hpp"

#include <iostream>

namespace riru::core
{
    app::app()
    {

    }

    app::~app()
    {
        
    }

    riru::result app::init()
    {
        return riru::result::success;
    }

    riru::result app::run()
    {
        is_running = true;
        std::cout << "riru app is running" << std::endl;

        return riru::result::success;
    }
}
