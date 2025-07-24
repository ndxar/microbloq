cmake_minimum_required (VERSION 3.15)
#nombre del proyecto
project(microbloq VERSION 0.01 LANGUAGES C)

#Fijamos el standard a C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

#Rutas para GNU/Linux
include(GNUInstallDirs)

#Incluimos los headers
include_directories(${PROJECT_SOURCE_DIR}/include)

#Subdirectorios, para el fuente de nuestras libs y el programa
add_subdirectory(src)
add_subdirectory(main)
