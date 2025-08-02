cmake_minimum_required(VERSION 3.10)

# Nome do projeto e configurações básicas
project(Vector VERSION 1.0 LANGUAGES CXX)

# Define o padrão C++ (C++11 ou superior)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define o diretório de saída para os binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/build)

# Cria uma biblioteca de interface (header-only)
add_library(vector INTERFACE)
target_include_directories(vector INTERFACE ${CMAKE_SOURCE_DIR}/include)

# Instalação
install(FILES include/vector.hpp DESTINATION include/vector)