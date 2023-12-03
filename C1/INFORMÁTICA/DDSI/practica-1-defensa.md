Se ha elaborado una descricpión de un Sistema de Información (entendiéndose sistema de información como un sistema informático que utilizan Sistemas Gestores de Bases de Datos (SGBD) como medio para almacenar la
información que procesa el sistema.), para la gestión de reservas de vuelos. En dicha descripción, se ha especificado el objetivo del sistema (permitir al cliente reservar vuelos y al personal autorizado por la aerolínea, gestionar todo el proceso de la reserva) así como también todos los datos que se almacenan de las instancias involucradas en la funcionalidad del sistema: se almacena información de los usuarios, de los aeropuertos, de los vuelos, de las reservas realizadas y de los pagos. De cada uno se ha especificado qué se almacena y el formato en el que se almacena.

* De cada usuario: nombre, telefono, correo, tarjeta de cŕedito, pasaporte (c.p), saldo.
* De cada aeropuerto: codigo, país, ciudad, telefono contacto.
* De cada vuelo: número de vuelo, código del aeropuerto de origen, código del aeropuerto de destino, número de asientos disponibles, precio de cada asiento, fecha y hora de salida, fecha y hora de llegada.
* De cada reserva: número de reserva, número de pasaporte cliente, número de vuelo, número de asientos reservados, fecha y hora de la reserva, estado de la reserva.
* De cada pago: fecha y hora del pago, número de reserva, identificador del pago, cantidad.
 
Seguidamente se han descrito brevemente las distintas funcionalidades del sistema:

**Vuelos**: el sistema permite a usuarios autorizados por la aerolínea:

* Crear: necesita los datos del vuelo

* Actualizar: se puede modificar la fecha y la hora de salida/llegada. Es necesario el número de vuelo.

* Cancelar: se especifica el número de vuelo.

* Consultar vuelos disponibles: los usuarios podran consultar los vuelos disponibles desde un aeropuerto a otro. 

* Consultar información de un vuelo: para lo que el usuario necesita especificar el número de vuelo.

**Aeropuertos**: el sistema permite a los usuarios autorizados por la aerolínea:

* Crear aeropuerto: se necesitan los datos del aeropuerto .

* Eliminar aeropuerto: si no existen vuelos que tengan origen y destino dicho aeropuerto.

* Consultar información de un aeropuerto: un usuario puede consultar la info de un aeropuerto.

**Usuarios**: el sistema permite a los usuarios:

* Crear una cuenta en el sistema: especificando los datos necesarios especificados anteriomente.

Para estos, solo necesita especificar el número de pasaporte:
* Consultar saldo.
* Actualizar información: se permite cambiar (nombre, número de tfo, correo)
* Consultar historial de vuelos

**Reservas**: el sistema permite al usuario:

* Realizar reserva: un usuario registrado puede hacer una reserva mediante: número de pasaporte, número de vuelo y número de asientos a reservar. Una vez se haga la reserva, el estado será "pendiente" de pagar". 
* Modificar reserva: siempre que la reserva no se haya pagado o el vuelo no haya salido, el usuario puede modificar la reserva, aportando el número de la misma y un número de asiento. 
* Cancelar reserva: aportando el número de reserva y se reembolsará si se ha pagado (siempre que el avión no haya salido ya).

**Pagos**: el sistema permite al usuario:

* Añadir saldo: aportando número de pasaporte y cantidad a añadir.
* Pagar reserva: aportando número de reserva. El precio que tendrá que pagar por la reserva se calcula así: **precioAsiento * númeroAsientosReservados**. Se cambia el estado de la reserva a "Pagado".
* Mostrar listado de reservas pendientes de pagar: aportando pasaporte
* Mostrar historial de pagos: aportando pasaporte.
* Consultar información de pago de una reserva: aportando pasaporte + número de reserva.

Por otra parte, teniendo en cuenta que el sistema se divide en 4 subsistemas y teniendo en consideración la descripción realizada del mismo, hemos realizado un análisis de requisitos utilizando como metodología el "Análisis conjunto de datos y funciones". A partir de la descricpicón, de cada subsistema hemos sacado un listado de al menos 5 requisitos funcionales (entendiendo requisito funcional como: una funcionalidad del sistema que requiere acceso a la base de datos y para lo cual necesita: un agente externo al SI que activa la funcionalidad (que puede aportar datos de entrada), unos datos de la base de datos que hay que consultar (lectura), o insertar/modificar/eliminar (escritura), y unas acciones de salida que pueden incluir datos de salida que se transmiten a un agente externo.)

