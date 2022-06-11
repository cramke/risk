cmake_minimum_required(VERSION 3.0.0)
project(risk VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/usr/include/ompl/
                    /usr/include/eigen3/
                    /usr/include/pqxx/)

add_executable(risk src/main.cpp)
TARGET_LINK_LIBRARIES(risk -lpqxx -lpq)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)

include(CPack)

