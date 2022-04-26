#include <iostream>
#include <iomanip>
#include <Menu.h>
#include <Libro.h>
#include <Lista.h>
using namespace std;

struct Campo //Variables para controlar el espacio disponible para las cadenas en formato tabla
{
    int nom = 6, //Nombre
    aut = 5,     //Autor
    ed = 9,      //Editorial
    isbn = 4,    //Isbn
    cat = 9,     //Categoria
    catsec = 12, //Categoria secundaria
    prc = 6,     //Precio
    ejd = 3,     //Ejemplares disponibles
    ejv = 3;     //Ejemplares vendidos
};



int campoMayor(int x,string y);  //Función para determinar si la cadena del
Libro capturarLibro(Lista lista); //Recibe la lista y solicita los campos de un libro
string capturaISBN(); //Solicita el isbn
void reStock(Libro &libro); //Establece el valor de ejemplares disponibles en 20
void ajustaCampo(Lista lista, Campo &campo); //Ajusta las variables de mi registro global campo, comparando el tamaño de cada cadena en mi lista

int main()
{
Campo campo;            //Campo para dar formato
Lista lista;            //Lista de libros
Menu menu;              //Instancia Menu para controlar el programa
int opc;                //Variable opcion para controlar el switch
bool ejecutado = false; //Booleano para ejecutar una sola vez la opcion 7

    do{
        opc = menu.menuPrincipal();
        switch(opc)
        {
            case 1: { //Insertar libros en lista

                        Libro l = capturarLibro(lista);

                        try {
                            lista.insertaAlFinal(l);
                        }  catch (const char* error) {
                            cout << error << endl;
                        }
                            ajustaCampo(lista,campo);

                                    break;
                    }
            case 2: { //
                    do
                    {
                        opc = menu.menuISBNnombre(); cin.ignore();
                        switch(opc)
                        {
                            case 1:
                                    {
                                      //Muestra el libro si el ISBN ingresado pertenece
                                      //a un libro en la lista, si no muestra que no hay con
                                      //ese mismo ISBN
                                        string buscaISBN = capturaISBN();
                                        bool encontrado = false;                                  
                                            for(int i=0; i < lista.getCont(); i++)
                                            {
                                                if(buscaISBN == lista.recupera(i).getISBN())
                                                {
                                                    cout << lista.recupera(i).toString() << endl;
                                                    encontrado = true;
                                                }
                                            }
                                            if(!encontrado)
                                                cout << "No hay libro con este ISBN" << endl;
                                    break;
                                    }
                            case 2: { //Busca con la cadena buscaNombre
                                      //las coincidencias de libros con ese mismo nombre
                                      //y muestra todas las coincidencias
                                        string buscaNombre = "";
                                        bool encontrado = false;
                                        cout << "Ingrese nombre: ";
                                        getline(cin,buscaNombre);
                                            for(int i=0; i < lista.getCont(); i++)
                                            {
                                                if(buscaNombre == lista.recupera(i).getNombre())
                                                {
                                                    cout << lista.recupera(i).toString() << endl;
                                                    encontrado = true;
                                                }
                                            }
                                            if(!encontrado)
                                                cout << "No hay libro con este nombre" << endl;
                                        break;
                                    }

                        }
                }while(opc!=0);
                    opc = -1; //Reseteo para salir con el 0, o se puede llamar a el metodo menu principal?
                    break;
                    }
            case 3: {//Modificar información del libro
                    cin.ignore();
                    string ISBN = capturaISBN(); //Capturamos el isbn
                    bool encontrado = false;     //Booleano para saber si encontro el ISBN
                        for(int i=0; i < lista.getCont() ; i++){ //Lo buscamos en la lista
                        if(ISBN == lista.recupera(i).getISBN())
                            {

                                Libro &modifica = lista.recupera(i);
                                encontrado = true; // Si lo encuentra cambiamos a true
                                do
                                {
                                    string stemp;
                                    int itemp;
                                    cout << modifica.toString() << endl;
                                    opc = menu.menuModifica();
                                    cin.ignore();
                                    switch (opc) {
                                        case 1: {
                                                    cout << "Ingrese Nombre: " ;
                                                    getline(cin,stemp);
                                                    modifica.setNombre(stemp);
                                                    break;
                                                }
                                        case 2: {
                                                    cout << "Ingrese Autor: " ;
                                                    getline(cin,stemp);
                                                    modifica.setAutor(stemp);
                                                    break;
                                                }
                                        case 3: {   cout << "Ingrese Editorial: " ;
                                                    getline(cin,stemp);
                                                    modifica.setEditorial(stemp);
                                                    break;
                                                }
                                        case 4: {
                                                    bool aceptado = true;
                                                    do{
                                                        stemp = capturaISBN();
                                                        for(int i = 0; i < lista.getCont(); i++)
                                                            if(stemp == lista.recupera(i).getISBN())
                                                            {
                                                                cout << "ISBN no valido" << endl;
                                                                system("pause");
                                                                aceptado = false;
                                                            }
                                                    }while(aceptado==false);
                                                    modifica.setISBN(stemp);
                                                    break;
                                                }
                                        case 5: {
                                                    cout << "Ingrese Categoria: " ;
                                                    getline(cin,stemp);
                                                    modifica.setCategoria(stemp);
                                                    break;
                                                }
                                        case 6: {   cout << "Ingrese Categoria Secundaria: " ;
                                                    getline(cin,stemp);
                                                    modifica.setCategoriaSec(stemp);
                                                    break;
                                                }
                                        case 7: {
                                                    do{
                                                        cout << "Ingrese Precio: " ;
                                                        cin >> itemp;
                                                            if(itemp<1)
                                                                cout << "Precio invalido" << endl;
                                                        }while(itemp<1);
                                                    modifica.setPrecio(itemp);
                                                    break;
                                                }
                                        case 8: {
                                                do{
                                                    cout << "Ingrese Ejemplares Disponibles: " ;
                                                    cin >> itemp;
                                                        if(itemp<1)
                                                            cout << "Ejemplares invalidos" << endl;
                                                    }while(itemp<1);
                                                    modifica.setEjenmpDisp(itemp);
                                                    break;
                                                }
                                        case 9: {
                                                do{
                                                    cout << "Ingrese Ejemplares Vendidos: " ;
                                                    cin >> itemp;
                                                        if(itemp<0)
                                                            cout << "Ejemplares invalidos" << endl;
                                                    }while(itemp<0);
                                                    modifica.setEjempVend(itemp);
                                                    break;
                                                }
                                        case 0: { break; }
                                    }
                                }while(opc!=0);


                            }
                        }
                        if(!encontrado) //Si no cambió a true entonces no se encontró
                        {
                            cout << "El libro no fue encontrado" << endl;
                        }else
                        {
                            ajustaCampo(lista,campo);
                        }
                        opc = -1;
                        break;
                    }

            case 4: { //Ventas
                        do{
                            opc = menu.menuISBNnombre();
                            switch(opc)
                            {
                                case 1: {
                                    cin.ignore();
                                    string ISBN = capturaISBN();
                                    for(int i=0; i < lista.getCont() ; i++){
                                        if(ISBN == lista.recupera(i).getISBN())
                                        {
                                           lista.recupera(i).setEjempVend(lista.recupera(i).getEjempVend()+1);
                                           lista.recupera(i).setEjenmpDisp(lista.recupera(i).getEjenmpDisp()-1);
                                           cout << "Ejemplar vendido con exito" << endl;
                                                if(lista.recupera(i).getEjenmpDisp()==0)
                                                {
                                                    cout << "Re stockeando ejemplares..." << endl;
                                                    reStock(lista.recupera(i));
                                                }
                                        }
                                    }
                                break;
                            }
                            case 2: cin.ignore();
                                    string temp;
                                    bool encontrado = false;
                                    cout << "Ingrese el nombre a buscar: ";
                                    getline(cin,temp);
                                        for(int i = 0; i < lista.getCont() ; i++){
                                            if(lista.recupera(i).getNombre() == temp)
                                            {

                                                cout << lista.recupera(i).toString() << endl;
                                                    cout << "Es este el libro buscado?" << endl << "1 Si 2 No :" << endl;
                                                    int opcBusqueda;
                                                    cin >> opcBusqueda;
                                                    if(opcBusqueda == 1)
                                                    {
                                                        encontrado = true;
                                                        lista.recupera(i).setEjempVend(lista.recupera(i).getEjempVend()+1);
                                                        lista.recupera(i).setEjenmpDisp(lista.recupera(i).getEjenmpDisp()-1);
                                                        cout << "Ejemplar vendido con exito" << endl;
                                                            if(lista.recupera(i).getEjenmpDisp()==0)
                                                            {
                                                                cout << "Re stockeando ejemplares..." << endl;
                                                                reStock(lista.recupera(i));
                                                            }
                                                            break;
                                                    }
                                            }
                                        }
                                            if(!encontrado)
                                            {
                                                cout << "No se encontro el libro" << endl;
                                            }
                                    break;
                            }
                            }while(opc!=0);
                        opc = -1;
                        break;
                    }
            case 5: { //Mostrar Todo
                        if(lista.vacia())
                        {
                            cout << "Lista vacia" << endl;
                            break;
                        }

                        cout << left;
                        cout << setw(campo.nom+1);    //Se le suma 1, porque cada miembro del registro tiene el valor de la longitud
                        cout << "Nombre";               //de la palabra de cada atributo del libro, es decir nombre tiene 6 letras
                        cout << setw(campo.aut+1);    //al sumar 1 tenemos 1 espacio para separar la información
                        cout << "Autor";
                        cout << setw(campo.ed+1);
                        cout << "Editorial";
                        cout << setw(campo.isbn+1);
                        cout << "ISBN";
                        cout << setw(campo.cat+1);
                        cout << "Categoria";
                        cout << setw(campo.catsec+1);
                        cout << "CategoriaSec";
                        cout << setw(campo.prc+1);
                        cout << "Precio";
                        cout << setw(campo.ejd+1);
                        cout << "EjD";
                        cout << setw(campo.ejv+1);
                        cout << "EjV";
                        cout << endl;
                        for(int i=0; i < lista.getCont(); i++)
                        {
                            cout << left;
                            cout << setw(campo.nom+1);
                            cout << lista.recupera(i).getNombre();
                            cout << setw(campo.aut+1);
                            cout << lista.recupera(i).getAutor();
                            cout << setw(campo.ed+1);
                            cout << lista.recupera(i).getEditorial();
                            cout << setw(campo.isbn+1);
                            cout << lista.recupera(i).getISBN();
                            cout << setw(campo.cat+1);
                            cout << lista.recupera(i).getCategoria();
                            cout << setw(campo.catsec+1);
                            cout << lista.recupera(i).getCategoriaSec();
                            cout << setw(campo.prc+1);
                            cout << lista.recupera(i).getPrecio();
                            cout << setw(campo.ejd+1);
                            cout << lista.recupera(i).getEjenmpDisp();
                            cout << setw(campo.ejv+1);

                            cout << lista.recupera(i).getEjempVend();
                            cout << endl;
                        }
                        break;
                    }
            case 6: { //Eliminar del catalogo
                            if(lista.vacia())
                            {
                                cout << "Lista vacia" << endl;
                                break;
                            }
                            cin.ignore();
                            string temp;
                            bool encontrado = false;
                            cout << "Ingrese el ISBN del libro a eliminar: ";
                            getline(cin,temp);
                            for(int i = 0; i < lista.getCont() ; i++)
                            {
                                if(temp == lista.recupera(i).getISBN())
                                {
                                    lista.eliminaPos(i);
                                    encontrado = true;
                                    break;
                                }
                            }
                            if(!encontrado)
                            {
                                cout << "No se encontro" << endl;
                            }else
                            {
                                ajustaCampo(lista,campo);
                            }
                        break;
                    }
            case 7://Ingresar 10 libros
                {   if(!ejecutado)
                    {

                    Libro l1("El Alquimista","Paulo Coelho","De Bolsillo","978-elal","Novela","Ficcion",200,35);
                    Libro l2("Mas Alla de tu Cerebro","David Perlmutter","Grijalbo","978-madt","Monografias","Salud",350,40);
                    Libro l3("El Alquimista","Michael Scott","Roca Junior","978-elal","Novela","Ficcion",400,15);
                    Libro l4("Los malditos","J. Jesus Lemus","Debolsillo","978-lmcp","Cronica","Narrativa",150,35);
                    Libro l5("El arte de la guerra","Sun Tzu","Emu","978-eadg","Tratado","Tactica militar",300,30);
                    Libro l6("El viejo y el mar","Ernest Hemingway","Charles Scribners Sons","978-evym","Novela","Literatura",100,10);
                    Libro l7("El origen de la vida","Alexander Oparin","Emu","978-elog","Cientifico","Educativo",200,20);
                    Libro l8("Mi planta de naranja lima","Jose Mauro de Vasconcelos","El ateneo","978-mpam","Novela","Relato",500,20);
                    Libro l9("Paco Yunque","Cesar Vallejo","Apuntes del hombre","978-pacy","Relato","Recreativo",100,20);
                    Libro l10("Los viajes de Gulliver","Jonathan Swift","Selector","978-lvdg","Satira","Infantil",150,20);
                    Libro librosHDcode[10];
                    librosHDcode[0] = l1;
                    librosHDcode[1] = l2;
                    librosHDcode[2] = l3;
                    librosHDcode[3] = l4;
                    librosHDcode[4] = l5;
                    librosHDcode[5] = l6;
                    librosHDcode[6] = l7;
                    librosHDcode[7] = l8;
                    librosHDcode[8] = l9;
                    librosHDcode[9] = l10;
                    bool aceptado = true;

                    for(int i = 0; i < 10 ; i++)
                    {
                        aceptado = true;

                            for(int j = 0; j < lista.getCont() ; j++)
                            {
                                if(librosHDcode[i].getISBN() == lista.recupera(j).getISBN())
                                    {
                                        aceptado = false;
                                    }
                            }
                            if(aceptado)
                                try {
                                lista.insertaAlFinal(librosHDcode[i]);
                            }  catch (const char* error) {
                                cout << error << endl;
                            }



                    }
                        ajustaCampo(lista,campo);
                        cout << "Ejecutado..." << endl;
                        ejecutado = true;
                    }else
                    {
                        cout << "Opcion ya ejecutada" << endl;
                    }
                    break;
                }


        }

    }while(opc!=0);

    return 0;
}

