include(ExternalProject)

ExternalProject_Add(systemc
    PREFIX systemc_dir
    GIT_REPOSITORY https://github.com/accellera-official/systemc
    GIT_SHALLOW TRUE
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/systemc_dir -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD} -DDISABLE_COPYRIGHT_MESSAGE=1
    BUILD_COMMAND make -j
    UPDATE_COMMAND ""
)
