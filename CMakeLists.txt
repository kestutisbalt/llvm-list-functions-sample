cmake_minimum_required(VERSION 2.8.8)

project("llvm_list_functions_sample")

set(project_executable "llvm_list_functions_sample")
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(src_files ${src_dir}/llvm_list_functions_sample.cpp)

include_directories(${LLVM_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})
add_definitions("-std=c++11 -fno-rtti")

llvm_map_components_to_libnames(llvm_libs support irreader)

add_executable(${project_executable} ${src_files})
target_link_libraries(${project_executable} ${llvm_libs})
