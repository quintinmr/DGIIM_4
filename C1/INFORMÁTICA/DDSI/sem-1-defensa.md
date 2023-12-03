# DEFENSA PRÁCTICA 1 - FLY UGR

En esta práctica, lo que hemos hecho ha sido, en primer lugar pensar un posible sistema de información que podamos desarrollar. Decidimos hacer un sistema de información para la gestión de reservas de vuelo. A continuación, bautizamos dicho SI como *Fly UGR*, e identificamos en él 4 posibles subsistemas, de cada cual, un integrante del grupo se ha hecho responsable. Los cuatro subsistemas son: gestión de usuarios (noura), de vuelos (pablo), de reservas (jose luis) y de pagos (quintin). 

Una vez identificados los subsistemas en los que se divide nuestro sistema, procedimos a elaborar una descripción general y completa del sistema. En ella, especificamos el claro objetivo del SI (permitir al usuario la reserva de un billete de avión y a los usuarios autorizados por la aerolínea, poder gestionar dicho proceso de reserva) así como la información que se iba a almacenar; se almacena información de usuarios, vuelos, aeropuertos, reservas y pagos. De cada uno, se ha especificado con detalle lo que se almacena y en qué formato:

* De cada usuario: nombre, telefono, correo, tarjeta de cŕedito, pasaporte (c.p), saldo.
* De cada aeropuerto: codigo, país, ciudad, telefono contacto.
* De cada vuelo: número de vuelo, código del aeropuerto de origen, código del aeropuerto de destino, número de asientos disponibles, precio de cada asiento, fecha y hora de salida, fecha y hora de llegada.
* De cada reserva: número de reserva, número de pasaporte cliente, número de vuelo, número de asientos reservados, fecha y hora de la reserva, estado de la reserva.
* De cada pago: fecha y hora del pago, número de reserva, identificador del pago, cantidad.

-----------------------------------------------------------------------------
Además, se ha descrito la funcionalidad del sistema; se han especificado y descrito las distintas acciones que permite el sistema realizar a los agentes externos, que son:

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

-------------------------------------------------------------------------------

Se ha elaborado un análisis de requisitos utilizando como metodología el "Análisis conjunto de datos y funciones" (el objetivo de esta metodología es determinar el conjunto de datos y las restricciones sobre los mismos necesarios para el sistema de información),a partir de la funcionalidad descrita del sistema y de la información que se almacena. Se ha elaborado un listado de al menos 5 requisitos funcionales (entendiendo requisito funcional como una funcionalidad del sistema que requiere acceso a la base de datos y para lo cual necesita un agente externo que activa la funcionalidad (y que puede o no aportar datos de entrada), unos datos de la base de datos que hay que consultar (operaciones de lectua), o insertar/modificar/eliminar (operaciones de escritura), y unas acciones de salida que pueden incluir datos de salida que se transmiten a un agente externo ).

Además hemos establecido, para cada subsistema, un listado de restricciones semánticas, asociadas a un requisito funcional y a uno o varios requisitos de datos (una restricción semántica describe cambios en el comportamiento del requisito funcional al que está asociada, cuando se da una consiguración específica en los requisitos de datos).

--------------------------------------------------------------------------------

Finalmente, con objeto de representar gráficamente la evolución de la información dentro del SI, se han elaborado una serie de diagramas de flujo de datos (DFDs), a partir del análisis realizado previamene, que van de menor a mayor grado de detalle o equivalentemente, de mayor a menor nivel de abstracción. Los sucesivos diagramas suponen un refinamiento del anterior. Dichos diagramas son:

* **Esquema de Caja Negra** que representa al SI como un solo proceso, y se indican todos los agentes externos y flujos de datos. En nuestro caso, solo tenemos dos agentes externos: usuario y usuario  de la aerolínea. Los flujos de datos que ponemos entre agentes externos y sistema son los de entrada (del agente al sistema) y salida (del sistema al agente).

* **Esquema de Armazón(DFD0)**, donde hemos representado cada subsistema mediante un único proceso y se incluye el almacén/es correspondiente a la BD, indicando los correspondientes flujos de datos. Entre agentes externos y procesos se ponen solo los flujos de datos de entrada y salida. Los flujos de datos de lectura y escritura se dan entre procesos y almacenes. En la práctica dichos flujos tienen la siguiente explicación:

    * Gestión de usuarios lee del almacén de vuelos y aeropuertos y del almacén de reservas y pagos para mostrar el historial de vuelos de un usuario (lee las reservas y los vuelos asociados a dicha reserva, con la información correspondiente). Escribe y lee en el almacén de usuarios para realizar todas las operaciones que conlleven añadir/modificar  y consultar, respectivamente, la información del usuario.

    * Gestión de vuelos: lee y escribe en el almacén de vuelos y aeropuertos para realizar todas las operaciones de añadir/eliminar vuelos, aeropuertos y modificar/consultar la información de los mismos.
    Lee la de reservas y pagos para obtener las reservas asociadas a un vuelo, si las tuviera, que se va a cancelar.

    * Gestión de reservas: lee y escribe de reservas y pagos para añadir/eliminar/consultar/modificar una reserva. Lee de usuario para cancelar/añadir una reserva y escribe en usuario para cancelar la reserva (tiene que modificar todos los datos de la reserva, de hecho, borrarlos). Lee de vuelos y aeropuertos para añadir/cancelar/actualizar una reserva.

    * Gestión de pagos: lee de usuarios para consultar la tarjeta de cŕedito, el saldo, y el pasaporte del usuario (estos dos últiimos también se consultan en realizar pago) y escribe en usuario para modificar el saldo (al añadir saldo y al realizar el pago). Lee de vuelos y aeropuertos para consultar la información del vuelo asociado a una reserva cuyo pago se va a realizar. Por último lee y escribe de reservas y pagos para consultar la información necesaria de este almacen para realizar el pago (escritura) y para realizar consultas de los mismos.


* **DFD1**, se refina cada subsistema dividiéndolo en procesos, que coinciden con los requisitos funcionales que hemos especificado. De esta forma, nos salen 4 DFD1s, uno por cada subsistema, con tantos procesos como requisitos funcionales hayamos especificado en el análisis. En este diagrama, como en el anterior, se representan los agentes externos, los almacenes que sean necesarios, y los flujos de datos, de entrada y salida (entre agente y proceso y viceversa) y ls flujos de datos de lectura y escritura (entre almacenes y procesos). 

    > Comprobamos que efectivamente se cumplen las propiedades  de consistencia de los refinamientos:
    *  Los flujos de datos entre los procesos que resultan de refinar el proceso del nivel anterior, y los agentes externos y almacenes, contienen los mismos datos que los flujos entre el proceso refinado y los agentes y almacenes.

    * Los refinamientos tienen la misma semántica y funcionalidad que los procesos originales (los que se refinan). Proceso y refinamiento solo pueden diferir en el nivel de detalle con el que están descritos.