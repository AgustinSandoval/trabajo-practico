#include <iostream>
#include <fstream>
#include <clocale>
#include <wchar.h>
#include <string>
#include <windows.h>

using namespace std;

/**
 * Abre el archivo segÃºn el origen, procesa las lÃ­neas del mismo y
 * almacena la informaciÃ³n resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen);//, Contenedor & contenedor);
string NormalizarLetra(char & letra);
int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
    procesar_archivo_entrada("libros.csv");
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a nï¿½mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargaron " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posiciï¿½n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string isbn = linea.substr(pos_inicial, pos_final);

            //Segunda posiciï¿½n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posiciï¿½n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posiciï¿½n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string fechaPublicacion = linea.substr(pos_inicial, pos_final - pos_inicial);

             //Quinta posiciï¿½n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string paisOrigen = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Sexta posiciï¿½n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << "LIBRO Nro "<< nroLibro<< "--------------------------------------" << endl;
            cout << "   ISBN: " << isbn << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   FECHA PUBLIC: " << fechaPublicacion<<endl;
            cout << "   PAIS: " << paisOrigen<< endl;
            cout << "   PRECIO: " << precio<<endl;

            //TO DO: Completar la lectura de los Idiomas del libro

            //Desde esta posiciï¿½n hasta el final se encuentra un nï¿½mero variable de idiomas de cada libro.
            //no tomo en cuenta los corchetes
            pos_inicial = pos_final + 2;
            pos_final = linea.size()-1;
            string idiomas = linea.substr(pos_inicial, pos_final - pos_inicial);
            cout << "   IDIOMAS: " << idiomas<<endl;

        /*
            // el siguiente cï¿½digo de prueba separa los diferentes idiomas en un arreglo de 10 posiciones
            string listaIdiomas[10];
            int pos_inicial_idiomas = 0, pos_final_idiomas = 0;
            int nroIdioma = 0;
            while (pos_final_idiomas != -1) {
                pos_final_idiomas = idiomas.find(',', pos_inicial_idiomas);
                listaIdiomas[nroIdioma] = idiomas.substr(pos_inicial_idiomas, pos_final_idiomas - pos_inicial_idiomas);
                cout<<"los idiomas de "<<titulo<<" son: "<<listaIdiomas[nroIdioma]<<endl;
                pos_inicial_idiomas = pos_final_idiomas + 1;
      Classical Musicians Guess Who is NOT a Musician          nroIdioma++;
            }
        */


            nroLibro++;
        }
        int opcion;

        //Tengo que cerrar y volver a abrir el archivo ya que el tellg() me devuelve -1 y el seekg() no me desplaza.
        archivo.close();
        archivo.open("libros.csv",ios::in);
    do {

        cout <<"\n----------------------------------"<<endl;
        cout << "\n Bienvenido a eCommerce" <<endl<<endl;
        cout << "-Presione 1 para buscar un titulo " << endl;
        cout << "-Presione 2 para ver los libros en un rango de fechas " << endl;
        cout << "-Presione 3 para ver un listado de los libros mas baratos en un idioma " << endl;
        cout << "-Presione 4 para finalizar el programa" << endl;
        cout << "\nIngrese una opcion: "<<endl<<endl;
        cout << "----------------------------------" <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:{
                system("cls");
                string linea;
                string busca;

                cout<<" Ingrese el titulo a buscar"<<endl<<"Recuerde que puede usar comodines como '?' si no recuerda una letra, o '*' si no sabe una palabra."<<endl;
                getline(cin, busca);
                while(!archivo.eof()){
                    getline(archivo, linea);

                    // Encuentro la posicion del titulo y lo paso a una variable limpia para no pasarme despues:
                    int pos_inicial = linea.find(';') + 1;
                    int pos_final = linea.find(';', pos_inicial);
                    string titulo = linea.substr(pos_inicial, pos_final-pos_inicial);

                    //Marco el inicio y el final la 1ï¿½palabra en ambos titulos(el que busco y el que tengo en el archivo)
                    int inicio=0;
                    int inicioB=0;
                    int fin=busca.find(' ');
                    string palabra=busca.substr(inicio, fin);
                    int finB=titulo.find(' ');
                    string palabraB=titulo.substr(inicio, finB);

                    //chequeo que la palabra exista y comparo en el while
                    if((!palabra.empty())){
                       bool para=false;
                       int esta=-1;

                        //si las palabras tienen el mismo largo, entro en el if
                        while((!palabra.empty()) && (!palabraB.empty()) && (para==false)&& (esta!=busca.size())){
                            if (palabra.size()==palabraB.size()){

                                //si las palabras estan escritas igual las doy por igual
                                if (palabra==palabraB){
                                    esta=esta+palabraB.size();

                                //si no estan igual escritas, reviso las palabras letra por letra
                                } else for(int i = 0; i < palabra.size(); i++) {
                                    palabra.replace(i,1,NormalizarLetra(palabra[i]));
                                    palabraB.replace(i,1,NormalizarLetra(palabraB[i]));
                                    if ((tolower(palabra[i])==tolower(palabraB[i]))&&(para==false)||(palabra[i]=='?')){
                                        esta=esta+1;
                                    }else para=true;
                                }

                            }else if (palabra=="*"){
                                esta=esta+palabra.size();
                        }else para=true;


                        //avanzo en ambas cadenas, buscando la siguiente palabra en cada una
                        if (para==false){
                            inicio=fin+1;
                            fin=busca.find(' ',inicio);
                            palabra=busca.substr(inicio, fin-inicio);
                            inicioB=finB+1;
                            finB=titulo.find(' ',inicioB);
                            if (finB!=-1){
                                palabraB=titulo.substr(inicioB, finB-inicioB);
                            }else palabraB=titulo.substr(0,0);
                        //Aca le sumo uno a la variable "esta"(la cual revisa si es la palabra correcta) para corregir la diferencia por los espacios
                        }esta=esta+1;
                    }if (esta==busca.size())
                        cout<< "se ha encontrado el titulo: "<< titulo<<endl;
                    }else{
                        cout<< "no se ha encontrado el titulo: "<<endl;
                    }
                }
                system("pause>nul"); // Pausa
                break;

             }
            case 2:{
                system("cls");
                int rangoIn;
                int rangoFin;

                cout<<"Ingrese la fecha inicial: "<<endl;
                cin>>rangoIn;
                cout<<"Ingrese la fecha final: "<<endl;
                cin>>rangoFin;
                cout<<endl<<"La siguiente lista de libros se publico en el reango de "<<rangoIn<<"-"<<rangoFin<<":"<<endl<<endl;;
                while(!archivo.eof()){
                    getline(archivo, linea);

                    // Encuentro la posicion de la fecha y lo paso a una variable limpia para no pasarme despues:
                    int pos_inicial = linea.find(';') + 1;
                    int pos_final = linea.find(';', pos_inicial);
                    string titulo=linea.substr(pos_inicial,pos_final-pos_inicial);
                    pos_inicial = pos_final + 1;
                    pos_final = linea.find(';', pos_inicial);
                    string autor=linea.substr(pos_inicial,pos_final-pos_inicial);
                    pos_inicial = pos_final + 1;
                    pos_final = linea.find(';', pos_inicial);
                    string fecha=linea.substr(pos_inicial,pos_final-pos_inicial);
                    pos_inicial = pos_final + 1;
                    pos_final = linea.find(';', pos_inicial);
                    string pais=linea.substr(pos_inicial,pos_final-pos_inicial);
                    pos_inicial = pos_final + 1;
                    pos_final = linea.find(';', pos_inicial);
                    string precio=linea.substr(pos_inicial,pos_final-pos_inicial);
                    pos_inicial = pos_final + 1;
                    pos_final = linea.find(';', pos_inicial);
                    string idiomas=linea.substr(pos_inicial,pos_final-pos_inicial);



                    if ((stoi(fecha)>rangoIn)&&(stoi(fecha)<rangoFin)){
                        cout << "--------------------------------------" << endl;
                        cout << "   TITULO: " << titulo<< endl;
                        cout << "   AUTOR: " << autor<< endl;
                        cout << "   FECHA PUBLIC: " << fecha<<endl;
                        cout << "   PAIS: " << pais<< endl;
                        cout << "   PRECIO: " << precio<<endl;
                    }
                }
                system("pause>nul"); // Pausa
                break;
                system("cls");
            }
            case 3: {
                system("cls");
                string linea;
                string titulo;
                string autor;
                string fecha;
                string pais;
                string precio;
                string idiomas;

                cout<<"Seleccione la cantidad de libros mas economicos que quiere ver: "<<endl;
                int cant;
                cin>>cant;
                cout<<"Ingrese el idioma de los libros"<<endl;
                string idiomaBuscado;
                cin>> idiomaBuscado;
                string idF;
                //cin.ignore();
                //getline(cin, idiomaBuscado);
                for(int i = 0; i < idiomaBuscado.size(); i++) {
                    cout<<"letra antes: "<<idiomaBuscado[i]<<endl;
                    idiomaBuscado.replace(i,1,NormalizarLetra(idiomaBuscado[i]));
                    //cout<<"normalizar letra: "<<NormalizarLetra(idiomaBuscado[i])<<endl;
                    cout<<"letra despues: "<<idiomaBuscado[i]<<endl;
                }
                cout<<"palabra despues: "<<idiomaBuscado<<endl;
                cout<<"presione una tecla para continuar:"<< endl;
                string asd = "";
                cin>>asd;
                
                string menor="0";

                for (int i=1; i<=cant; i++){
                    string compara="99999999";
                    archivo.seekg(1);
                    while(!archivo.eof()){
                        getline(archivo, linea);

                        // Asigno los valores de los precios:
                        int pos_inicial = linea.find(';') + 1;
                        int pos_final = linea.find(';', pos_inicial);
                        for (int a=0; a<4; a++){
                            pos_inicial = pos_final + 1;
                            pos_final = linea.find(';', pos_inicial);
                        }
                        precio=linea.substr(pos_inicial,pos_final-pos_inicial);

                        // Tomo los idiomas
                        pos_inicial = pos_final + 2;
                        pos_final = linea.size()-1;
                        idiomas = linea.substr(pos_inicial, pos_final - pos_inicial);

                        // Si el libro esta dentro
                        if ((precio<compara)&&(precio>menor)){

                            // el siguiente código de prueba separa los diferentes idiomas en un arreglo de 10 posiciones
                            string listaIdiomas[10];
                            int pos_inicial_idiomas = 0, pos_final_idiomas = 0;
                            int nroIdioma = 0;
                            string ArchIdioma;
                            while (pos_final_idiomas != -1) {
                                pos_final_idiomas = idiomas.find(',', pos_inicial_idiomas); 
                                ArchIdioma = idiomas.substr(pos_inicial_idiomas, pos_final_idiomas - pos_inicial_idiomas);
                                for(int i = 0; i < ArchIdioma.size(); i++) {
                                    ArchIdioma.replace(i,1,NormalizarLetra(ArchIdioma[i]));
                                }                
                                listaIdiomas[nroIdioma] = ArchIdioma;
                                
                                if (listaIdiomas[nroIdioma]==idiomaBuscado){
                                    // Si encuentro un libro que cumpla los requisitos guardo sus datos
                                    int pos_inicial = linea.find(';') + 1;
                                    int pos_final = linea.find(';', pos_inicial);
                                    titulo=linea.substr(pos_inicial,pos_final-pos_inicial);
                                    pos_inicial = pos_final + 1;
                                    pos_final = linea.find(';', pos_inicial);
                                    autor=linea.substr(pos_inicial,pos_final-pos_inicial);
                                    pos_inicial = pos_final + 1;
                                    pos_final =+ linea.find(';', pos_inicial);
                                    fecha=linea.substr(pos_inicial,pos_final-pos_inicial);
                                    pos_inicial = pos_final + 1;
                                    pos_final = linea.find(';', pos_inicial);
                                    pais=linea.substr(pos_inicial,pos_final-pos_inicial);
                                    pos_inicial = pos_final + 1;
                                    pos_final = linea.find(';', pos_inicial);
                                    pos_inicial = pos_final + 2;
                                    pos_final = linea.size()-1;
                                    idF = linea.substr(pos_inicial, pos_final - pos_inicial);
                                    compara=precio;


                                }else cout<<idiomaBuscado<<" no es igual a "<<listaIdiomas[nroIdioma]<<endl;

                                pos_inicial_idiomas = pos_final_idiomas+2;
                                nroIdioma++;
                            }
                        }

                        }
                        if(compara!="99999999"){
                        menor=compara;
                        cout << "LIBRO Nro "<< i<< "--------------------------------------" << endl;
                        cout << "   TITULO: " << titulo<< endl;
                        cout << "   AUTOR: " << autor<< endl;
                        cout << "   FECHA PUBLIC: " << fecha<<endl;
                        cout << "   PAIS: " << pais<< endl;
                        cout << "   PRECIO: " << menor<<endl;
                        cout << "   IDIOMAS: " << idF<<endl;
                        }
                    }

                    system("pause>nul"); // Pausa
                    break;
                }
            }
        } while (opcion != 4);
    }archivo.close();
}\
string NormalizarLetra(char & letra) {
    char lowercaseletra = tolower(letra);
    switch (lowercaseletra) {
        case '�' : return "a";
        case '�' : return "e";
        case '�' : return "i";
        case '�' : return "o";
        case '�' : return "u";
        case '�' : return "n";
        default: return string(1,lowercaseletra);
    }
}


