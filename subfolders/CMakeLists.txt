cmake_minimum_required(VERSION 3.20)

project(subfolders VERSION 1.2.3)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(CMAKE_PROJECT_NAME="${CMAKE_PROJECT_NAME}")
add_compile_definitions(CMAKE_PROJECT_VERSION="${PROJECT_VERSION}")


set(TARGET_NAME "${CMAKE_PROJECT_NAME}")
add_executable(${TARGET_NAME})



add_subdirectory(main)
add_subdirectory(drivers)


# enable unused variable warning for all sources:
# target_compile_options(${TARGET_NAME} PRIVATE "-Wunused-variable")

# enable unused variable warning only for flags.c:
# set_source_files_properties(flags.c PROPERTIES COMPILE_OPTIONS "-Wunused-variable")