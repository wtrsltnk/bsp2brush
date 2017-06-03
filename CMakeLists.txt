cmake_minimum_required(VERSION 3.3)

project(bsp2brush)

option(BUILD_TESTS "Build test programs" OFF)

include(win-cpp-deps.cmake/win-cpp-deps.cmake)

install_dep("https://bitbucket.org/wincppdeps/glm.git")

find_package(GLM REQUIRED)
find_package(GLEXTL REQUIRED)
find_package(OpenGL REQUIRED)

set(FILES
    program.cpp
    glextl.cpp
    )

add_subdirectory(libs/game-assets)

add_executable(bsp2brush ${FILES})

target_include_directories(bsp2brush
    PRIVATE ${GLM_INCLUDE_DIR}
    PRIVATE ${GLEXTL_INCLUDE_DIR}
    PRIVATE "${CMAKE_SOURCE_DIR}/libs/game-assets/include"
    )

target_compile_features(bsp2brush
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(bsp2brush
    game-assets
    ${OPENGL_LIBRARIES}
    )

#target_compile_definitions(bsp2brush
#    )

if(BUILD_TESTS)

    add_executable(all-tests
        tests/catch.hpp
        tests/test-base.cpp
        )

    target_include_directories(all-tests
        PRIVATE ${GLM_INCLUDE_DIR}
        PRIVATE "${CMAKE_SOURCE_DIR}/libs/game-assets/include"
        )

    target_compile_features(all-tests
        PRIVATE cxx_auto_type
        PRIVATE cxx_nullptr
        PRIVATE cxx_range_for
        )

    target_link_libraries(all-tests
        game-assets
    )

endif(BUILD_TESTS)
