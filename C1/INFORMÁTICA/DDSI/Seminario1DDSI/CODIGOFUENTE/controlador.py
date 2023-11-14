
import conexion
import pyodbc
import menu1
import menu2
import capturaPedido
import capturaDetallePedido
import datosBD

class Controlador:
    
    def __init__ (self):
        self.conn = conexion.conexionBD()
        self.cursor = self.conn.cursor()

        self.menu1 = menu1.Menu1(self)
        self.menu2 = menu2.Menu2(self)

        self.cp = capturaPedido.capturaPedido()
        self.cdp = capturaDetallePedido.capturaDetallePedido()
        self.datosBD = datosBD.InterfazConsultas()
        self.pedido = ()
        self.detallePedido = ()

    def showMenu1(self):
        self.menu1.mostrar()

    def showMenu2(self):
        self.menu2.mostrar()

    def añadirPedido(self):
        
        self.menu1.cerrar()
        self.pedido = self.capturaDatosPedido()

        try:
            self.cursor.execute("""INSERT INTO PEDIDO (CPEDIDO,CCLIENTE,FECHAPEDIDO) 
                                VALUES (?,?,TO_DATE(?,'DD/MM/YYYY')) """, self.pedido)
        except pyodbc.Error:
            print ("Error al añadir el pedido")
            self.showMenu1()
        else:
            self.savepoint = self.cursor.execute('SAVEPOINT pedido')
            self.showMenu2()

    def añadirDetallePedido(self):
        
        self.menu2.cerrar()
        aux = self.capturaDatosDetallePedido()
        self.detallePedido = (self.pedido[0],aux[0],aux[1])

        self.cursor.execute("SELECT CANTIDAD FROM STOCK WHERE CPRODUCTO=?", self.detallePedido[1])
        consulta = self.cursor.fetchone()

        error = None 

        if (consulta != None and consulta.CANTIDAD >= int(self.detallePedido[2])):
            try:
                self.cursor.execute("""INSERT INTO DETALLEPEDIDO (CPEDIDO,CPRODUCTO,CANTIDAD) 
                                    VALUES (?,?,?) """, self.detallePedido)
            except pyodbc.Error:
                print ("Error al insertar detallePedido")
            else:
                self.cursor.execute("""UPDATE STOCK 
                                   SET CANTIDAD = ? WHERE CPRODUCTO = ?""", consulta.CANTIDAD-int(self.detallePedido[2]), self.detallePedido[1])

        self.consultarDatosBD()
        self.showMenu2()


    def capturaDatosPedido(self):
        self.cp.capturarDatosPedido()
        return self.cp.getPedido()
    
    def capturaDatosDetallePedido(self):
        self.cdp.capturarDatosDetallePedido()
        return self.cdp.getDetallePedido()


    def consultarDatosBD(self):

        self.cursor.execute("""SELECT * FROM STOCK""")
        stock = self.cursor.fetchall()
        stock = [tuple(str(item) for item in t) for t in stock]

        self.cursor.execute("""SELECT * FROM PEDIDO""")
        pedido = self.cursor.fetchall()
        pedido = [tuple(str(item) for item in t) for t in pedido]

        self.cursor.execute("""SELECT * FROM DETALLEPEDIDO""")
        detallepedido = self.cursor.fetchall()
        detallepedido = [tuple(str(item) for item in t) for t in detallepedido]

        self.datosBD.pintaConsultas(stock,pedido,detallepedido)

    def confirmarCambios(self):
        self.menu2.cerrar()
        self.conn.commit()
        self.menu1.mostrar()

    def eliminarDetalles(self):
        self.cursor.execute('ROLLBACK TO SAVEPOINT pedido')
        self.consultarDatosBD()

    def eliminarDetallesYPedido(self):
        self.conn.rollback()
        self.menu2.cerrar()
        self.consultarDatosBD()
        self.menu1.mostrar()

    def borradoCreacion(self):
        SQL_QUERY = "DROP TABLE DETALLEPEDIDO"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "DROP TABLE PEDIDO"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "DROP TABLE STOCK"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "CREATE TABLE PEDIDO( CPedido NUMBER(3) PRIMARY KEY, CCliente NUMBER(5), Fechapedido DATE );"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "CREATE TABLE STOCK( CProducto NUMBER(4) PRIMARY KEY, Cantidad NUMBER(3) CHECK (Cantidad >= 0) );"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "CREATE TABLE DETALLEPEDIDO( CPedido REFERENCES PEDIDO(CPedido),CProducto NUMBER(4) REFERENCES STOCK(CProducto), Cantidad NUMBER(3) CHECK (Cantidad >= 0), PRIMARY KEY(CPedido, CProducto));"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (25,50);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (10,15);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (30,40);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (5,15);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (36,7);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (96,3);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (15,120);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (9,50);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (21,36);"
        self.cursor.execute(SQL_QUERY)        
        SQL_QUERY = "INSERT INTO STOCK (CProducto,Cantidad) VALUES (19,69);"
        self.cursor.execute(SQL_QUERY)        
        self.cursor.commit()

    def cerrarConexion(self):
        self.cursor.close()
        self.conn.close()