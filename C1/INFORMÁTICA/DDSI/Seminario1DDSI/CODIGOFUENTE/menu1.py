import tkinter as tk
from tkinter import PhotoImage


class Menu1:

    def __init__(self,controlador):
        self.controlador = controlador
        self.ventana = None

    def mostrar(self):
        # Crear una ventana

        self.ventana = tk.Tk()
        self.ventana.title("Seminario 1 - Menú 1")
        self.ventana.geometry("1100x555")

        imagen = PhotoImage(file='fondo-menu1.png')

        # Etiqueta de resultado
        resultado_label = tk.Label(self.ventana, text="", pady=10, image=imagen)
        resultado_label.pack()
        resultado_label.place(x=0,y=0,width=1100,height=555)


        # Botones de opciones
        boton_1 = tk.Button(self.ventana, text="Borrado y reinicio de la base de datos", background='#f39c12', foreground='white', font=('Lexend',18), command=self.controlador.borradoCreacion)  #meter función de la opción 1
        boton_1.pack()
        boton_1.place(x=500,y=150,width=500, height=45)

        boton_2 = tk.Button(self.ventana, text="Alta de pedido", background='#18bc9c', foreground='white', font=('Lexend',18),command=self.controlador.añadirPedido)
        boton_2.pack()
        boton_2.place(x=500,y=217,width=500, height=45)

        boton_3 = tk.Button(self.ventana, text="Mostrar contenido de la base de datos", background='#3498db', foreground='white', font=('Lexend',18), command=self.controlador.consultarDatosBD) #meter funcion para mostrar base de datos
        boton_3.pack()
        boton_3.place(x=500,y=284,width=500, height=45)

        # Botón para salir
        boton_salir = tk.Button(self.ventana, text="Salir", background='#e74c3c', foreground='white', font=('Lexend',18), command=self.cerrar)
        boton_salir.pack()
        boton_salir.place(x=500,y=350,width=500, height=45)

        self.ventana.mainloop()
        

    def cerrar(self):
        self.ventana.destroy()
      















