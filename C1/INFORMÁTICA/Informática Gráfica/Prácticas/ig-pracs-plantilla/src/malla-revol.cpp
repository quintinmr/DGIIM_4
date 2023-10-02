// *********************************************************************
// **
// ** Asignatura: INFORMÁTICA GRÁFICA
// ** 
// ** Mallas indexadas (implementación)
// ** Copyright (C) 2016-2023 Carlos Ureña
// **
// ** Implementación de las clases 
// **    + MallaRevol: malla indexada de triángulos obtenida por 
// **      revolución de un perfil (derivada de MallaInd)
// **    + MallaRevolPLY: malla indexada de triángulos, obtenida 
// **      por revolución de un perfil leído de un PLY (derivada de MallaRevol)
// **    + algunas clases derivadas de MallaRevol
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
#include "lector-ply.h"
#include "malla-revol.h"

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<glm::vec3> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   using namespace glm ;
   
   // COMPLETAR: práctica 2: implementar algoritmo de creación de malla de revolución
   //
   // Escribir el algoritmo de creación de una malla indexada por revolución de un 
   // perfil, según se describe en el guion de prácticas.
   //

   // Partimos de la tabla de vértices vacía.
   std::vector<glm::vec3> vertex;
   unsigned int m = perfil.size();
   unsigned int n = num_copias;

   //Para cada i desde 0 hasta n − 1 (ambos incluidos)
   // • Para cada j desde 0 hasta m − 1 (ambos incluidos)
   //    ◦ Sea q = vértice obtenido rotando pj un ángulo igual a 2πi/(n − 1) radianes.
   //    ◦ Añadir q a la tabla de vértices (al final).

   for (unsigned int i = 0; i < n; i++){

      double angle = (2*M_PI*i)/(n-1);

      for (unsigned int j = 0; j < m; j++){

         double ratio = perfil.at(j).x;
         glm::vec3 q = {ratio*cos(angle), perfil.at(j).y, -ratio*sin(angle)};
         vertex.push_back(q);

      }
   }

   // Partimos de la tabla de triángulos vacía
   // Para cada i desde 0 hasta n − 2 (ambos incluidos)
   //    • Para cada j desde 0 hasta m − 2 (ambos incluidos)
   //         ◦ Sea k = im + j
   //         ◦ Añadir triángulo formado por los índices k, k + m y k + m + 1.
   //         ◦ Añadir triángulo formado por los índices k, k + m + 1 y k + 1.

   std::vector<glm::uvec3> triangles;

   for (unsigned int i = 0; i < n-1; i++){
      for (unsigned int j = 0; j < m-1; j++){
         unsigned int k = i*m+j;
         glm::uvec3 t1 = {k,k+m,k+m+1};
         glm::uvec3 t2 = {k,k+m+1,k+1};
         triangles.push_back(t1);
         triangles.push_back(t2);
      }
   }


}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   // LeerVerticesPLY(nombre_arch,);


}