Libro capturarLibro(Lista lista)
{
    cin.ignore();
    string nombre,autor,editorial,ISBN,categoria,categoria_sec;
    bool aceptado;
    int precio, ejemp_disp;

    cout << "Ingrese el nombre del libro: ";
    getline(cin,nombre);

    cout << "Ingrese el nombre del autor: ";
    getline(cin,autor);

    cout << "Ingrese el nombre de la editorial: ";
    getline(cin,editorial);

    do
    {
        ISBN = capturaISBN();
        aceptado = true;
        for(int i=0; i < lista.getCont() ; i++)
        {
            if(ISBN==lista.recupera(i).getISBN())
            {
                aceptado = false;
                cout << "ISBN no valido" << endl;
                system("pause"); //Pausamos para evitar errores al hacer inyeccion de datos con ISBN repetidos
                break; //Sale del for
            }
        }
    }while(aceptado == false);

    cout << "Ingrese categoria del libro: ";
    getline(cin,categoria);

    cout << "Ingrese categoria secundaria del libro: ";
    getline(cin,categoria_sec);

    do
    {
        cout << "Ingrese precio del libro: ";
        cin >> precio;
            if(precio<1)
                cout << "Precio invalido"<<endl;
    }while(precio<1);

    do
    {
        cout << "Ingrese ejemplares disponibles: ";
        cin >> ejemp_disp;
        if(ejemp_disp<1)
           cout << "Ejemplares no validos" << endl;
    }while(ejemp_disp<1);

        Libro l(nombre,autor,editorial,ISBN,categoria,categoria_sec,precio,ejemp_disp);
        return l;
}

