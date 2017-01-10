#include "TSP.h"

TSP::TSP(){
    n_ciudades = 0;
    coordenadas_x.resize(0);
    coordenadas_y.resize(0);
    matriz_distancias.resize(0);
}

TSP::~TSP(){
  n_ciudades = 0;
  coordenadas_x.resize(0);
  coordenadas_y.resize(0);
  matriz_distancias.resize(0);
}

/**
 * Método para leer el problema del TSP desde fichero
 */
void TSP::leer_fichero(char nombreFichero[85]){
    try{
  
    ifstream fichero(nombreFichero);
    //fichero.open("a280.tsp");
    
    
    if(fichero.is_open()){
      string cabecera, puntos;
      int n = 0;
     
      while(cabecera.compare("NODE_COORD_SECTION") != 0){
    	fichero >> (string &) cabecera; 
    	cout << cabecera << endl;
    	
    	// Para el caso en que haya un espacio entre DIMENSION y ":"
    	if(cabecera.compare("DIMENSION") == 0){
    	  fichero >> (string &) puntos >> (int &) n;
    	  if(n <= 0)
    	    throw tamanyo_erroneo();
    	  set_n_ciudades(n);
    	}
    	
    	//Para el caso en que no haya un espacio entre DIMENSION Y ":"
    	else if(cabecera.compare("DIMENSION:") == 0){
    	  fichero >> (int &) n;
    	  if(n <= 0)
    	    throw tamanyo_erroneo();
    	  set_n_ciudades(n);
    	}
	
	// ignorar las cabeceras que no sean relevantes
	fichero.ignore(256, '\n');
	
      }
      
      cout << "Número de ciudades: " << get_n_ciudades() << endl;
      
      int nodo;
      double coord_x, coord_y;
      for(int i = 0; i < n; i++){
	  fichero >> (int &) nodo >> (double &) coord_x >> (double &) coord_y;

	  coordenadas_x.push_back(coord_x);
	  coordenadas_y.push_back(coord_y);
      } 
      
    matriz_distancias.resize(n);
    for(int i = 0; i < matriz_distancias.size(); i++){
	matriz_distancias[i].resize(n);
      } 
    }
    
    else
      throw fichero_erroneo();
    
    fichero.close();
    calcular_matriz();
  
  }
  
  catch(tamanyo_erroneo& e){
    cout << e.excepcion() << endl;
  }
  
  catch(fichero_erroneo& e){
    cout << e.excepcion() << endl;
  }
}


/**
 * Método que calcula la matriz de distancias del problema 
 */
void TSP::calcular_matriz(){
  for(int i = 0; i < get_n_ciudades(); i++){
    for(int j = 0; j < get_n_ciudades(); j++){
      if(i != j){
	matriz_distancias[i][j] = distancia_euclidea(i, j);
	
      }
      else{
	matriz_distancias[i][j] = 0;
	
      }
    }
  }
  
}

/**
 * Método que devuelve la distancia euclidea entre dos puntos
 */
int TSP::distancia_euclidea(int nodo1, int nodo2){
  int distancia = floor(sqrt(pow(get_coord_x(nodo2) - get_coord_x(nodo1), 2) 
		      + (pow(get_coord_y(nodo2) - get_coord_y(nodo1), 2))) + 0.5);
  
  return distancia;
  
}

/*
 * Método que muestra la matriz de distancias
 */
void TSP::mostrar_matriz(){
  for(int i = 0; i < get_n_ciudades(); i++){
    for(int j = 0; j < get_n_ciudades(); j++){
      cout << matriz_distancias[i][j] << " ";
    }
    cout << endl;
  }
}


/*
 * ----------------------------------Getters y Setters----------------------------------------
 */

int TSP::get_n_ciudades(){
  return n_ciudades;
}

void TSP::set_n_ciudades(int n){
  n_ciudades = n;
}

vector<double> TSP::get_coordenadas_x(){
  return coordenadas_x;
}

vector<double> TSP::get_coordenadas_y(){
  return coordenadas_y;
}

void TSP::set_coordenadas_x(vector<double> x){
  coordenadas_x = x;
}

void TSP::set_coordenadas_y(vector<double> y){
  coordenadas_y = y;
}

double TSP::get_coord_x(int nodo){
  return get_coordenadas_x()[nodo];
}

double TSP::get_coord_y(int nodo){
  return get_coordenadas_y()[nodo];
}

vector<vector<int> > TSP::get_matriz_distancias(){
  return matriz_distancias;
}

void TSP::set_matriz_distancias(vector<vector<int> > matriz){
  matriz_distancias = matriz;
}