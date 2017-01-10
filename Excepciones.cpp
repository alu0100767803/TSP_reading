#include <cstdio>

#include <exception>

using namespace std;

class Excepciones{
public:
  virtual const char * excepcion () const throw () = 0;
};

/**
 * Clase para manejar los errores a la hora de abrir el fichero
 */
class fichero_erroneo : public Excepciones{
public:
  virtual const char * excepcion () const throw (){
    return "ERROR: Fichero incorrecto";
  }
  
};

/**
 * Clase para manejar las excepciones del número de ciudades 
 */
class tamanyo_erroneo : public Excepciones{
public: 
  virtual const char * excepcion () const throw (){
    return "ERROR: El tamaño de matriz introducido en el fichero es erroneo";
  }
};
