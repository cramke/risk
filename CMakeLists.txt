cmake_minimum_required(VERSION 3.0.0)
project(risk VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/usr/include/ompl/
                    /usr/include/eigen3/)
add_executable(risk src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
