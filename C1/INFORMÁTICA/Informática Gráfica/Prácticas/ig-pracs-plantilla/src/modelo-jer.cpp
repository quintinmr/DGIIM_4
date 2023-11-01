#include "modelo-jer.h"
#include "malla-ind.h"
#include "ig-aux.h"

using namespace glm;
using namespace std;


MolinoAceite::MolinoAceite()
{
    agregar( new Solera() );
    agregar( new Tolva()  );
    agregar( new Alfarje());
    agregar( new Rulo1() );
    agregar( new Rulo2() );
    agregar( new Rulo3() );
    agregar( new Rulo4() );
    agregar( new Palo() );
    
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
    agregar ( new CiliMolino(50,50,vec3(0.5,0.5,0.5)) );
}

CiliMolino::CiliMolino
(
    const int num_verts_per,   //m
    const unsigned nperfiles,   //n
    glm::vec3 color
)
{
    std::vector<glm::vec3>  perfil_cili;

   perfil_cili.push_back(glm::vec3(0.0, 0.0, 0.0));

   float h;

   for(int i=0; i<num_verts_per-1; i++){

       h = float(i)/(num_verts_per-1);
      perfil_cili.push_back(glm::vec3(1,h,0.0));

   }

   for ( int i = 0; i < num_verts_per; i++){

      for (unsigned int j = 0; j < nperfiles; j++){

         col_ver.push_back(color);

      }
   }

   inicializar(perfil_cili, nperfiles);

}


Alfarje::Alfarje()
{
    agregar ( translate(vec3(0.0,1.0,0.0)));
    agregar ( scale(vec3(4.3,0.3,4.3)));
    agregar ( new CiliMolino(50,50,vec3(0.3, 0.2, 0.1)) );
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

    for (unsigned i = 0; i < vertices.size(); i++)
        col_ver.push_back(vec3(0.23, 0.31, 0.14));

    

}

Rulo1::Rulo1()
{
    
    agregar( translate(vec3(-2.87,1.7,+2.0) ) );
    agregar( scale(vec3(2.75,1.75,3.0)));
    agregar(rotate(radians(-90.0f), vec3(0.0, 0.0, 1.0))); 
    agregar(rotate(radians(-19.0f), vec3(0.0, 0.0, 1.0)));    
    agregar(rotate(radians(-30.0f), vec3(1.0, 0.0, 0.0)));

    agregar( new ConoRulo(50,50) );

    

}

Rulo2::Rulo2()
{
    
    agregar( translate(vec3(-2.87,1.7,-2.0) ) );
    agregar( scale(vec3(2.75,1.75,3.0)));
    agregar(rotate(radians(-90.0f), vec3(0.0, 0.0, 1.0))); 
    agregar(rotate(radians(-19.0f), vec3(0.0, 0.0, 1.0)));
    agregar(rotate(radians(+30.0f), vec3(1.0, 0.0, 0.0)));
    
    agregar( new ConoRulo(50,50) ); 

    

}

Rulo3::Rulo3()
{
    
    agregar( translate(vec3(+2.87,1.7,-2.0) ) );
    agregar( scale(vec3(2.75,1.75,3.0)));
    agregar(rotate(radians(+90.0f), vec3(0.0, 0.0, 1.0))); 
    agregar(rotate(radians(+19.0f), vec3(0.0, 0.0, 1.0)));
    agregar(rotate(radians(+30.0f), vec3(1.0, 0.0, 0.0)));
    
    agregar( new ConoRulo(50,50) ); 

}

Rulo4::Rulo4()
{
    
    agregar( translate(vec3(+2.87,1.7,+2.0) ) );
    agregar( scale(vec3(2.75,1.75,3.0)));
    agregar(rotate(radians(+90.0f), vec3(0.0, 0.0, 1.0))); 
    agregar(rotate(radians(+19.0f), vec3(0.0, 0.0, 1.0)));
    agregar(rotate(radians(-30.0f), vec3(1.0, 0.0, 0.0)));
    
    agregar( new ConoRulo(50,50) ); 

}
ConoRulo::ConoRulo
(
    const int num_verts_per, const unsigned nperfiles
)
{
    std::vector<glm::vec3>  perfil_conorulo;

    float h = 0;

    // Agrega el vértice en el centro de la base

    for(int i=0; i<int((num_verts_per-1)/3); i++){

       perfil_conorulo.push_back(glm::vec3());
   }


   for(int i=int((num_verts_per-1)/3); i<num_verts_per-1; i++){

       h = float(i)/(num_verts_per-1);
       perfil_conorulo.push_back(glm::vec3(0.3 * h, 1.5*(1-h), 0.0));
   }

    perfil_conorulo.push_back(glm::vec3(0.0,0.0,0.0));

    for ( int i=0; i < num_verts_per; i++){

      for (unsigned int j = 0; j < nperfiles; j++){

         col_ver.push_back(vec3(0.96, 0.87, 0.70));

      }
   } 

   inicializar(perfil_conorulo, nperfiles);

   
   

}

Palo::Palo()
{
    vertices=
    {
        {-0.15,1.5,+0.15}, //0
        {-0.15,1.5,-0.15}, //1
        {+0.15,1.5,-0.15}, //2
        {+0.15,1.5,+0.15}, //3

        {-0.15,4.5,+0.15}, //4
        {-0.15,4.5,-0.15}, //5
        {+0.15,4.5,-0.15}, //6
        {+0.15,4.5,+0.15} //7

    };

    triangulos=
    {
        {0,1,3},{2,3,1},
        {4,5,7},{6,7,5},
        {0,4,1},{5,1,4},
        {3,7,2},{6,2,7},
        {4,0,7},{3,7,0},
        {5,1,6},{2,6,1},
    };

    
    for (unsigned i = 0; i < vertices.size(); i++)
        col_ver.push_back(vec3{0.0,0.0,0.0});



}