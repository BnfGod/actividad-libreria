#include "Lista.h"

Lista::Lista()
{
    cont = 0;
}

void Lista::insertaPos(Libro l, int pos)
{
    if(llena())
        throw "Lista llena";
    if(pos > cont || pos < 0)
        throw "Posicion invalida";
    for(int i = cont; i > pos; i--)
    {
        libros[i] = libros[i-1];
    }

    libros[pos] = l;
    cont++;
}

void Lista::insertaAlInicio(Libro l)
{
    insertaPos(l,0);
}

void Lista::insertaAlFinal(Libro l)
{
    insertaPos(l,cont);
}

void Lista::eliminaPos(int pos)
{
    if(vacia())
        throw "Error: Lista vacia"; //Se puede simplificar unicamente con la segunda validacion si se requiere
    if(pos >= cont || pos < 0)
        throw "Error: Posicion invalida";
    for(int i = pos; i < cont-1 ; i++)
    {
        libros[i] = libros[i+1];
    }
    cont--;
}

void Lista::eliminaAlInicio()
{
    eliminaPos(0);
}

void Lista::eliminaAlFinal()
{
    eliminaPos(cont-1);
}

bool Lista::llena()
{
    return cont == 100; //Lista de 100 libros
}

bool Lista::vacia()
{
    return cont == 0;
}

int Lista::getCont()
{
    return cont;
}

Libro& Lista::recupera(int pos)
{
    if(pos < 0 || pos >= cont)
        throw "Posicion invalida";
    return libros[pos];
}
