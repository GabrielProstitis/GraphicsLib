#pragma once
#include <stdexcept>
#include <iostream>

#define LOGBREAK(Description)                                                        \
    std::cout << "\nError in " << __FILE__ << ":" << __LINE__ << " " << Description; \
    __debugbreak()

#define LOGWARNING(Description) \
    std::cout << "[WARNING]" << __FILE__ << ":" << __LINE__ << " " << Description;
