include(FetchContent)
include(ExternalProject)

option(LINK_DEPS_STATIC CACHE ON)

# Don't build shared libs if we want to link to deps statically
if(LINK_DEPS_STATIC)
  set(BUILD_SHARED_LIBS OFF)
else()
  set(BUILD_SHARED_LIBS ON)
endif()

# GLFW ==============================================================
FetchContent_Declare(
  glfw
  GIT_REPOSITORY "https://github.com/glfw/glfw"
  GIT_TAG        "3.3.4"
)

option(GLFW_INSTALL "Generate installation target" OFF)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# SDL ===============================================================
FetchContent_Declare(
  SDL
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL"
  GIT_TAG        "release-2.0.14"
)

# SDL
if (LINK_DEPS_STATIC)
  set(SDL_STATIC ON CACHE BOOL "Build SDL2 as shared lib")
else()
  set(SDL_SHARED ON CACHE BOOL "Build SDL2 as shared lib")
endif()

FetchContent_MakeAvailable(SDL)

# Define alias for what we used
if (LINK_DEPS_STATIC)
  add_library(SDL2::SDL2 ALIAS SDL2-static)
else()
  add_library(SDL2::SDL2 ALIAS SDL2)
endif()

# imgui ============================================================= # not working
# FetchContent_Declare(
#   imgui
#   GIT_REPOSITORY "https://github.com/ocornut/imgui"
#   GIT_TAG "v1.85"
#   SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib/imgui"
# )

# FetchContent_MakeAvailable(imgui)

ExternalProject_Add(
  imgui
    GIT_REPOSITORY "https://github.com/ocornut/imgui"
    GIT_TAG "v1.85"
)


# glad ==============================================================
FetchContent_Declare(
  glad

  GIT_REPOSITORY "https://github.com/Dav1dde/glad.git"
  GIT_TAG        "v0.1.27"
)

FetchContent_MakeAvailable(glad)

# FetchContent_GetProperties(extern_glad)
# if(NOT extern_glad_POPULATED)
#   FetchContent_Populate(extern_glad)
#   set(GLAD_INSTALL ON)
#   add_subdirectory(
#     ${extern_glad_SOURCE_DIR}
#     ${extern_glad_BINARY_DIR}
#     EXCLUDE_FROM_ALL)
# endif()

# glm ===============================================================
FetchContent_Declare(
  glm

  GIT_REPOSITORY "https://github.com/g-truc/glm"
  GIT_TAG        bf71a834948186f4097caa076cd2663c69a10e1e # GLM 0.9.9.8
)

FetchContent_MakeAvailable(glm)
