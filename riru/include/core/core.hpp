#pragma once

#include <cstdint>

// For future API use (if moving to dynamic build)
#define RR_API

namespace riru
{
    enum class result : uint8_t
    {
        success = 0,
    };
};