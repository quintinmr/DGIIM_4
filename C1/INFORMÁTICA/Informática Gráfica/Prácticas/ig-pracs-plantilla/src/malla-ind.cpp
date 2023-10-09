// *********************************************************************
// **
// ** Asignatura: INFORMÁTICA GRÁFICA
// ** 
// ** Mallas indexadas (implementación)
// ** Copyright (C) 2016-2023 Carlos Ureña
// **
// ** Implementación de las clases 
// **        + MallaInd: malla indexada de triángulos (derivada de Objeto3D)
// **        + MallaPLY: malla indexada de triángulos, leída de un PLY (derivada de MallaInd)
// **        + algunas clases derivadas de MallaInd.
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************


#include "ig-aux.h"
#include "aplicacion-ig.h"
#include "malla-ind.h"   // declaración de 'ContextoVis'
#include "lector-ply.h"
#include "seleccion.h"   // para 'ColorDesdeIdent' 


// *****************************************************************************
// funciones auxiliares

// *****************************************************************************
// métodos de la clase MallaInd.

MallaInd::MallaInd()
{
   // nombre por defecto
   ponerNombre("malla indexada, anónima");
}
// -----------------------------------------------------------------------------

MallaInd::MallaInd( const std::string & nombreIni )
{
   // 'identificador' puesto a 0 por defecto, 'centro_oc' puesto a (0,0,0)
   ponerNombre(nombreIni) ;
}

//-----------------------------------------------------------------------------
// calcula la tabla de normales de triángulos una sola vez, si no estaba calculada

void MallaInd::calcularNormalesTriangulos()
{

   
   // si ya está creada la tabla de normales de triángulos, no es necesario volver a crearla
   const unsigned nt = triangulos.size() ;
   assert( 1 <= nt );
   if ( 0 < nor_tri.size() )
   {
      assert( nt == nor_tri.size() );
      return ;
   }

   // COMPLETAR: Práctica 4: creación de la tabla de normales de triángulos
   // ....

}


// -----------------------------------------------------------------------------
// calcula las dos tablas de normales

void MallaInd::calcularNormales()
{
   using namespace glm ;
   // COMPLETAR: en la práctica 4: calculo de las normales de la malla
   // se debe invocar en primer lugar 'calcularNormalesTriangulos'
   // .......


}


// --------------------------------------------------------------------------------------------

void MallaInd::visualizarGL( )
{
   // comprobar algunas precondiciones básicas
   using namespace std ;
   assert( apl != nullptr );
   Cauce * cauce = apl->cauce ; assert( cauce != nullptr );
   CError();

   // si la malla no vértices o no tiene triángulos, imprimir advertencia y salir.
   if ( triangulos.size() == 0 || vertices.size() == 0 )
   {  cout << "advertencia: intentando dibujar malla vacía '" << leerNombre() << "'" << endl << flush ;
      return ;
   }

   // COMPLETAR: práctica 1: cambiar color del cauce
   //
   // Si el objeto tiene un color asignado (se comprueba con 'tieneColor')
   //    - hacer push del color actual del cauce
   //    - fijar el color en el cauce usando el color del objeto (se lee con 'leerColor()')

   if (tieneColor()){

      cauce->pushColor();
      cauce->fijarColor(leerColor());

   }

   // COMPLETAR: práctica 1: crear el descriptor de VAO, si no está creado
   //  Si el puntero 'dvao' es nulo, crear el descriptor de VAO
   //   * en primer lugar se crea el descriptor de VAO, con su constructor 
   //     (se le pasa como parámetro la tabla de posiciones y el número de atributos del cauce). 
   //   * se añade el descriptor de VBO con la tabla de índices (la tabla de triángulos),
   //   * finalmente se añaden al VAO los descriptores VBOs con tablas de atributos 
   //     que no estén vacías
   //  Si el VAO ya está creado, (dvao no nulo), no hay que hacer nada.
   //
   

    if (dvao == nullptr){

      dvao = new DescrVAO(numero_atributos_cauce,
                                        new DescrVBOAtribs(ind_atrib_posiciones, vertices));
     

      dvao->agregar(new DescrVBOInds(triangulos));

      if (!col_ver.empty()) dvao->agregar(new DescrVBOAtribs(ind_atrib_colores, col_ver));
      if (!nor_ver.empty()) dvao->agregar(new DescrVBOAtribs(ind_atrib_normales, nor_ver));
      if (!cc_tt_ver.empty()) dvao->agregar(new DescrVBOAtribs(ind_atrib_coord_text, cc_tt_ver));
   }
    
   // COMPLETAR: práctica 1: visualizar el VAO usando el método 'draw' de 'DescrVAO'

   dvao->draw(GL_TRIANGLES);

   // COMPLETAR: práctica 1: restaurar color anterior del cauce 
   //
   // Si el objeto tiene un color asignado (se comprueba con 'tieneColor')
   //    - hacer 'pop' del color actual del cauce

   if (tieneColor())
      cauce->popColor();

}


