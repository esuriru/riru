#include <iostream>

#include "riru.hpp"

int main()
{
    riru::core::app app;

    auto init_result = app.init();
    if (init_result != riru::result::success)
    {
        return 1;
    }
    app.run();
}