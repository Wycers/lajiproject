cmake_minimum_required(VERSION 3.16)

project(untitled5)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/node)
include_directories(${CMAKE_SOURCE_DIR}/src/error)
include_directories(${CMAKE_SOURCE_DIR}/src/ir)
include_directories(${CMAKE_SOURCE_DIR}/src/symbol_table)
include_directories(${CMAKE_SOURCE_DIR}/src/semantic_analysis)
include_directories(${CMAKE_CURRENT_BINARY_DIR})


add_executable(splc
        main.cpp
        ./src/error/error.cpp
        ./src/node/node.cpp
        ./src/ir/ir.hpp
        ./src/semantic_analysis/semantic_analysis.hpp
        src/semantic_analysis/program.hpp
        src/semantic_analysis/ext_def_list.hpp
        src/semantic_analysis/ext_def.hpp
        src/semantic_analysis/basic.hpp
        src/semantic_analysis/specifier.cpp
        src/semantic_analysis/var_dec.hpp
        src/semantic_analysis/struct_specifier.hpp
        src/semantic_analysis/dec.hpp
        src/semantic_analysis/exp.cpp
        src/semantic_analysis/def.hpp
        src/semantic_analysis/dec_list.cpp
        src/semantic_analysis/def_list.cpp
        src/semantic_analysis/args.hpp
        src/semantic_analysis/stmt.hpp
        src/semantic_analysis/stmt_list.hpp
        src/semantic_analysis/ext_dec_list.hpp
        src/semantic_analysis/param_dec.hpp
        src/semantic_analysis/var_list.hpp
        src/semantic_analysis/fun_dec.hpp
        src/semantic_analysis/base.hpp)