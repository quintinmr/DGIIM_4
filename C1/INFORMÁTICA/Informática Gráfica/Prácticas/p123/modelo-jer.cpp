// Nombre: Quintín, Apellidos: Mesa Romero, Titulación: GIM.
// email: quintinmr@correo.ugr.es, DNI o pasaporte: 78006011Q

#include "modelo-jer.h"
#include "malla-ind.h"
#include "ig-aux.h"

using namespace glm;
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------
//      MOLINOACEITE
//-------------------------------------------------------------------------------------------------------------------------

MolinoAceite::MolinoAceite(float angle_alfarje_inic, float angle_rulos_inic, float angle_palo_inic, vec3 pos_palo_inic)
{
    
    angle_alfarje_ini = angle_alfarje_inic;
    angle_rulos_ini   = angle_rulos_inic;
    angle_palo_ini    = angle_palo_inic;
    pos_palo_ini      = pos_palo_inic; 

    // Tolva
    agregar( new Tolva()  );

    //Solera
    agregar( new Solera() );

    //alfarje
    alfarje = agregar( new Alfarje(angle_alfarje_ini));

    //palo
    palo  = agregar( new PaloMolino(angle_palo_ini, pos_palo_ini) ); 
    
    //rulo1
    vector<RotationPair> rots1 = {
        {-90.0f, vec3(0.0, 0.0, 1.0)},
        {-19.0f, vec3(0.0, 0.0, 1.0)},
        {-47.5f, vec3(1.0, 0.0, 0.0)},
        {angle_rulos_inic, vec3(0.0,1.0,0.0)}
    };

    rulo1 = agregar( new Rulo(vec3(-2.87,1.7,+2.75), vec3(3.5,1.75,3.0),rots1));

     //rulo2
    vector<RotationPair> rots2 = {
        {-90.0f, vec3(0.0, 0.0, 1.0)},
        {-19.0f, vec3(0.0, 0.0, 1.0)},
        {+47.5f, vec3(1.0, 0.0, 0.0)},
        {angle_rulos_inic, vec3(0.0,1.0,0.0)}
    };

    rulo2 = agregar( new Rulo(vec3(-2.87,1.7,-2.75), vec3(3.5,1.75,3.0),rots2));

    //rulo3
    vector<RotationPair> rots3 = {
        {+90.0f, vec3(0.0, 0.0, 1.0)},
        {+19.0f, vec3(0.0, 0.0, 1.0)},
        {+47.5f, vec3(1.0, 0.0, 0.0)},
        {angle_rulos_inic, vec3(0.0,1.0,0.0)}
    };

    rulo3 = agregar( new Rulo(vec3(+2.87,1.7,-2.75), vec3(3.5,1.75,3.0),rots3));

    //rulo4
    vector<RotationPair> rots4 = {
        {+90.0f, vec3(0.0, 0.0, 1.0)},
        {+19.0f, vec3(0.0, 0.0, 1.0)},
        {-47.5f, vec3(1.0, 0.0, 0.0)},
        {angle_rulos_inic, vec3(0.0,1.0,0.0)}
    };

    rulo4 = agregar( new Rulo(vec3(+2.87,1.7,+2.75), vec3(3.5,1.75,3.0),rots4));    
    
    
}

unsigned int MolinoAceite::leerNumParametros() const
{
    return num_param;
}

void MolinoAceite::actualizarEstadoParametro(unsigned int iParam, const float t_sec)
{
    assert(iParam <= leerNumParametros()-1);

     switch (iParam)
     {
     
     case 0:
        ((Rulo*)(entradas[rulo1].objeto))->actualizarEstadoParametro(iParam, t_sec);
        ((Rulo*)(entradas[rulo2].objeto))->actualizarEstadoParametro(iParam, t_sec);
        ((Rulo*)(entradas[rulo3].objeto))->actualizarEstadoParametro(iParam, t_sec);
        ((Rulo*)(entradas[rulo4].objeto))->actualizarEstadoParametro(iParam, t_sec); 
        break;

     case 1: case 2:
        
        ((PaloMolino*)(entradas[palo].objeto))->actualizarEstadoParametro(iParam-1, t_sec);
        break;

     case 3:
        ((Alfarje*)(entradas[alfarje].objeto))->actualizarEstadoParametro(iParam-3, t_sec);
        break;

     

    }

}

//-------------------------------------------------------------------------------------------------------------------------
//      SOLERA
//-------------------------------------------------------------------------------------------------------------------------

Solera::Solera()
{
    agregar ( scale(vec3(4.0,1.0,4.0)) );
    agregar ( new CiliMolino(50,50,vec3(0.5,0.5,0.5)) );
}

//-------------------------------------------------------------------------------------------------------------------------
//      ALFARJE
//-------------------------------------------------------------------------------------------------------------------------

Alfarje::Alfarje(float angle_alfarje_inic)
{
    angle_alfarje_ini = angle_alfarje_inic;
    agregar ( translate(vec3(0.0,1.0,0.0)));
    agregar ( scale(vec3(4.3,0.3,4.3)));
    unsigned ind_rot = agregar(rotate(radians(angle_alfarje_ini), vec3(0.0, 1.0, 0.0)));
    agregar ( new CiliMolino(200,200,vec3(0.3, 0.2, 0.1)) );
    rot_alfarje = leerPtrMatriz(ind_rot);  
}

void Alfarje::establecerRotacionAlfarje(float time)
{
    // Calcular el ángulo de rotación en función del tiempo
    float anguloRotacion = (angle_alfarje_ini) * time;
    *rot_alfarje = rotate(radians(anguloRotacion), vec3(0.0, 1.0, 0.0));;
} 

