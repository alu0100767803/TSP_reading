#include "TSP.h"

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Programa principal para la lectura del problema del TSP
 */
int main(){
    char filename[85];
    cout<<"---------------Traveling Salesman Problem---------------"<<endl;
    cout << "Fichero con el problema:";
    cin >> filename;
    
    TSP tsp;
    tsp.leer_fichero(filename); 
    tsp.mostrar_matriz();
}