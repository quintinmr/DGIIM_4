#include "modelo-jer.h"
#include "malla-ind.h"

using namespace glm;
using namespace std;


MolinoAceite::MolinoAceite()
{
    agregar( new Solera() );
    agregar( new Tolva()  );
    agregar( new Alfarje());
}

unsigned int MolinoAceite::leerNumParametros() const
{
    return 0;
}

void MolinoAceite::actualizarEstadoParametro(unsigned int iParam, const float t_sec)
{
    cout << "Actualizado estado del parametro..." << endl;

}

Solera::Solera()
{
    agregar ( scale(vec3(4.0,1.0,4.0)) );
    agregar ( new Cilindro(50,50) );
}

CiliAljarfe::CiliAljarfe
(
    const int num_verts_per,   //m
    const unsigned nperfiles   //n
)
{
    std::vector<glm::vec3>  perfil_cili;

   perfil_cili.push_back(glm::vec3(0.0, 0.0, 0.0));

   float h;

   for(int i=0; i<num_verts_per-1; i++){

       h = float(i)/(num_verts_per-1);
      perfil_cili.push_back(glm::vec3(1,h,0.0));

   }

   inicializar(perfil_cili, nperfiles);

}

Alfarje::Alfarje()
{
    agregar ( translate(vec3(0.0,1.0,0.0)));
    agregar ( scale(vec3(4.3,0.3,4.3)));
    agregar ( new CiliAljarfe(50,50) );
}



Tolva::Tolva()
{
    vertices = 
    {
        {-0.5,1.5,+0.5},  //0
        {+0.5,1.5,+0.5},  //1
        {-0.5,1.5,-0.5},  //2
        {+0.5,1.5,-0.5},  //3
        
        
        {-1.5,3.5,+1.5},  //4
        {+1.5,3.5,+1.5},  //5
        {-1.5,3.5,-1.5},  //6
        {+1.5,3.5,-1.5},  //7

        {-0.5,1.0,+0.5},  //8
        {+0.5,1.0,+0.5},  //9
        {-0.5,1.0,-0.5},  //10
        {+0.5,1.0,-0.5},  //11

    };

    triangulos =
    {
        
        {0,6,4}, {0,6,2},
        {1,5,3}, {3,5,7},
        {0,1,4}, {1,4,5},
        {2,6,3}, {3,6,7},
        {8,2,10},{8,2,0},
        {9,1,11},{11,1,3},
        {8,9,9}
    };

}

Rulo1::Rulo1()
{
    //agregar( rotate(2*M_PI/3,vec3(0.0,1.0,0.0)));

}