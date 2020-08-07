cmake_minimum_required(VERSION 3.16)
project(Advanced_Computer_Graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_LIST)

set(HEADER_LIST)

list(APPEND SOURCE_LIST
        Ray.cpp
        Sphere.cpp
        Hittable.cpp
        Camera.cpp
        Scene.cpp
        Config.cpp
        Triangle.cpp
        Material.cpp
        Light.cpp
        HittableList.cpp
        )
list(APPEND HEADER_LIST
        Ray.h
        Hittable.h
        Sphere.h
        Camera.h
        Scene.h
        Config.h
        Triangle.h
        Material.h
        Light.h
        Hittable.h
        )

add_executable(Advanced_Computer_Graph main.cpp ${HEADER_LIST} ${SOURCE_LIST})