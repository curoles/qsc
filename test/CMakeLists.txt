

set(tests
    minimal
)

foreach(test_name IN LISTS tests)

    set(test_file ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.cpp)

    add_executable(${test_name} ${test_file})
    add_dependencies(${test_name} systemc qpp)
    target_link_libraries(${test_name} Eigen3::Eigen)
    target_link_libraries(${test_name} ${SYSTEMC_LIB_DIR}/libsystemc.so)

    add_test(NAME ${test_name}
        COMMAND ${test_name}
    )

endforeach()