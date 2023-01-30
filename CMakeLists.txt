cmake_minimum_required(VERSION 3.0.0)
project(snake_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(
                    ${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/src
                    )

                    
file(GLOB ALL_SRCS
                    "${PROJECT_SOURCE_DIR}/include/*.h"
                    "${PROJECT_SOURCE_DIR}/src/*.cpp"
                    )
            
add_executable(snake_cpp ${ALL_SRCS})