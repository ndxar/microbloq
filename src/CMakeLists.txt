#Archivos fuente de nuestras lobrerias
set(LIB_SOURCES
  ${PROJECT_SOURCE_DIR}/src/parser.c
  ${PROJECT_SOURCE_DIR}/src/lista.c
  #Con este formato hay que agregar los otros .c
)

#Creación de las librerias estaticas
add_library(microbloq STATIC ${LIB_SOURCES})

#Headers del proyexto
target_include_directories(microbloq PUBLIC $(PROJECT_SOURCE_DIR)/include)

#Configuración para multiplataforma
install(TARGETS microbloq
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} #.a para unix, .lib para windows
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} #.so en unix para linkeo compartido
  LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR} #.dll en windows para linkeo compartido
)

#Agregamos los headers en include
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
