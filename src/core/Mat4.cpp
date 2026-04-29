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

float Mat4::det2x2(float a, float b, float c, float d) const {
    float det = (a*d) - (b*c);
    return det;
}

float Mat4::det3x3(float a[3][3]) const {
    float det1, det2, det3;
    det1 = a[0][0] * det2x2(a[1][1], a[1][2], a[2][1], a[2][2]);
    det2 = a[0][1] * det2x2(a[1][0], a[1][2], a[2][0], a[2][2]);
    det3 = a[0][2] * det2x2(a[1][0], a[1][1], a[2][0], a[2][1]);

    float det = det1 - det2 + det3;
    return det;
}

float Mat4::determinant() const {
    float detArray[4];
    for(int i = 0; i < 4; i++){
        float subMat[3][3];
        getSubMatrix(0, i, subMat);
        detArray[i] = m[0][i] * det3x3(subMat);
    }

    float det = detArray[0] - detArray[1] + detArray[2] - detArray[3];
    return det;
}

void Mat4::getSubMatrix(int skipRow, int skipCol, float out[3][3]) const {
    int row = 0;
    for(int i = 0 ; i < 4; i++){
        if(i == skipRow) continue;
        int col = 0;
        for(int j = 0; j < 4; j++){
            if(j == skipCol) continue;
            out[row][col] = m[i][j];
            col++;
        }
        row++;
    }
}

Mat4 Mat4::inverse() const {
    float det = determinant();
    if(std::abs(det) < 1e-6f){
        throw std::invalid_argument("Determinant of matrix is 0");
    }

    Mat4 coFactor;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            float subMat[3][3]; 
            getSubMatrix(i, j, subMat);
            float sign = (i+j) % 2 == 0 ? 1.0f : -1.0f;
            coFactor.m[i][j] = sign * det3x3(subMat);
        }
    }

    Mat4 tran = coFactor.transpose();

    Mat4 inv = tran * (1/det);

    return inv;
}