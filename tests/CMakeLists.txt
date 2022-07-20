cmake_minimum_required(VERSION 3.20)

project(tests VERSION 0.0.0)


set(BINARY_BASE_NAME ${PROJECT_NAME})


set(TARGET_NAME ${BINARY_BASE_NAME}_test)
if(UNIX)
    set(TARGET_NAME ${TARGET_NAME}.exe)
    # Why this 'strange idea'? Because to have the test extension working properly, we need to specify the test executable name (in settings.json).
    # But by default CMake adds '.exe' to the binary name. So we add it also for Linux, to have the same binary.
    # I know it is strange, but that's the best I can think of right now.
endif(UNIX)

enable_language(C CXX ASM)

add_executable(${TARGET_NAME})

add_subdirectory(tests)