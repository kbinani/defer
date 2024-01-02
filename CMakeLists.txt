cmake_minimum_required(VERSION 3.16)
project(defer LANGUAGES CXX)

add_library(defer INTERFACE include/defer.hpp)
target_include_directories(defer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if ("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  set(BUILD_SHARED_LIBS OFF)

  if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()

  add_subdirectory(test)
endif()
