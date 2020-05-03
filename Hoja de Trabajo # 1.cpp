# include  <fstream>
# include  <iostream>
# include  <string>
# include  <cstdlib>
# include <ctime> 
# include  <stdio.h>
# include  <vector>
//usando el  espacio de nombres  estándar ;

flotador total_igss;
vector <cadena> en_memoria;

struct  Trabajadores {
  cadena nombre;
  float salario_x_h;
  int horas_trabajadas;
  flotante salario_semana;
  int horas_extras;
  flotador igss;
};



vacio  calculo_grabar ()
{
    Trabajadores x;

    cout << " Ingrese el nombre del trabajador: " << " \ n " ;
    cin >> x. nombre ;
    cout << " Ingrese el salario por hora del trabajador: " << " \ n " ;
    cin >> x. salario_x_h ;
    cout << " Ingrese el total de horas trabajas del trabajador: " << " \ n " ;
    cin >> x. horas_trabajadas ;

    // declaro las variables para el calculo
    flotante extra_total, igss, total;
    int tiempoextra;

    if (x. horas_trabajadas > 40 ) {
      tiempoextra = x. horas_trabajadas - 40 ;
      cout << tiempoextra;

      extra_total = (tiempoextra * 1.5 ) * x. salario_x_h ;
      
      total = ((x. horas_trabajadas -tiempoextra) * x. salario_x_h ) + extra_total;
      

    } más {
      total = (x. horas_trabajadas * x. salario_x_h );
    }
    X. salario_semana = total;
    X. horas_extras = tiempoextra;
    X. igss = total * ( 4.83 / 100 );
    total_igss = total_igss + x. igss ;

    // grabamos en el archivo.
    ofstream miarchivo ( " planilla.txt " , std :: ios_base :: app);
    miarchivo << x. nombre << endl;
    miarchivo << x. salario_x_h << endl;
    miarchivo << x. horas_trabajadas << endl;
    miarchivo << x. salario_semana << endl;
    miarchivo << x. horas_extras << endl;
    miarchivo << x. igss << endl;

    // Cerramos la escritura del archivo.
    miarchivo cerrar ();
}

vacío  leer_archivo () {
    // declaramos la variable para leer el archivo
    ifstream miarchivo;
    
    // archivo std :: ifstream ("myfile", std :: ios :: binary | std :: ios :: ate);
    // abrimos archivo
    miarchivo abierto ( " planilla.txt " , ios :: in);
    
    // declara una cadena para contener cada línea de texto
    línea de cuerda;

    // recorrer mi archivo mientras exista la línea
    while ( getline (miarchivo, line))
    {
        cout << línea << endl;
        // grabo en memoria
        en_memoria. push_back (línea);
    }

    // asegúrese de cerrar ifstream
    miarchivo cerrar ();
    cadena vacía;
    cin >> vacío;
    volver ;

}

int  main () {
  int contador;
  char tecla;
  cadena vacía;
  bool bandera = falso ;
  
  hacer
    {
        sistema ( " claro " );
        cin. claro ();
        cout << " Calculo de Salario " << endl;
        cout << " ----------- " << endl << endl;
        cout << " \ t 1 .- Ingresar Trabajador " << endl;
        cout << " \ t 2 .- Leer registros y grabar en memoria " << endl;
        cout << " \ t 3 .- Mostrar total de planilla " << endl;
        cout << " \ t 4 .- Salir " << endl << endl;
        cout << " Elije una opcion: " ;
 
        cin >> tecla;
 
		interruptor (tecla) {
			caso  ' 1 ' :
				sistema ( " claro " );
        calculo_grabar ();
        contador = contador + 1 ;
        romper ;
 
			caso  ' 2 ' :
        sistema ( " claro " );
        leer_archivo ();
        romper ;
      
      caso  ' 3 ' :
        sistema ( " claro " );
        cout << " El total de planilla del IGSS es de: " << " \ n " ;
        cout << " Q ". << total_igss;
        cin >> vacío;
        romper ;

      caso  ' 4 ' :
				bandera = verdadero ;
				// salida (1);
				romper ;
 
			por defecto :
				sistema ( " claro " );
				cout << " Opción no valida. \ a \ n " ;
				getchaar ();
        getline (cin, vacío);
				romper ;
		  }
    } while (bandera! = verdadero );
  
  devuelve  0 ;
}
