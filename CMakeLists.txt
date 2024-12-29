cmake_minimum_required(VERSION 3.29)
project(Owl_Server)

set(CMAKE_CXX_STANDARD 17)

# pthread 라이브러리 추가

add_executable(Owl_Server main.cpp
        boot/dotenv.cpp
        boot/dotenv.h
        boot/boot.cpp
        boot/boot.h
        )
