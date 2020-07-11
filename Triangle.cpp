//
// Created by Edge on 2020/7/9.
//

#include "Triangle.h"

bool Triangle::isHit(Ray &ray) {
    Velocity planeVector[2] = {m_point[1] - m_point[0], m_point[2] - m_point[0]};
    // | v1.x v2.x vr.x | | t1 |   | xr.x - x0.x |
    // | v1.y v2.y vr.y | | t2 | = | xr.y - x0.y |
    // | v1.z v2.z vr.z | |-tr |   | xr.z - x0.z |
    float A[3][3] = {
            {planeVector[0].x, planeVector[1].x, ray.velocity.x},
            {planeVector[0].y, planeVector[1].y, ray.velocity.y},
            {planeVector[0].z, planeVector[1].z, ray.velocity.z}
    };
    float b[3] = {
            ray.origin.x - m_point[0].x,
            ray.origin.y - m_point[0].y,
            ray.origin.z - m_point[0].z,
    };
    // entry forward
    for (int i = 0; i < 3; ++i) {
        if (fabs(A[i][i]) < 1e-10) {
            for (int j = i + 1; j < 3; ++j) {
                if (fabs(A[j][i]) >= 1e-10) {
                    for (int k = 0; k < 3; ++k) {
                        float buf = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = buf;
                    }
                    float buf = b[i];
                    b[i] = b[j];
                    b[j] = buf;
                    break;
                }
            }
        }
    }
    // forward pass
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            float quotient = A[j][i] / A[i][i];
            for (int k = j; k < 3; ++k) {
                A[j][k] -= quotient * A[i][k];
            }
            b[j] -= quotient * b[i];
            A[j][i] = 0.0f;
        }
    }
    // backward pass
    for (int i = 3 - 1; i >= 0; --i) {
        if(fabs(A[i][i]) < 1e-10 && b[i] >= 1e-10) {
            // No solution, triangle is parallel to ray
            return false;
        }
        for (int j = i - 1; j >= 0; --j) {
            b[j] -= A[j][i] / A[i][i] * b[i];
            A[j][i] = 0.0f;
        }
        b[i] /= A[i][i];
        A[i][i] = 1.0f;
    }
//    float t1 = b[0], t2 = b[1], tr = -b[2];
    return b[0] >= 0.0f && b[1] >= 0.0f && (b[0] + b[1] <= 1.0f);
}