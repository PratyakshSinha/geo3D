#include <iostream>
#include "core/Vec3.hpp"
#include "core/Mat4.hpp"

int main() {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);

    Vec3 sum = a + b;
    Vec3 cross = a.crossProduct(b);
    float dot = a.dotProduct(b);
    float mag = a.magnitude();
    Vec3 norm = a.normalized();

    std::cout << "Geo3D starting...\n";
    std::cout << "Dot: " << dot << std::endl;
    std::cout << "Magnitude of a: " << mag << std::endl;
    std::cout << "Sum of a and b: " << sum.toString(); 
    std::cout << "Cross: " << cross.toString();
    std::cout << "a Normalized is: " << norm.toString();

    Mat4 identity;
    identity.print();
    identity = identity * 4;
    identity.print();

    float src[4][4] = {
        {2, 0, 0, 0},
        {0, 3, 0, 0},
        {0, 0, 4, 0},
        {0, 0, 0, 1}};
    
    Mat4 mat(src);
    Mat4 inv = mat.inverse();
    Mat4 res = mat*inv;

    std::cout << "Matrix A is: \n" << mat.toString() << std::endl;
    std::cout << "Inverse of A is: \n" << inv.toString() << std::endl;
    std::cout << "A*A^-1 is: \n" << res.toString();

    return 0;
}