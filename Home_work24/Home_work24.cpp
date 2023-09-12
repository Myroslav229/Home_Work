#include <iostream>
#include"Vector2d.h"
#include"Vector3d.h"
int main()
{
    Vector2D vec1(-1,-1);
    Vector2D vec2(1, 1);
   /* Vector3D a(2, 3, 3);
    Vector3D b(1, 4, 1);
    std::cout << a.crossProduct(b);*/
    std::cout << "jopa " << (int)vec1.getRelativeState(vec2);
}