// -----------------------------------------------------------------------------
// Visualizar el objeto con OpenGL
// usa las tablas de normales, colores y coordenadas de textura, si no están vacías.
      
void MallaInd::visualizarGeomGL( )
{
   // Comprobar que el descriptor de VAO ya está creado
   // (es decir, este método únicamente se podrá invocar después de que 
   // se haya llamado a 'visualizaGL')
   
   assert( dvao != nullptr );

   // COMPLETAR: práctica 1: visualizar únicamente la geometría del objeto 
  

   //    1. Desactivar todas las tablas de atributos del VAO (que no estén vacías)
   std::vector<bool> tablas_vacias = {true,true,true};
   if (!col_ver.empty()){ tablas_vacias[0] = false; dvao->habilitarAtrib(1,false);}
   if (!nor_ver.empty()){ tablas_vacias[1] = false; dvao->habilitarAtrib(2,false);}
   if (!cc_tt_ver.empty()){ tablas_vacias[2] = false; dvao->habilitarAtrib(3,false);}
  
   //    2. Dibujar la malla (únicamente visualizará los triángulos)
   dvao->draw(GL_TRIANGLES);

   //    3. Volver a activar todos los atributos para los cuales la tabla no esté vacía
   for (unsigned i = 0; i < tablas_vacias.size(); i++){
      if (tablas_vacias[i] == false) dvao->habilitarAtrib(i+1, true);    //!!!!!!
   }


}

// -----------------------------------------------------------------------------
// Visualizar las normales del objeto, si no tiene tabla de normales imprime 
// advertencia y no hace nada.

void MallaInd::visualizarNormalesGL(  )
{
   using namespace std ;
   assert( apl != nullptr );
   Cauce * cauce = apl->cauce ; assert( cauce != nullptr );

   if ( nor_ver.size() == 0 )
   {
      cout << "Advertencia: intentando dibujar normales de una malla que no tiene tabla (" << leerNombre() << ")." << endl ;
      return ;
   }  

   if( nor_ver.size() != vertices.size() )
   {
      cout << "Error visu. normales: tabla de normales no vacía y de tamaño distinto a la de vértices." << endl ;
      cout << "Nombre del objeto        : " << leerNombre() << endl ;
      cout << "Tamaño tabla vértices    : " << vertices.size() << endl ;
      cout << "Tamaño tabla de normales : " << nor_ver.size() << endl ;
      exit(1);
   }
   CError();

   // COMPLETAR: práctica 4: visualizar las normales del objeto MallaInd
   // 
   // *1* Si el puntero al descriptor de VAO de normales ('dvao_normales') es nulo, 
   //    debemos de crear dicho descriptor, con estos pasos:
   //
   //       * Para cada posición 'v_i' de un vértice en el vector 'vertices':
   //             - Leer la correspondiente normal 'n_i' del vector de normales ('nor_ver').
   //             - Añadir 'v_i' al vector 'segmentos_normales'.
   //             - Añadir 'v_i+a*n_i' al vector 'segmentos_normales'.
   //
   //       * Crear el objeto descriptor del VAO de normales, para ello se usa el vector 
   //          'segmentos_normales' y se tiene en cuenta que esa descriptor únicamente gestiona 
   //          una tabla de atributos de vértices (la de posiciones, ya que las otras no se 
   //          necesitan).
   // 
   // *2* Visualizar el VAO de normales, usando el método 'draw' del descriptor, con el 
   //       tipo de primitiva 'GL_LINES'.

   //  ..........

}

// -----------------------------------------------------------------------------
// visualizar el objeto en 'modo seleccion', es decir, sin iluminación y con los colores 
// basados en los identificadores de los objetos
void MallaInd::visualizarModoSeleccionGL() 
{

   using namespace std ;
   assert( apl != nullptr );
   Cauce * cauce = apl->cauce ; assert( cauce != nullptr );

   // COMPLETAR: práctica 5: visualizar la malla en modo selección 
   //
   // Se debe escribir código para visualizar únicamente la geometría, pero usando el color 
   // obtenido a partir del identificador. El código da estos pasos:
   // 
   // 1. Leer el identificador del objeto (con 'leerIdentificador'). Si el objeto tiene 
   //    identificador (es decir, si su identificador no es -1)
   //       + Hacer push del color del cauce, con 'pushColor'.
   //       + Fijar el color del cauce (con 'fijarColor') usando un color obtenido a 
   //         partir del identificador (con 'ColorDesdeIdent'). 
   // 2. Invocar 'visualizarGeomGL' para visualizar la geometría.
   // 3. Si tiene identificador: hacer pop del color, con 'popColor'.
   //

}


