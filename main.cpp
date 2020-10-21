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
