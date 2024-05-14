# **Práctica 3 - Catálogos en implementaciones SGBDR**
----------------------
> Quintín Mesa Romero
>
> Doble Grado en Ingeniería Informática y Matemáticas
> 
> quintinmr@correo.ugr.es
----------------------

# Descripción del sistema gestor de bases de datos

De entre todos los sistemas gestores de bases de datos que se mencionan en el enunciado de la práctica y entre los que no se ha hecho referencia, el único sobre el que tengo algo de conocimiento y con el que he trabajado ya previamente es **MySQL**, de ahí que haya elegido este y no otro. Otras de las razones por las que me he decantado por este SGBD es porque es muy utilizado en la industria, es muy popular, robusto y ha sido y es esencial para aplicaciones web, empresas y proyectos varios.

![mysql](mysql.png)[1]

MySQL es un sistema gestor de bases de datos relacional de código abierto, que fue desarrollado por **Oracle**. Utiliza un modelo de bases de datos relacional, es decir, los datos están organizados en tablas que se relacionan entre sí. Permite almacenar, organizar y recuperar datos de forma eficiente, usando para ello lenguaje **SQL**[1]. 

Está basado en el modelo **cliente-servidor**. Esto es, incluye un servidor de bases de datos, y clientes que interactúan con la base de datos [2]. 

Destaca por ser **portable** (funciona en diferentes sistemas operativos), **flexible** y **escalable**, esto es, por ser capaz de poder adaptarse a las necesidades de las aplicaciones que lo usan, **compatible** con gran cantidad de lenguajes de programación, por tener alto **rendimiento** en cuanto a que permite recuperar los datos de forma rápida y eficiente y por ser **seguro** en cuanto a que garantiza el cifrado de los datos y ofrece opciones de autenticación [1].

# Descripción de los identificadores que MySQL usa para cada objeto creado

Los objetos que permite crear MySQL pueden ser la propia base de datos, tablas, índices, columnas, alias, vistas, procedimientos almacenados, tablaspaces, grupo de recursos, entre otros. Cada uno de ellos está identificado de forma unívoca por un **identificador**.



# Referencias


Información sobre MySQL
[1] https://www.arsys.es/blog/mysql

[2] https://hoplasoftware.com/mysql-sistema-de-gestion-de-bases-de-datos-relacionales/

Identificadores
[3] https://dev.mysql.com/doc/refman/8.3/en/identifiers.html 

