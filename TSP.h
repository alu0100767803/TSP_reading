#ifndef TSP_H
#define TSP_H

#include "Excepciones.cpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>


using namespace std;

/**
 * Autores: Jorge Alonso Hernández
 * 	    Erik Andreas Barreto de Vera
 *          Teguayco Gutiérrez González
 * 	    Miguel Castro Caraballo
 * 	    Carlos Troyano Carmona
 * 	    Rubén Labrador Paez
 * Fecha: 23/12/2016
 * Asignatura: Complejidad Computacional
 * Version: 1.0
 * Comentario: 	
 */

class TSP{
    private:
        int n_ciudades;					// variable con el numero de ciudades del problema
		vector<double> coordenadas_x;			// vector con las coordenadas x de las ciudades
		vector<double> coordenadas_y;			// vector con las coordenadas y de las ciudades	
		vector<vector<int> > matriz_distancias;	// matriz con las distancias de todas las ciudades
    public: 
        TSP();
        ~TSP();
        void leer_fichero(char nombreFichero[85]);
		void mostrar_matriz();
		int get_n_ciudades();
		vector<double> get_coordenadas_x();
		vector<double> get_coordenadas_y();
		vector<vector<int> > get_matriz_distancias();
		double get_coord_x(int nodo);		// Método que devuleve la coordenada x del nodo
		double get_coord_y(int nodo);		// Método que devuelve la coordenada y del nodo 
    private:
		void set_coordenadas_x(vector<double> x);
		void set_coordenadas_y(vector<double> y);
		void set_n_ciudades(int n);
		void set_matriz_distancias(vector<vector<int> > matriz);
		int distancia_euclidea(int nodo1, int nodo2);
		void calcular_matriz();
};

#endif