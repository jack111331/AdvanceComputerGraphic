//
// Created by Edge on 2020/7/8.
//

#include "Scene.h"
#include "Material.h"
#include "HittableList.h"

Color Scene::castRay(Ray &ray, double intensity, int depth) {
    if (intensity < 1e-6 || depth > 50) {
        return {0.0, 0.0, 0.0};
    }
    HitRecord record;
    record.t = -1.0;
    if (m_hittableList->isHit(0.001, ray, record)) {
        if (record.material->m_constantReflectionRatio < 1e-6) {
            LightRecord lightRecord;
            for (auto light: m_lightList) {
                HitRecord testRecord;
                testRecord.t = -1.0;
                Ray testRay = {record.point, light->m_origin - record.point};
                lightRecord.addShadedLight(!m_hittableList->isHit(0.001, testRay, testRecord));
            }
            Color objectColor = record.material->calculatePhong(this, ray, record, lightRecord);
            return objectColor;
        } else {
            LightRecord lightRecord;
            for (auto light: m_lightList) {
                HitRecord testRecord;
                testRecord.t = -1.0;
                Ray testRay = {record.point, light->m_origin - record.point};
                lightRecord.addShadedLight(!m_hittableList->isHit(0.001, testRay, testRecord));
            }
            Color calculateColor = record.material->calculatePhong(this, ray, record, lightRecord);
            ray = {record.point, ray.velocity.reflect(record.normal)};
            const Color &castedColor = castRay(ray, intensity * record.material->m_constantReflectionRatio, depth + 1);
            return (1.0 - record.material->m_constantReflectionRatio) * calculateColor +
                   record.material->m_constantReflectionRatio *
                   castedColor;
        }
    }
    return {0.0, 0.0, 0.0};
}

void Scene::displayScene() {
    if (!m_camera) {
        return;
    }
    // Upper left start
    // Lower right end
    Velocity left = m_camera->m_direction.cross(m_camera->m_up);
    const double PI = acos(-1);
    Coord center = m_camera->m_eyeCoord + m_camera->m_direction.normalize();
    double widthFactor = tan(m_camera->m_fov / 180.0 * PI);
    double heightFactor = widthFactor * m_camera->m_height / m_camera->m_width;
    Coord leftUpper = center + widthFactor * left.normalize() + heightFactor * m_camera->m_up.normalize();
    for (int i = 0; i < m_camera->m_height; ++i) {
        for (int j = 0; j < m_camera->m_width; ++j) {
            Coord currentRayOnScreen =
                    leftUpper - (double) j / (double) (m_camera->m_width - 1) * 2.0 * widthFactor * left.normalize() -
                    (double) i / (double) (m_camera->m_height - 1) * 2.0 * heightFactor * m_camera->m_up.normalize();
            Ray ray = {
                    m_camera->m_eyeCoord,
                    currentRayOnScreen - m_camera->m_eyeCoord
            };
//            std::cout << currentRayOnScreen.x << " " << currentRayOnScreen.y << " " << currentRayOnScreen.z
//                      << std::endl;
            m_camera->m_screen[i][j] = castRay(ray, 1.0, 0);

        }
    }
}
