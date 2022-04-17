include(ExternalProject)

ExternalProject_Add(qpp
    PREFIX qpp_dir
    GIT_REPOSITORY https://github.com/softwareQinc/qpp.git
    GIT_SHALLOW TRUE
    GIT_TAG origin/main
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/qpp_dir -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    BUILD_COMMAND make -j
    UPDATE_COMMAND ""
)
