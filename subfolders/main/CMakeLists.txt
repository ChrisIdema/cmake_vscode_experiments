cmake_minimum_required(VERSION 3.20)

target_include_directories(${TARGET_NAME} PUBLIC  "${CMAKE_SOURCE_DIR}")

target_sources(${TARGET_NAME} PRIVATE 
    main.cpp
)
