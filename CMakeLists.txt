cmake_minimum_required(VERSION 3.5...3.18)
project(biomedcpp)

find_package (Python3 COMPONENTS Interpreter Development REQUIRED)

execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(pybind11_DIR ${PYBIND11_CMAKE_DIR})

message(STATUS "Using pybind11 from ${pybind11_DIR}")
find_package(pybind11 REQUIRED)

pybind11_add_module(sectionizer SHARED sectionizer/sectionizer.cpp)

set_target_properties(sectionizer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/__init__.py")
if(NOT EXISTS ${INIT_PY})
    file(WRITE ${INIT_PY} "")
endif()

add_custom_command(TARGET sectionizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:sectionizer>
        ${CMAKE_CURRENT_BINARY_DIR}/sectionizer.pyd
)
