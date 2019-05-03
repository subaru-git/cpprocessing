cmake_minimum_required(VERSION 3.5)


# project setting
set(project test)
project(${project})

# build options
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_STANDARD 17)

# source files
include_directories(/usr/local/include)
include_directories(lib)
set(SOURCE_FILES  ${SOURCE_FILES} src/*.cpp)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_FILES})

# libraries
add_subdirectory(lib)
link_directories(/usr/local/lib)
set(LIBRARIES ${LIBRARIES} cpprocessing)

add_executable(${project} ${SOURCE_FILES})
target_link_libraries(${project} ${LIBRARIES})

# custom commands
add_custom_target(run
        COMMAND ${project}
        DEPENDS ${project}
        )