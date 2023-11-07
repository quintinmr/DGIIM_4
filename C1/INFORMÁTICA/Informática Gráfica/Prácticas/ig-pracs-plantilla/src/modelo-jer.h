#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP


#include "malla-ind.h"
#include "malla-revol.h"
#include "grafo-escena.h"
#include <vector>

using namespace glm;
using namespace std;

struct RotationPair {
    float angle;
    glm::vec3 axis;
};

class MolinoAceite : public NodoGrafoEscena
{
 
    protected:
        unsigned num_param = 4;
        unsigned rulo1,rulo2,rulo3,rulo4,palo,alfarje;
        //vector<mat4*> pm_rot_rulos{nullptr};
    
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
    protected:
        unsigned num_param = 1;
        mat4* rot_alfarje = nullptr;

    public:
       Alfarje( );
       void establecerRotacionAlfarje(float v_angular, float time);
       unsigned leerNumParametros() const;
       void actualizarEstadoParametro(const unsigned iParam, const float t_sec);
};

class CiliMolino : public MallaRevol
{
    public:
      CiliMolino(const int num_verts_per,  const unsigned nperfiles, glm::vec3 color);
};

class Rulo : public NodoGrafoEscena
{
    protected:
        unsigned int num_param = 1;
        mat4* pm_rulo = nullptr;
    
    public:
        Rulo(const vec3 traslacion, const vec3 escalado, const vector<RotationPair> rotaciones);
        void establecerRotacionRulos(float v_angular, float time);
        unsigned int leerNumParametros() const;
        void actualizarEstadoParametro(const unsigned int iParam, const float t_sec);
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

class Palo : public MallaInd
{
    public:
       Palo();

}; 

class PaloMolino : public NodoGrafoEscena
{
    
    protected:
       unsigned int num_param = 2;
       unsigned palo;
       mat4x4* pos_palo = nullptr;
       mat4x4* rot_palo = nullptr;

    public:
       PaloMolino();
       void establecerRotacionPalo(float v_angular, float time);
       void establecerPosicionPalo(vec3 pos);
       unsigned int leerNumeroParametros() const;
       void actualizarEstadoParametro(const unsigned int iParam, const float t_sec);

};


#endif // MODELO_JER_HPP