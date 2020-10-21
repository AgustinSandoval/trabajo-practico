#include <iostream>
#include <fstream>
using namespace std;


void lectura();

int main()
{
    lectura();
}

void lectura(){
    ifstream archivo;
    string linea;
    string busca;

    archivo.open("libros.csv",ios::in);

    if(archivo.fail()){
        cout << "error al abrir el archivo";
        exit(1);
    }
    cout<<"ingrese el titulo a buscar"<<endl;
    cin>>busca;
    while(!archivo.eof()){
        getline(archivo, linea);

        // Encuentro la posicion del titulo y lo paso a una
        //variable limpia para no pasarme despues:
        int pos_inicial = linea.find(';') + 1;
        int pos_final = linea.find(';', pos_inicial);
        string titulo = linea.substr(pos_inicial, pos_final-pos_inicial-1);

//-----------------------------------------------------------------------------------------------------------------------------------------
        // PRIMERO:
        // divido el string busca en las diferentes palabras que tenga. por ej: master of puppets va a transformarse en array[master, of, puppets]' Arreglo de 3 string o cantidad de strings necesarios
        //Segundo hago lo mismo con titulo, pero antes al titulo le saco los acentos ~y le saco las mayusculas~.
        //ahora, voy a tener 2 arreglos 1 para la busqueda, 1 con el titulo
        //Comparo arreglo con arreglo con los titulos.
        // Opcion 1 => Array 1 . size != array 2 . size son distinta cancion
        // Opcion 2 => Array 1 . size == array 2 => llamo a metodo comparar palabra

        def compararPalabra(palBusqueda: String, palTitulo: String) : Boolean = {
            if (palBusqueda == '*') {
                return true
            } else 
            if (palBusqueda.size != palTitulo.size) {
                return false
            } else  {
                //palBusqueda es un string convertir a array como se pueda y l;lamar a funcion letrasiguales
                for(i = 1, i < pal1.size, i++) {
                    if (!letrasIguales(palBusqueda[i], palTitulo[i]))
                    return false
                }
                return true
            }
        }

        def letrasIguales(letra1: Char, letra2: Char): Boolean = {
            if(let1 == '?') return true else return let1 == let2
        }

//----------------------------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------------------------

//Comentarios para FACUNDO. Si no queres irte de rango, pone algun mecanismo de control. Por ejemplo si lo haces con recursion, podes pasarle a la funcion recursiva
// el tamaño de la palabra en letras, e ir restando cada vez que entras a la funcion recursiva. Cuando el tama;o es 0, salis de la funcion recursiva;
// Te recomiendo no hacerlo con recursion porque le metes complejidad al pedo

//------------------------------------------------------------------------------------------------------------------------------------------
        /*si la palabra es un comodin la tomo como igual, sino, comparo la palabra letra por letra.
        if(titulo.substr(inicioT, finT-inicioT)=='*'){
         //sigo comparando la siguiente palabra (recursion?) seguramente
        }else{
        if(titulo.substr(inicioT, finT-inicioT)==linea.substr(inicioL, finL-inicioL));
            cout<<"hola"<<endl; */



        /*if(titulo==linea.substr(pos_inicial, pos_final-pos_inicial-1)){
                cout<<titulo<< " ha sido encontrado"<< endl;
        } este es el algoritmo que busca el titulo escrito tal cual, sin comodin*/
    }

}
