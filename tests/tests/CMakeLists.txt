enable_language(C CXX ASM)


set_target_properties(${TARGET_NAME} PROPERTIES  CMAKE_CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES  CMAKE_CXX_EXTENSIONS ON)  # Switch between '-std=gnu11' and '-std=c11'


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# No need to have CTest integration at the moment
target_sources(
    ${TARGET_NAME}
    PRIVATE example_test.cpp)

target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    gtest
    gmock
    gtest_main
)

add_custom_target(run_tests
    COMMAND ${TARGET_NAME}
)

target_compile_options(${TARGET_NAME} PRIVATE
                       $<$<COMPILE_LANG_AND_ID:C,GNU>:
                       -Wno-pointer-to-int-cast>    # we are testing on 64 bit architecture, so we cannot cast pointers easily to uint32_t without an error
                    #    -m32
                       -Werror -Wno-error=register  # new versions of gcc complain about 'register' keyword in nrf library
)



if(UNIX)
    target_compile_options(${TARGET_NAME} PRIVATE "--coverage")

    set(DIRECTORIES_TO_INCLUDE_IN_COVERAGE
        -d ${CMAKE_SOURCE_DIR}/
    )

    target_link_libraries(
        ${TARGET_NAME} PRIVATE
        gcov
    )

    add_custom_target(run_coverage
        COMMAND echo "Start of tests"
        COMMAND lcov --directory . --zerocounters
        COMMAND ${TARGET_NAME}
        COMMAND lcov --no-extern ${DIRECTORIES_TO_INCLUDE_IN_COVERAGE}
            --base-directory .
            --directory ${CMAKE_BINARY_DIR}
            --capture
            --output-file eo_test.info
        COMMAND lcov --remove eo_test.info '${CMAKE_BINARY_DIR}/externals/*' -o eo_test.info.filtered
        COMMAND genhtml -o ${CMAKE_BINARY_DIR}/test_coverage -t "EO Test Coverage" --num-spaces 4 eo_test.info
        COMMAND echo "End of tests"
        COMMAND xdg-open ${CMAKE_BINARY_DIR}/test_coverage/index.html
        DEPENDS ${CMAKE_BINARY_DIR}/${TARGET_NAME}
        )
endif()
