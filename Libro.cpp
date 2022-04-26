#include "Libro.h"

Libro::Libro()
{

}

Libro::Libro(string nombre, string autor, string editorial, string ISBN, string categoria,
             string categoria_sec, int precio, int ejemp_disp)
{
    this->nombre = nombre;
    this->autor = autor;
    this->editorial = editorial;
    this->ISBN = ISBN;
    this->categoria = categoria;
    this->categoria_sec = categoria_sec;
    this->precio = precio;
    this->ejemp_disp = ejemp_disp;
    this->ejemp_vend = 0;
}

string Libro::toString()
{
    string s;
    s="";
    s += nombre;
    s += ",";
    s += autor;
    s += ",";
    s += editorial;
    s += ",";
    s += ISBN;
    s += ",";
    s += categoria;
    s += ",";
    s += categoria_sec;
    s += ",";
    s += to_string(precio);
    s += ",";
    s += to_string(ejemp_disp);
    s += ",";
    s += to_string(ejemp_vend);
    s += ".";

    return s;
}

string Libro::getISBN()
{
    return ISBN;
}

string Libro::getCategoria()
{
    return categoria;
}

string Libro::getCategoriaSec()
{
    return categoria_sec;
}

int Libro::getPrecio()
{
    return precio;
}

string Libro::getNombre()
{
    return nombre;
}

string Libro::getAutor()
{
    return autor;
}

string Libro::getEditorial()
{
    return editorial;
}

int Libro::getEjempVend()
{
    return ejemp_vend;
}

int Libro::getEjenmpDisp()
{
    return ejemp_disp;
}

void Libro::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Libro::setAutor(string autor)
{
    this->autor = autor;
}

void Libro::setEditorial(string editorial)
{
    this->editorial = editorial;
}

void Libro::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

void Libro::setCategoria(string categoria)
{
    this->categoria = categoria;
}

void Libro::setCategoriaSec(string categoria_sec)
{
    this->categoria_sec = categoria_sec;
}

void Libro::setPrecio(int precio)
{
    this->precio = precio;
}

void Libro::setEjempVend(int ejemp_vend)
{
    this->ejemp_vend = ejemp_vend;
}

void Libro::setEjenmpDisp(int ejemp_disp)
{
    this->ejemp_disp = ejemp_disp;
}