unsigned Alfarje::leerNumParametros() const
{
    return num_param;
}

void Alfarje::actualizarEstadoParametro(const unsigned iParam, const float t_sec)
{
    assert(iParam <= leerNumParametros()-1);

    switch (iParam)
    {
    case 0:
        establecerRotacionAlfarje(t_sec);
        break;
    
    }
}

// Objeto CiliMolio, usado en SOLERA y ALFARJE
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

         if (i%2 ==0)
          col_ver.push_back(color);
         else 
          col_ver.push_back(color+vec3(0.1,0.1,0.1));

      }
   }

   inicializar(perfil_cili, nperfiles);

}

//-------------------------------------------------------------------------------------------------------------------------
//      TOLVA
//-------------------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------------------
//      RULO
//-------------------------------------------------------------------------------------------------------------------------

Rulo::Rulo(const vec3 traslacion, const vec3 escalado, const vector<RotationPair> rotaciones)
{
    angle_rulo_inic = rotaciones[rotaciones.size()-1].angle;
    agregar( translate(traslacion) );
    agregar( scale(escalado) );
    for (long unsigned int i = 0; i < rotaciones.size()-1; i++){

        float angulo = rotaciones[i].angle;
        vec3 eje     = rotaciones[i].axis;

        agregar(rotate(radians(angulo), eje));
    }

    unsigned ind_rot = agregar(rotate(radians(angle_rulo_inic), vec3(0.0, 1.0, 0.0)));

    agregar( new ConoRulo(50,50) ); 
    
    rot_rulo = leerPtrMatriz(ind_rot);
}

void Rulo::establecerRotacionRulos(float time)
{
    // Calcular el ángulo de rotación en función del tiempo
    float v_angular = angle_rulo_inic * time;
    *rot_rulo = rotate(radians(v_angular), vec3(0.0, 1.0, 0.0));
} 

unsigned int Rulo::leerNumParametros() const
{
    return num_param;
}

void Rulo::actualizarEstadoParametro(unsigned int iParam, const float t_sec)
{
    assert(iParam <= (leerNumParametros() -1));

    switch (iParam)
    {
    case 0:
        establecerRotacionRulos(t_sec); 
        break;

    }   
}

// Objeto ConoRulo usando en RULO
ConoRulo::ConoRulo
(
    const int num_verts_per, const unsigned nperfiles
)
{
    std::vector<glm::vec3>  perfil_conorulo;

    float h = 0;

    // Añadir el vértice en el centro de la base

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

         
         if (i%2 == 0)
            col_ver.push_back(vec3(0.96, 0.87, 0.70));
        else 
            col_ver.push_back(vec3(0.85, 0.75, 0.55));

      }
   } 

   inicializar(perfil_conorulo, nperfiles);

   
   

}

//-------------------------------------------------------------------------------------------------------------------------
//      PALOMOLINO
//-------------------------------------------------------------------------------------------------------------------------

PaloMolino::PaloMolino(float angle_palo_inic, vec3 pos_palo_inic)
{
    
    angle_palo_ini = angle_palo_inic;
    pos_palo_ini   = pos_palo_inic;
    unsigned int i = agregar( translate(pos_palo_ini) );
    unsigned int j = agregar( rotate(radians(angle_palo_ini), vec3(0.0,1.0,0.0)) );

    agregar( new Palo() );

    rot_palo = leerPtrMatriz(j);

    pos_palo = leerPtrMatriz(i);
}

void PaloMolino::establecerPosicionPalo(const vec3 pos)
{
    *pos_palo = translate(pos_palo_ini+pos);
}

 void PaloMolino::establecerRotacionPalo(float time)
{
    // Calcular el ángulo de rotación en función del tiempo
    float v_angular = (angle_palo_ini) * time;
    *rot_palo = rotate(radians(v_angular), vec3(0.0, 1.0, 0.0));
} 

unsigned PaloMolino::leerNumeroParametros() const
{
    return num_param;
}

void PaloMolino::actualizarEstadoParametro(const unsigned iParam, const float t_sec)
{

    assert(iParam <= leerNumeroParametros()-1);

    switch (iParam)
    {
    
    case 0:
    {
        establecerRotacionPalo(t_sec);
    }
        break;

    case 1:
    {
        const float radio = 0.5f;

        // Velocidad angular en radianes por segundo
        const float velocidadAngular = 1.0f;

        // Calcular la nueva posición del palo en función del tiempo
        float nuevaPosX = radio * cos(velocidadAngular * t_sec);
        float nuevaPosZ = radio * sin(velocidadAngular * t_sec);

        // Construir la nueva posición en el espacio 3D
        vec3 nuevaPosicion = vec3(0.0, 0.0, 0.0) + vec3(nuevaPosX, 0.0f, nuevaPosZ);

        // Establecer la nueva posición del palo
        establecerPosicionPalo(nuevaPosicion);
    }
        break;
    

    }

    
}

// Objeto Palo utilizado en PALOMOLINO

Palo::Palo()
{
    vertices=
    {
        {-0.15,2,+0.15}, //0
        {-0.15,2,-0.15}, //1
        {+0.15,2,-0.15}, //2
        {+0.15,2,+0.15}, //3

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
        if (i%2==0)
           col_ver.push_back(vec3{0.0,0.0,0.0});

        else 
           col_ver.push_back(vec3{0.5,0.5,0.5});



}