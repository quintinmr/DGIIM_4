// Nombre: Quintín, Apellidos: Mesa Romero, Titulación: GIM.
// email: quintinmr@correo.ugr.es, DNI o pasaporte: 78006011Q
// *********************************************************************

#ifndef LATAPEONES_HPP
#define LATAPEONES_HPP

#include "malla-ind.h"
#include "grafo-escena.h"
#include "malla-revol.h"

class Lata : public NodoGrafoEscena
{
    public:
        Lata(const std::string & archivoTextura);
};

class PeonMadera : public NodoGrafoEscena
{
    public:
        PeonMadera();
};

class PeonBlanco : public NodoGrafoEscena
{
    public:
        PeonBlanco();
};

class PeonNegro : public NodoGrafoEscena
{
    public:
        PeonNegro();
};

class LataPeones : public NodoGrafoEscena
{
    public:
        LataPeones();
};

#endif
