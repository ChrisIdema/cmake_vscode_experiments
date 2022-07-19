cmake_minimum_required(VERSION 3.20)

# target_sources(${TARGET_NAME} PRIVATE 
#     util/util.cpp
#     driver_c.c
# )

# target_include_directories(${TARGET_NAME} PUBLIC "util")
# target_include_directories(${TARGET_NAME} PUBLIC  "inc")

# compile as library to demonstrate private includes:

add_library(drivers STATIC 
    driver_c.c
    util/util.cpp
)

# allow users to include using: "driver_inc.h" instead of "drivers/inc/driver_inc.h":
# target_include_directories(drivers PUBLIC "inc") 

#private includes:
target_include_directories(drivers PRIVATE "util")
target_include_directories(drivers PRIVATE "inc")

# enable unused variable warning for all sources:
# target_compile_options(drivers PRIVATE "-Wunused-variable")

# enable unused variable warning only for some sources:
set_source_files_properties(driver_c.c PROPERTIES COMPILE_OPTIONS "-Wunused-variable")

target_link_libraries(${TARGET_NAME} drivers)
