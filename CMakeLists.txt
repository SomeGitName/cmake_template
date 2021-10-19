cmake_minimum_required(VERSION 3.0.0)
project(TestProject VERSION 0.1.0)


option(LINK_DEPS_STATIC CACHE ON)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)


set(PROJECT_SRC_FILES
    main.cpp
)
add_executable(${PROJECT_NAME} ${PROJECT_SRC_FILES})


set(PROJECT_LIBS
    glfw
    glad
    glm
    # SDL::SDL

    imgui

    # imgui-sdl
    imgui-glfw
    # imgui-osx
    # imgui-win32
    # imgui-glut
    # imgui-metal
    imgui-opengl3
    # imgui-opengl2
    # imgui-vulkan
    # imgui-dx9
    # imgui-dx10
    # imgui-dx11
    # imgui-dx12

)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_LIBS})
