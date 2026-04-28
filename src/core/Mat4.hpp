#pragma once
#include <string>

class Mat4 {
public:
    Mat4() {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i == j){
                    m[i][j] = 1;
                } else {
                    m[i][j] = 0;
                }
            }
        }
    }

    Mat4 operator*(const Mat4& other) const;
    Mat4 operator*(const float& scalar) const;

    Mat4 transpose() const;
    Mat4 inverse() const;

    std::string toString() const;
    void print() const;

    static Mat4 identity();
    static Mat4 translation(float x, float y, float z);
    static Mat4 scale(float x, float y, float z);
    static Mat4 rotationX(float angle);
    static Mat4 rotationY(float angle);
    static Mat4 rotationZ(float angle);

private:

    Mat4(float src[4][4]);
    float determinant() const;

    float m[4][4];
};