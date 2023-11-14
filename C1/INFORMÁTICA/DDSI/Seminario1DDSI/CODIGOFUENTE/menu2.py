
import tkinter as tk
from tkinter import PhotoImage

class Menu2:
    
    def __init__(self,controlador):
        self.ventana2 = None
        self.controlador = controlador

    def mostrar(self):
        
        # Crear una ventana2
        self.ventana2 = tk.Tk()
        self.ventana2.title("Seminario 1 - Menú 2")
        self.ventana2.geometry("1100x555")

        imagen = PhotoImage(file='fondo-menu2.png')

        # Etiqueta de resultado
        resultado_label = tk.Label(self.ventana2, text="", pady=10, image=imagen)
        resultado_label.pack()
        resultado_label.place(x=0,y=0,width=1100,height=555)

        # Botones de opciones
        boton_1 = tk.Button(self.ventana2, text="Añadir detalle de pedido", background='#f39c12', foreground='white', font=('Lexend',18), command=self.controlador.añadirDetallePedido)  #crear función para añadir detalles de pedido
        boton_1.pack()
        boton_1.place(x=500,y=150,width=500, height=45)

        boton_2 = tk.Button(self.ventana2, text="Eliminar todos los detalles del pedido",background='#18bc9c', foreground='white', font=('Lexend',18), command=self.controlador.eliminarDetalles) #crear función para eliminar detalles del pedido
        boton_2.pack()
        boton_2.place(x=500,y=217,width=500, height=45)

        boton_3 = tk.Button(self.ventana2, text="Eliminar pedido y todos sus detalles", background='#3498db', foreground='white', font=('Lexend',18), command=self.controlador.eliminarDetallesYPedido)
        boton_3.pack()
        boton_3.place(x=500,y=284,width=500, height=45)

        boton_4 = tk.Button(self.ventana2, text="Confirmar todos los cambios",background='#e74c3c', foreground='white', font=('Lexend',18), command=self.controlador.confirmarCambios)
        boton_4.pack()
        boton_4.place(x=500,y=350,width=500, height=45)

        self.ventana2.mainloop()

    def cerrar(self):
        self.ventana2.destroy()
