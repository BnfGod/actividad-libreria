#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std;

class Libro
{
private:
    string nombre;
    string autor;
    string editorial;
    string ISBN;
    string categoria;
    string categoria_sec;
    int precio;
    int ejemp_disp;
    int ejemp_vend;
public:
    Libro();
    Libro(string nombre,string autor,string editorial,string ISBN,string categoria,
          string categoria_sec, int precio, int ejemp_disp);
    string toString();

    string getNombre();

    string getAutor();
    string getEditorial();

    string getISBN();
    string getCategoria();
    string getCategoriaSec();

    int getPrecio();
    int getEjempVend();
    int getEjenmpDisp();




    void setNombre(string a);
    void setAutor(string a);
    void setEditorial(string a);
    void setISBN(string a);
    void setCategoria(string a);
    void setCategoriaSec(string a);
    void setPrecio(int p);
    void setEjempVend(int p);
    void setEjenmpDisp(int p);

};

#endif // LIBRO_H
