cmake_minimum_required(VERSION 3.26)
project(Projeto)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Projeto main.cpp
        stdafx.h
        Student.cpp
        Class.cpp
        LoadFiles.cpp
        Schedule.cpp
        UC.cpp
        UI.cpp
        Restoring.cpp
        Restoring.h)
