# Ejecutable principal
add_executable(microbloq_bin
    ${PROJECT_SOURCE_DIR}/main/main.c
)

# Enlazar con la librería
target_link_libraries(microbloq_bin PRIVATE microbloq)

# Incluir headers
target_include_directories(microbloq_bin PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Instalación multiplataforma del binario
install(TARGETS microbloq_bin
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # Windows + Unix binarios
)
