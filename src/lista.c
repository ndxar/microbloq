/*Ver Archivo LICENSE Para detalles sobre la licencia*/
/*Basado en la Implementación de lista hallada en    */ 
/*https://github.com/TheAlgorithms/C                 */
#include <stdlib.h>

#include "lista.h"

/*Retorna la longitud de una lista, o 0 si está vacía*/ 
signed int 
largo_lista(Nodo *lista)
{
  signed int largo = 0;
  if (!lista) 
    return 0;
  while (lista->previo)
    lista = lista->previo;
  while (lista){
    largo++;
    lista = lista->siguiente;
  }
  return largo;
}
/*Retorna el dato del indice indicado, NULL si está vacía*/
void *
retornar_de_indice(Nodo *lista, unsigned int indice)
{
  Nodo *lista = lista;
  if (!lista) 
    return NULL;
  while (lista->previo)
    lista = lista->previo;
  for (unsigned int i = 0; i < indice && lista; i++)
    lista = lista->siguiente;
  if (!lista) 
    return NULL;
  return lista->dato;
}
/*destrucción de listas*/
void 
destruir_lista(Nodo *lista, void(*borrar_dato)(void *))
{
  if (!lista)
    return;
  while (lista->previo)
    lista = lista->previo;
  while (lista->siguiente){
    Nodo *siguiente = lista->siguiente;
    destruir_nodo(lista, borrar_dato);
    lista = siguiente;
  }
  destruir_nodo(lista, borrar_dato);
}
/*destrucción de nodos*/
void 
destruir_nodo(Nodo *nodo, void(*borrar_dato)(void *))
{
  if (!nodo)
    return;
  if (borrar_dato && nodo->dato)
    borrar_dato(nodo->dato);
  free(nodo);
}
/*Creación de lista Vacía*/
Nodo * 
crear_lista(void)
{
  Nodo *n = malloc(sizeof(Nodo));
  if (!n)
    return NULL;
  *n = (Nodo){0};
  return n;
}
/*Inserción de nodo al inicio de la lista*/
Nodo *
empujar_nodo(Nodo *lista, void *valor)
{
  Nodo *n = malloc(sizeof(Nodo));
  if (!n)
    return NULL;
  *n = (Nodo){0};
  while (lista->previo)
    lista = lista->previo;
  n->dato = valor;
  n->siguiente = lista;
  if (lista)
    lista->previo = n;
  return n;
}
/*Inserción de nodo al final de la lista*/
Nodo *
agregar_nodo(Nodo *lista, void *valor)
{
  Nodo *n = malloc(sizeof(Nodo));
  if (!n)
    return NULL;
  *n = (Nodo){0};
  n->dato = valor;
  if (!lista)
    return n;
  while (lista->siguiente)
    lista = lista->siguiente;
  n->previo = lista;
  lista->siguiente = n;
  return n;
}
/*Inserción de nodo en un indice dado, retorna NULL si el indice > largo*/
Nodo *
insertar_nodo(Nodo *lista, void *valor, unsigned int indice)
{
  unsigned int i = 0;
  Nodo *n = malloc(sizeof(Nodo));
  if (!n)
      return NULL;
  *n = (Nodo){0};
  n->dato = valor;
  if (!lista)
    return n;
  while (lista->previo)
    lista = lista->previo;
  if (indice == 0){
    n->siguiente = lista;
    lista->previo = n;
    return n;
  }
  while (i < indice - 1 && lista->siguiente){
    lista = lista->siguiente;
    i++;
  }
  if (i < indice - 1)
    return NULL;
  n->siguiente = lista->siguiente;
  if (lista->siguiente)
    lista->siguiente->previo = n;
  n->previo = lista;
  lista->siguiente = n;
  while (lista->previo)
      lista = lista->previo;
  return lista;
}
/*Remoción de un nodo dado un indice, retorna NULL si el indice > largo*/
Nodo *
remover_nodo(Nodo *lista, unsigned int indice)
{
  unsigned int i = 0;
  if (!lista)
    return NULL;
  while (lista->previo)
    lista = lista->previo;
  while (i < indice && lista->siguiente){
    lista = lista->siguiente;
    i++;
  }
  if (i != indice)
    return NULL;
  if (lista->previo)
    lista->previo->siguiente = lista->siguiente;
  if (lista->siguiente)
    lista->siguiente->previo = lista->previo;
  lista->previo = NULL;
  lista->siguiente = NULL;
  return lista;
}
Nodo *
remover_primero(Nodo *lista)
{
}
Nodo *
remover_ultimo(Nodo *lista)
{
}
