#pragma once
#include <stdexcept>
#include <iostream>

#define GiveException(Description)\
std::cout << "\nError in " << __FILE__ <<":"<< __LINE__ <<  " "<< Description;\
__debugbreak()