// ****************************************************************************
// Clase 'MallaPLY'

MallaPLY::MallaPLY( const std::string & nombre_arch )
{
   ponerNombre( std::string("malla leída del archivo '") + nombre_arch + "'" );

   // COMPLETAR: práctica 2: leer archivo PLY e inicializar la malla
   LeerPLY(nombre_arch, vertices, triangulos);


   // COMPLETAR: práctica 4: invocar  a 'calcularNormales' para el cálculo de normales
   // .................

}

// ****************************************************************************
// Clase 'Cubo

Cubo::Cubo()
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

}

// -----------------------------------------------------------------------------------------------

// Clase Tetraedro
Tetraedro::Tetraedro()
: MallaInd( "tetraedro de 4 vértices")
{
   vertices =
   {
      {+1.0,+1.0,+1.0}, // 0
      {-1.0,-1.0,-1.0}, // 1
      {-1.0,+1.0,-1.0}, // 2
      {+1.0,-1.0,-1.0}  // 3
   };

   triangulos = 
   {
      {0,1,2}, {0,2,3},
      {0,3,1}, {1,2,3}
   };
}

// ****************************************************************************
// Clase 'CuboColores

CuboColores::CuboColores()
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

   col_ver = 
      {
         { 0.0, 0.0, 0.0 }, // 0
         { 0.0, 0.0, +1.0 }, // 1
         { 0.0, +1.0, 0.0 }, // 2
         { 0.0, +1.0, +1.0 }, // 3
         { +1.0, 0.0, 0.0 }, // 4
         { +1.0, 0.0, +1.0 }, // 5
         { +1.0, +1.0, 0.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7

      };

}

// ****************************************************************************
// Clase 'CasaX'

