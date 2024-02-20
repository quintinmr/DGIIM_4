
import tkinter as tk
from tkinter import PhotoImage

def disable_event():
    pass

class capturaPedido:

    def __init__ (self):
        self.pedido = (None,None,None)
        self.ventanaPedido = None
        self.CPedido_entry = None
        self.CCliente_entry = None
        self.FechaPedido_entry = None


    def capturarDatosPedido(self):

        # self.ventanaPedido window
        self.ventanaPedido = tk.Tk()
        self.ventanaPedido.geometry("1100x555")
        self.ventanaPedido.title('Seminario 1 - Alta Pedido')

        imagen = PhotoImage(file='fondo-menu1.png')

        # Etiqueta de resultado
        resultado_label = tk.Label(self.ventanaPedido, text="", pady=10, image=imagen)
        resultado_label.pack()
        resultado_label.place(x=0,y=0,width=1100,height=555)

        # store CPedido, CCliente, FechaPedido
        CPedido = tk.StringVar()
        CCliente = tk.StringVar()
        FechaPedido = tk.StringVar()

        # CPedido
        CPedido_label = tk.Label(self.ventanaPedido, text="Código del pedido:", background='#f39c12', foreground='white', font=('Lexend',18))
        CPedido_label.pack()
        CPedido_label.place(x=500,y=110,width=500, height=30)

        self.CPedido_entry = tk.Entry(self.ventanaPedido, textvariable=CPedido, font=('Lexend',18))
        self.CPedido_entry.pack()
        self.CPedido_entry.place(x=500,y=145,width=500, height=30)

        # CCliente
        CCliente_label = tk.Label(self.ventanaPedido, text="Código del cliente:", background='#3498db', foreground='white', font=('Lexend',18))
        CCliente_label.pack()
        CCliente_label.place(x=500,y=190,width=500, height=30)

        self.CCliente_entry = tk.Entry(self.ventanaPedido, textvariable=CCliente, font=('Lexend',18))
        self.CCliente_entry.pack()
        self.CCliente_entry.place(x=500,y=225,width=500, height=30)

        # Fecha Pedido
        FechaPedido_label = tk.Label(self.ventanaPedido, text="Fecha del pedido (DD/MM/YYYY):", background='#2c3e50', foreground='white', font=('Lexend',18))
        FechaPedido_label.pack()
        FechaPedido_label.place(x=500,y=270,width=500, height=30)

        self.FechaPedido_entry = tk.Entry(self.ventanaPedido, textvariable=FechaPedido, font=('Lexend',18))
        self.FechaPedido_entry.pack()
        self.FechaPedido_entry.place(x=500,y=305,width=500, height=30)

        # button
        alta_button = tk.Button(self.ventanaPedido, text="Añadir", background='#18bc9c', foreground='white', command=self.button_clicked, font=('Lexend',18))
        alta_button.pack(fill='x', expand=True, pady=10)
        alta_button.place(x=500,y=350,width=500, height=50)

        self.ventanaPedido.mainloop()

    def button_clicked(self):
        self.pedido = (self.CPedido_entry.get(),self.CCliente_entry.get(),self.FechaPedido_entry.get())
        self.ventanaPedido.destroy()


    def getPedido(self):
        return self.pedido