/*Ver Archivo LICENSE Para detalles sobre la licencia*/
/*Basado en la Implementación de lista hallada en    */ 
/*https://github.com/TheAlgorithms/C                 */
#ifndef __LISTA__
#define __LISTA__

typedef struct Nodo{
  void *dato;
  struct Nodo *previo;
  struct Nodo *siguiente;
} Nodo;

/*Longitud e indexado*/
signed int largo_lista(Nodo *lista);
void *retornar_de_indice(Nodo *lista, unsigned int indice);
/*Destrucción de nodos y listas, usar para liberar memoria*/
/*ADVERTENCIA: Si se usa un dato sin malloc, borrar_dato debe ser NULL*/
void destruir_lista(Nodo *lista, void(*borrar_dato)(void *));
void destruir_nodo(Nodo *nodo, void(*borrar_dato)(void *));
/*Creación y expansión de una lista*/
/*ADVERTENCIA: La actualización de la cabeza es responsabilidad del usuario*/
Nodo *crear_lista(void);
Nodo *empujar_nodo(Nodo *lista, void *valor);
Nodo *agregar_nodo(Nodo *lista, void *valor);
Nodo *insertar_nodo(Nodo *lista, void *valor, unsigned int indice);
/*Remoción de datos de la lista, los retorna sin destruirlos*/
/*Primero y ultimo son un poco más rápidos (y ad hoc)*/
Nodo *remover_nodo(Nodo *lista, unsigned int indice);
Nodo *remover_primero(Nodo *lista);
Nodo *remover_ultimo(Nodo *lista);
#endif
