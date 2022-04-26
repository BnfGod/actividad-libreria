#ifndef LISTA_H
#define LISTA_H
#include <Libro.h>

class Lista
{
private:
    Libro libros[100];
    int cont;
public:
    Lista();   
    void insertaPos(Libro l, int pos);
    void insertaAlInicio(Libro l);
    void insertaAlFinal(Libro l);
    void eliminaPos(int pos);
    void eliminaAlInicio();
    void eliminaAlFinal();
    bool llena();
    bool vacia();
    int getCont();
    Libro& recupera(int pos);
};

#endif // LISTA_H