A continuación, una vez hecha la espeficación y análisis de los requisitos de cada subsistema, se presenta un listado con las restricciones semánticas que hemos considerado oportunas (una restricción semántica está relacionada a un requisito funcional y uno o varios requisitos de datos. Las restricciones semánticas describen cambios en el comportamiento del requisito funcional cuando se da una configuración específica en los requisitos de datos. Altera la realización de una función concreta del sistema por alguna configuración de los datos).

Por último, para completar el análisis, se han elaborado Diagramas de Flujo de Datos (DFDs), que son una representación gráfica de la evolución de la información dentro de nuestro Sistema de Información. Antes de describir los diagramas, necesitamos unos conceptos clave:

> *Definición (agente externo)*: un agente externo es una persona, SI u otro sistema activo que se comunica con el SI enviado información y/o recibiendo información. No forman parte del sistema de información pero se comunican con él. Un agente externo NO es una entidad de un conjunto de datos. 

> *Definición (proceso)*: un proceso es una actividad dentro de un sistema, cuyo objetivo es el de generar, usar, manipular o destruir información. En esta práctica serán los requisitos funcionales. 

> *Definición (almacén de datos):* representa un depósito de información dentro del SI, en nuestro caso una base de datos. El SI puede tener varios almacenes de datos.

> *Definición (flujo de datos)*: los flujos de datos representan un intercambio de información entre procesos y otros elementos del DFD: RDE, RDW, RDR, RDS, en la práctica. Si flujo va de proceso a almacén (escritura), si va del almacén al proceso (lectura).

Se pueden utilizar distintos DFDs para describir el SI. EL de mayor nivel de abstracción del SI es el **Esquema de Caja Negra** que representa al SI como un solo proceso, y se indican todos los agentes externos y flujos de datos. En nuestro caso, solo tenemos dos agentes externos: usuario y usuario de la aerolínea. Los flujos de datos que ponemos entre agentes externos y sistema son los de entrada (del agente al sistema) y salida (del sistema al agente).

En el siguiente nivel, está el **Esquema de Armazón(DFD0)**, donde hemos representado cada subsistema mediante un único proceso y se incluye el almacén/es correspondiente a la BD, indicando los correspondientes flujos de datos. EEntre agentes externos y procesos se ponen solo los flujos de datos de entrada y salida. Los flujos de datos de lectura y escritura se dan entre procesos y almacenes. En la práctica dichos flujos tienen la siguiente explicación:

* Gestión de usuarios lee del almacén de vuelos y aeropuertos y del almacén de reservas y pagos para mostrar el historial de vuelos de un usuario (lee las reservas y los vuelos asociados a dicha reserva, con la información correspondiente). Escribe y lee en el almacén de usuarios para realizar todas las operaciones que conlleven añadir/modificar  y consultar, respectivamente, la información del usuario.

* Gestión de vuelos: lee y escribe para realizar todas las operaciones de añadir/eliminar vuelos, aeropuertos y modificar/consultar la información de los mismos.
Lee la de reservas y pagos para obtener las reservas asociadas a un vuelo, si las tuviera, que se va a cancelar.

* Gestión de reservas: lee y escribe de reservas y pagos para añadir/eliminar/consultar/modificar una reserva. Lee de usuario para cancelar/añadir una reserva y escribe en usuario para cancelar la reserva (tiene que modificar todos los datos de la reserva, de hecho, borrarlos). Lee de vuelos y aeropuertos para añadir/cancelar/actualizar una reserva.

* Gestión de pagos: lee de usuarios para consultar la tarjeta de cŕeidito, el saldo, y el pasaporte del usuario (estos dos últiimos también se consultan en realizar pago) y escribe en usuario para modificar el saldo (al añadir saldo y al realizar el pago). Lee de vuelos y aeropuertos para consultar la información del vuelo asociado a una reserva cuyo pago se va a realizar. Por último lee y escribe de reservas y pagos para consultar la información necesaria de este almacen para realizar el pago (escritura) y para realizar consultas de los mismos.

Finalmente se han elaborado los DF1s, se refina cada subsistema dividiéndolo en procesos que coinciden con los requisitos funcionales que hemos especificado y analizado.