string capturaISBN(){
    string ISBN;
    cout << "Ingrese ISBN del libro: ";
    getline(cin,ISBN);

    return ISBN;
}

int campoMayor(int x,string y) //Compara dos enteros, donde el mayor delimita el campo
{
    if(((int)y.length())>x)
        return ((int)y.length());
    return x;
}

void reStock(Libro &libro) //Agrega 20 ejemplares al libro pasado por parametro
{
    libro.setEjenmpDisp(20);
}

void ajustaCampo(Lista lista,Campo &campo) //Delimita los campos, utilizando los datos de la lista de libros
{
    campo.nom = 6,
    campo.aut = 5,
    campo.ed = 9,
    campo.isbn = 4,
    campo.cat = 9,
    campo.catsec = 12,
    campo.prc = 6,
    campo.ejd = 3,
    campo.ejv = 3;

    for(int i = 0; i < lista.getCont() ; i++)
    {
                campo.nom     = campoMayor(campo.nom, lista.recupera(i).getNombre());
                campo.aut     = campoMayor(campo.aut, lista.recupera(i).getAutor());
                campo.ed      = campoMayor(campo.ed, lista.recupera(i).getEditorial());
                campo.isbn    = campoMayor(campo.isbn, lista.recupera(i).getISBN());
                campo.cat     = campoMayor(campo.cat, lista.recupera(i).getCategoria());
                campo.catsec  = campoMayor(campo.catsec, lista.recupera(i).getCategoriaSec());
                campo.prc     = campoMayor(campo.prc, to_string(lista.recupera(i).getPrecio()));
                campo.ejd     = campoMayor(campo.ejd, to_string(lista.recupera(i).getEjenmpDisp()));
                campo.ejv     = campoMayor(campo.ejv, to_string(lista.recupera(i).getEjempVend()));
    }
}
