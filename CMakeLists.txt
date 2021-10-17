cmake_minimum_required(VERSION 3.0.0)
project(TestProject VERSION 0.1.0)

include(${PROJECT_SOURCE_DIR}/CMakeFunctions.cmake)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib)


set(PROJECT_SRC_FILES
    main.cpp
)
add_executable(${PROJECT_NAME} ${PROJECT_SRC_FILES})


set(PROJECT_LIBS
    glfw
    glad
    glm
    # SDL
    # SDL2-static
    # imgui # currently not working
)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_LIBS})
