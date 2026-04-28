#include "Mat4.hpp"
#include <iostream>
#include <sstream>

Mat4::Mat4(float src[4][4]){
    std::memcpy(m, src, sizeof(m));
}

Mat4 Mat4::identity() {
    return Mat4();
}

Mat4 Mat4::transpose() const {
    float tran[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            tran[j][i] = m[i][j];
        }
    }

    return Mat4(tran);
}

Mat4 Mat4::operator*(const Mat4& other) const {
    float prod[4][4];
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            float sum = 0;
            for(int j = 0; j < 4; j++){
                sum = sum + (m[i][j] * other.m[j][k]);
            }
            prod[i][k] = sum;
        }
    }

    return Mat4(prod);
}

Mat4 Mat4::operator*(const float& other) const {
    float prod[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            prod[i][j] = m[i][j] * other;
        }
    }

    return Mat4(prod);
}

std::string Mat4::toString() const {
    std::stringstream ss;

    for(int i = 0; i < 4; i++) {
        ss << "| ";
        for(int j = 0; j < 4; j++) {
            ss << m[i][j] << " ";
        }
        ss <<"|\n";
    }

    return ss.str();
}

void Mat4::print() const {
    std::cout << toString() << std::endl;
}