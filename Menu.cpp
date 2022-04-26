#include "Menu.h"

int Menu::menuPrincipal()
{
    int opc;

    cout << "1. Ingresar un nuevo libro" << endl;
    cout << "2. Buscar y mostrar" << endl;
    cout << "3. Modificar informacion de libro" << endl;
    cout << "4. Ventas" << endl;
    cout << "5. Mostrar todo" << endl;
    cout << "6. Eliminar del catalogo" << endl;
    cout << "7. Crear automaticamente 10 libros" << endl;
    cout << "0. Salir" << endl;

    cin >> opc;

    return opc;
}

int Menu::menuISBNnombre()
{
    int opc;

    cout << "1. ISBN" << endl;
    cout << "2. Nombre" << endl;
    cout << "0. Salir" << endl;

    cin >> opc;

    return opc;
}

int Menu::menuModifica()
{
    int opc;

    cout << "1. Nombre" << endl;
    cout << "2. Autor" << endl;
    cout << "3. Editorial" << endl;
    cout << "4. ISBN" << endl;
    cout << "5. Categoria" << endl;
    cout << "6. Categoria secundaria" << endl;
    cout << "7. Precio" << endl;
    cout << "8. Ejemplares disponibles" << endl;
    cout << "9. Ejemplares vendidos" << endl;
    cout << "0. Salir" << endl;
    cin >> opc;

    return opc;
}
