#pragma once
#include "DynamicArray.h"
template <typename T, const std::size_t N> class InplaceArray: public DynamicArray<T>  {
   
public:
    InplaceArray(): DynamicArray<T>(N) {}
};

