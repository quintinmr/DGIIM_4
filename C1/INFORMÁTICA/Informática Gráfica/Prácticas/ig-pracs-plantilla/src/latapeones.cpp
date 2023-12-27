// Nombre: Quintín, Apellidos: Mesa Romero, Titulación: GIM.
// email: quintinmr@correo.ugr.es, DNI o pasaporte: 78006011Q
// *********************************************************************

#include "latapeones.h"

using namespace glm;

Lata::Lata(const std::string& archivoTextura)
{
    NodoGrafoEscena * base_inferior = new NodoGrafoEscena();
    NodoGrafoEscena * cilindro_lata = new NodoGrafoEscena();
    NodoGrafoEscena * base_superior = new NodoGrafoEscena();

    Material * material_bases = new Material(0.1,0.6,0.3,20);
    base_inferior->agregar(material_bases);
    base_superior->agregar(material_bases);

    Material * material_cilindro = new Material(new Textura(archivoTextura),0.5,0.1,0.3,20);
    cilindro_lata->agregar(material_cilindro);
    base_inferior->agregar(new MallaRevolPLY("lata-pinf.ply",50));
    agregar(base_inferior);
    base_superior->agregar(new MallaRevolPLY("lata-psup.ply",50));
    agregar(base_superior);
    cilindro_lata->agregar(new MallaRevolPLY("lata-pcue.ply",50));
    agregar(cilindro_lata);
}

PeonMadera::PeonMadera()
{
    Textura * madera = new Textura("text-madera.jpg");
    agregar(scale(vec3(0.2,0.2,0.2)));
    agregar(translate(vec3(0.0,1.35,0.0)));
    agregar( new Material(madera, 0.2, 0.4, 0.4, 20));
    agregar( new MallaRevolPLY("peon.ply",50));

}

PeonBlanco::PeonBlanco()
{
    agregar(scale(vec3(0.2,0.2,0.2)));
    agregar(translate(vec3(0.0,1.35,0.0)));
    agregar( new Material(0.1,0.8,0.1,15));
    agregar( new MallaRevolPLY("peon.ply",50));

}

PeonNegro::PeonNegro()
{
    agregar(scale(vec3(0.2,0.2,0.2)));
    agregar(translate(vec3(0.0,1.35,0.0)));
    agregar( new Material(0.1,0.1,0.8,20));
    agregar( new MallaRevolPLY("peon.ply",50));

}

LataPeones::LataPeones()
{
    NodoGrafoEscena * lata = new NodoGrafoEscena();
    lata->agregar(new Lata("lata-coke.jpg"));
    agregar(lata);
    agregar(translate(vec3(0.0, 0.0, 1.0)));
    agregar(new PeonMadera());
    agregar(translate(vec3(0.5, 0.0, 0.0)));
    agregar(new PeonBlanco());
    agregar(translate(vec3(0.5, 0.0, 0.0)));
    agregar(new PeonNegro());
}

