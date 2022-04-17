cmake_minimum_required(VERSION 3.16)

project(QSC CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include(external_qpp.cmake)

ExternalProject_Get_property(qpp INSTALL_DIR)
set(QPP_INCLUDE_DIR ${INSTALL_DIR}/include)
message("Quantum++ installation path: ${INSTALL_DIR}")

include(external_systemc.cmake)

ExternalProject_Get_property(systemc INSTALL_DIR)
set(SYSTEMC_LIB_DIR ${INSTALL_DIR}/lib)
set(SYSTEMC_INCLUDE_DIR ${INSTALL_DIR}/include)
message("SystemC installation path: ${INSTALL_DIR}")

include_directories(${SYSTEMC_INCLUDE_DIR})
include_directories(${QPP_INCLUDE_DIR})

#file(DOWNLOAD
#    https://github.com/CLIUtils/CLI11/releases/download/v1.9.1/CLI11.hpp
#    ${PROJECT_SOURCE_DIR}/lib/CLI11.hpp
#)

include_directories(.)

set(CMAKE_CXX_FLAGS "-O2 -Werror -Wall -Wextra -Weffc++ -fpic -pipe -march=native -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g -flto")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -DNDEBUG -DEIGEN_NO_DEBUG")

# Install inside the build directory.
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Do not strip RPATH during installation
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_BINARY_DIR}/systemc_dir/lib")


enable_testing()

#add_subdirectory(sim)
add_subdirectory(test)
#add_subdirectory(doc)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")