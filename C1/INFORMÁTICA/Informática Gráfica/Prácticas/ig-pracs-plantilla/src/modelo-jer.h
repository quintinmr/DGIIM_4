#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP


#include "malla-ind.h"
#include "malla-revol.h"
#include "grafo-escena.h"

using namespace glm;

class MolinoAceite : public NodoGrafoEscena
{
 
    public:

        MolinoAceite();
        unsigned leerNumParametros() const;
        void actualizarEstadoParametro(const unsigned iParam, const float t_sec);

    
};

class Solera : public NodoGrafoEscena
{
    public:
       Solera();
};

class Alfarje : public NodoGrafoEscena
{
    public:
       Alfarje( );
};

class CiliAljarfe : public MallaRevol
{
    public:
      CiliAljarfe(const int num_verts_per,  const unsigned nperfiles);
};

class Rulo1 : public NodoGrafoEscena
{
    public:
       Rulo1();
};

class Rulo2 : public NodoGrafoEscena
{
    public:
       Rulo2();
};

class Rulo3 : public NodoGrafoEscena
{
    public:
       Rulo3();
};

class ConoRulo : public MallaRevol
{
    public:
       ConoRulo(const int num_verts_per, const unsigned nperfiles);

};

class Tolva : public MallaInd
{
    public:
       Tolva();
};







#endif // MODELO_JER_HPP