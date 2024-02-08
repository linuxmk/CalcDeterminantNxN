cmake_minimum_required(VERSION 3.5)

project(CalcDeterminantNxN LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CalcDeterminantNxN main.cpp
    matrix.h matrix.cpp)

include(GNUInstallDirs)
install(TARGETS CalcDeterminantNxN
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
