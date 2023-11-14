
import tkinter as tk
from tkinter import PhotoImage

def disable_event():
    pass

class capturaDetallePedido:

    def __init__ (self):
        self.detallePedido = (None,None)
        self.ventanaDetallePedido = None
        self.CProducto_entry = None
        self.Cantidad_entry = None


    def capturarDatosDetallePedido(self):

        # self.ventanaDetallePedido window
        self.ventanaDetallePedido = tk.Tk()
        self.ventanaDetallePedido.geometry("1100x555")
        self.ventanaDetallePedido.title('Seminario 1 - Alta Detalle Pedido')

        imagen = PhotoImage(file='fondo-menu1.png')

        # Etiqueta de resultado
        resultado_label = tk.Label(self.ventanaDetallePedido, text="", pady=10, image=imagen)
        resultado_label.pack()
        resultado_label.place(x=0,y=0,width=1100,height=555)

        # store CPedido address and CCliente
        CProducto = tk.StringVar()
        Cantidad = tk.StringVar()

        # CProducto
        CProducto_label = tk.Label(self.ventanaDetallePedido, text="Código de producto:", background='#f39c12', foreground='white', font=('Lexend',18))
        CProducto_label.pack()
        CProducto_label.place(x=500,y=110,width=500, height=30)

        self.CProducto_entry = tk.Entry(self.ventanaDetallePedido, textvariable=CProducto, font=('Lexend',18))
        self.CProducto_entry.pack()
        self.CProducto_entry.place(x=500,y=145,width=500, height=30)

        # Cantidad
        Cantidad_label = tk.Label(self.ventanaDetallePedido, text="Cantidad:", background='#2c3e50', foreground='white', font=('Lexend',18))
        Cantidad_label.pack()
        Cantidad_label.place(x=500,y=270,width=500, height=30)

        self.Cantidad_entry = tk.Entry(self.ventanaDetallePedido, textvariable=Cantidad, font=('Lexend',18))
        self.Cantidad_entry.pack()
        self.Cantidad_entry.place(x=500,y=305,width=500, height=30)

        # button
        alta_button = tk.Button(self.ventanaDetallePedido, text="Añadir", background='#18bc9c', foreground='white', command=self.button_clicked, font=('Lexend',18))
        alta_button.pack()
        alta_button.place(x=500,y=350,width=500, height=50)

        self.ventanaDetallePedido.mainloop()

    def button_clicked(self):
        self.detallePedido = (self.CProducto_entry.get(),self.Cantidad_entry.get())
        self.ventanaDetallePedido.destroy()


    def getDetallePedido(self):
        return self.detallePedido