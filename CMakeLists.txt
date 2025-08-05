cmake_minimum_required(VERSION 3.10)
project(SFML-3.0-Boilerplate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# Gather all .cpp files from src/
file(GLOB_RECURSE SOURCES "src/*.cpp")


# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include headers from /include
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

