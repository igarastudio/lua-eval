# This file is released into the public domain.
# Read LICENSE.txt for more information.

cmake_minimum_required(VERSION 3.16)

# lua
include(FetchContent)
FetchContent_Declare(lua
  GIT_REPOSITORY https://github.com/igarastudio/lua.git
  GIT_TAG        cmake)
FetchContent_MakeAvailable(lua)
FetchContent_GetProperties(lua SOURCE_DIR lua_src_dir)

# lua-eval
project(lua-eval C)

add_executable(lua-eval main.c)
target_link_libraries(lua-eval lua lualib lauxlib)
target_include_directories(lua-eval PRIVATE . ${lua_src_dir})