CasaX::CasaX()
:  MallaInd( "Casa Colores" )
{

   vertices =
      {  { 0.0, 0.0, 0.0 }, // 0
         { 0.0, 0.0, +1.0 }, // 1
         { +2.0, 0.0, +1.0 }, // 2
         { +2.0, 0.0, 0.0 }, // 3
         { 0.0, +1.0, +1.0 }, // 4
         { 0.0, +1.0, 0.0 }, // 5
         { +2.0, +1.0, 0.0 }, // 6
         { +2.0, +1.0, +1.0 }, // 7
         { +2.0, +1.5, +0.5 },  // 8
         { 0.0,  +1.5, +0.5 },  // 9
      } ;



   triangulos =
      {  {1,7,4}, {1,7,2},

         {0,6,5}, {0,6,3},

         {2,3,7}, {3,6,7},

         {0,1,4}, {0,5,4},

         {4,8,7}, {4,8,9},

         {5,8,9}, {5,8,6},

         {6,8,7}, {4,9,5}

      } ;

   col_ver = 
      {
         { 0.0, 0.0, 0.0 }, // 0
         { 0.0, 0.0, +1.0 }, // 1
         { +1.0, 0.0, +1.0 }, // 2
         { +1.0, 0.0, 0.0 }, // 3
         { 0.0, +1.0, +1.0 }, // 4
         { 0.0, +1.0, 0.0 }, // 5
         { +1.0, +1.0, 0.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
         { +1.0, +1.0, 0.0}, //8
         { 0.0, +1.0, 0.0 }  // 9

      };

}

EstrellaZ::EstrellaZ(unsigned n)
: MallaInd("Estrella Z")
{

   vertices.push_back({+0.5,+0.5,0.0});
   
   
   for(unsigned i=0; i < 2*n; i+= 2 ){
      vertices.push_back( {float(cos(i*M_PI/n)/2 + 0.5), float(sin(i*M_PI/n)/2 + 0.5), 0} );
      vertices.push_back( {float(cos((i+1)*M_PI/n)/4 + 0.5), float(sin((i+1)*M_PI/n)/4 + 0.5), 0} );
      
   }
   
   for (unsigned j = 0; j < 2*n; j++){
      triangulos.push_back({0,j,j+1});
   }

   triangulos.push_back({0,2*n,1});

   col_ver.push_back({1.0,1.0,1.0}); //Color del centro

   for(unsigned i=0; i < 2*n; i+= 2 ){
      col_ver.push_back( {float(cos(i*M_PI/n)/2 + 0.5), float(sin(i*M_PI/n)/2 + 0.5), 0} );
      col_ver.push_back( {float(cos((i+1)*M_PI/n)/4 + 0.5), float(sin((i+1)*M_PI/n)/4 + 0.5), 0} );
      
   }


};

MallaTriangulo::MallaTriangulo()
:  MallaInd( "Malla Triangulo" )
{
   
   vertices = 
   {
      {-0.5, sqrt(2), 0.0}, // 0
      {+0.5, 0.0, 0.0},     // 1
      {-0.5, 0.0, 0.0}      // 2
   };

   triangulos = 
   {
      {0,2,1}
   };
  
};

MallaCuadrado::MallaCuadrado()
:  MallaInd( "Malla Cuadrado" )
{
   
   vertices = 
   {
      {-1.0, +2.0, 0.0}, // 0
      {+1.0, 0.0, 0.0},  // 1
      {-1.0, 0.0, 0.0},   // 2
      {+1.0, +2.0, 0.0}   // 3
   };

   triangulos = 
   {
      {2,3,0},
      {2,1,3}

   };
  
};

MallaPiramideL::MallaPiramideL()
:  MallaInd( "Malla PiramideL" )
{
   
   vertices = 
   {
      {0.0, 0.0, 0.0},   // 0
      {0.0, 0.0, +1.0},  // 1
      {0.0, 0.0, +2.0},  // 2
      {+1.0, 0.0, +1.0}, // 3
      {+1.0, 0.0, +2.0}, // 4
      {+2.0, 0.0, +1.0}, // 5
      {+2.0, 0.0, 0.0},  // 6
      {+1.0, +2.0, +1.0} // 7
   };

   triangulos = 
   {
      
      {0,2,6}, {2,3,4}, {3,5,6},

      {0,7,2}, {2,4,7},
      {3,4,7}, {3,5,7},
      {5,6,7}, {0,6,7} 
      
   };
  
};

PiramideEstrellaZ::PiramideEstrellaZ(unsigned n)
: MallaInd("PiramideEstrellaZ")
{

   vertices.push_back({+0.5,+0.5,+0.5});
   
   
   for(unsigned i=0; i < 2*n; i+= 2 ){
      vertices.push_back( {float(cos(i*M_PI/n)/2 + 0.5), float(sin(i*M_PI/n)/2 + 0.5), 0} );
      vertices.push_back( {float(cos((i+1)*M_PI/n)/4 + 0.5), float(sin((i+1)*M_PI/n)/4 + 0.5), 0} );
      
   }
   
   for (unsigned j = 0; j < 2*n; j++){
      triangulos.push_back({0,j,j+1});
   }

   triangulos.push_back({0,2*n,1});

   col_ver.push_back({1.0,1.0,1.0}); //Color del centro

   for(unsigned i=0; i < 2*n; i+= 2 ){
      col_ver.push_back( {float(cos(i*M_PI/n)/2 + 0.5), float(sin(i*M_PI/n)/2 + 0.5), 0} );
      col_ver.push_back( {float(cos((i+1)*M_PI/n)/4 + 0.5), float(sin((i+1)*M_PI/n)/4 + 0.5), 0} );
      
   }


};

RejillaY::RejillaY(unsigned m, unsigned n)
: MallaInd("RejillaY")
{

   for (unsigned int i = 0; i < m; i++) {
      for (unsigned int j = 0; j < n; j++) {
            float x = static_cast<float>(i) / static_cast<float>(m - 1);
            float z = static_cast<float>(j) / static_cast<float>(n - 1);
            vertices.push_back(glm::vec3(x, 0.0f, z));
            col_ver.push_back(glm::vec3(x, 0.0f, z));
      }
   }

  

   for (unsigned i = 0; i < m-1; i++ ){
      for (unsigned j = 0; j < n-1; j++){
         triangulos.push_back({j+i*n, j+(i+1)*n, (j+1)+i*n});
         triangulos.push_back({(j+1)+i*n,j+(1+i)*n,(j+1)+(i+1)*n});
      }
   }
   

};


MallaTorre::MallaTorre( unsigned n )
: MallaInd("MallaTorre")
{

   for (unsigned i = 0; i < n+1; i++){

      vertices.push_back(glm::vec3(-0.5,i,+0.5)); //0
      vertices.push_back(glm::vec3(+0.5,i,+0.5)); //1
      vertices.push_back(glm::vec3(+0.5,i,-0.5)); //2
      vertices.push_back(glm::vec3(-0.5,i,-0.5)); //3
      
   }
  
   triangulos.push_back( {0,3,4} );

   for (unsigned j = 0; j < 4*n; j++){

         triangulos.push_back({j, j+1, 4+j });
         triangulos.push_back({j+1, j+4, j+5});
      
   }

   triangulos.push_back( {4*n,4*(n-1)+3,4*n+3} );
};
