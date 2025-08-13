# Microbloq
Microbloq es un sucesor espiritual de minibloq, creado por Robotgroup, dado el
estado del repositorio original, se decidió iniciar de vuelta, con un enfoque
de desarrollo más transparente

## Estilo de código
Para establecer un entorno de trabajo sano, se decidió apegarse a la filosofia
de desarrollo [Suckless](https://suckless.org/coding_style/), complementando
con el uso de la herramienta [Doxygen](https://doxygen.nl). Asimismo, se
solicita que las contribuciones incluyan comentarios y variables en la lengua
española.

## Esquema de directorios
```
minibloq/
├── include/                # Archivos de cabecera públicos (.h)
│   ├── parser.h            # Parser de la app
│   ├── lista.h             # Definición de lista genérica
│   └── xxxxxx.h
├── src/                    # Código fuente de los módulos (.c)
│   ├── CMakeLists.txt      # CMake para compilar la librería estática
│   ├── parser.c            # Parser de la app
│   ├── lista.c             # Implementación de lista genérica
│   └── xxxxxx.c
├── main/                   # Código fuente del programa principal
│   ├── CMakeLists.txt      # CMake para compilar el ejecutable
│   ├── main.c              # Código fuente de la app
│   └── main.h              # Header de la app
├── CMakeLists.txt          # CMake raíz que orquesta todo
├── LICENSE
└── README.md
```
