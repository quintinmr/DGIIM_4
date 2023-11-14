
import tkinter as tk
from tkinter import ttk, PhotoImage

class InterfazConsultas:

    def __init__(self) :
        self.ventana = None
    
    def pintaConsultas(self,stock,pedido,detallepedido):

        self.ventana = tk.Tk()
        self.ventana.title("Base de datos")
        self.ventana.geometry("700x700")

        # Etiqueta de resultado
        self.pintaTablaStock(stock)
        self.pintaTablaPedido(pedido)
        self.pintaTablaDetallePedido(detallepedido)

        boton_4 = tk.Button(self.ventana, text="Volver",background='#e74c3c', foreground='white', font=('Lexend',18), command=self.ventana.destroy)
        boton_4.pack()
        boton_4.place(x=300,y=630,width=100, height=45)

        self.ventana.mainloop()


    def pintaTablaStock(self,stock):

        # define columns
        columns = ('CProducto', 'Cantidad')

        titulo_label = tk.Label(self.ventana, text="Tabla Stock", font=('Lexend',18), pady=10)
        titulo_label.pack()

        tree = ttk.Treeview(self.ventana, column=columns, show='headings', height=10)
        
        tree.column("# 1", anchor=tk.CENTER)
        tree.heading("# 1", text="Código de producto")

        tree.column("# 2", anchor=tk.CENTER)
        tree.heading("# 2", text="Cantidad")

        for row in stock:
            tree.insert('', tk.END, values=row)

        tree.pack()

    def pintaTablaPedido(self,pedido):

        # define columns
        columns = ('CPedido', 'CCliente','FechaCliente')

        titulo_label = tk.Label(self.ventana, text="Tabla Pedido", font=('Lexend',18), pady=10)
        titulo_label.pack()

        tree = ttk.Treeview(self.ventana, column=columns, show='headings', height=5)
        
        tree.column("# 1", anchor=tk.CENTER)
        tree.heading("# 1", text="Código de pedido")

        tree.column("# 2", anchor=tk.CENTER)
        tree.heading("# 2", text="Código de cliente")

        tree.column("# 3", anchor=tk.CENTER)
        tree.heading("# 3", text="Fecha del pedido")

        for row in pedido:
            tree.insert('', tk.END, values=row)

        tree.pack()

    def pintaTablaDetallePedido(self,detallepedido):

        # define columns
        columns = ('CPedido', 'CProducto', 'Cantidad')

        titulo_label = tk.Label(self.ventana, text="Tabla Detalle Pedido", font=('Lexend',18), pady=10)
        titulo_label.pack()

        tree = ttk.Treeview(self.ventana, column=columns, show='headings', height=5)
        
        tree.column("# 1", anchor=tk.CENTER)
        tree.heading("# 1", text="Código de pedido")

        tree.column("# 2", anchor=tk.CENTER)
        tree.heading("# 2", text="Código de producto")

        tree.column("# 3", anchor=tk.CENTER)
        tree.heading("# 3", text="Cantidad")

        for row in detallepedido:
            tree.insert('', tk.END, values=row)

        tree.pack()

