cmake_minimum_required(VERSION 3.20)

# set the project name
project(basic VERSION 1.2.3)

set(CMAKE_C_STANDARD 17)

add_compile_definitions(CMAKE_PROJECT_NAME="${CMAKE_PROJECT_NAME}")
add_compile_definitions(CMAKE_PROJECT_VERSION="${PROJECT_VERSION}")



# add_compile_options(
# "-m32"
# )

# add_link_options(
#     "-m32"
# )

set(CMAKE_C_FLAGS "-m32")


# add the executable
add_executable(32bit main.c)
