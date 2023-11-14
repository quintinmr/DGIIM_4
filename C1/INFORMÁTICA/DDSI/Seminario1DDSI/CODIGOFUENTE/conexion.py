
import pyodbc

def conexionBD():

    SERVER = 'oracle0.ugr.es'
    PORT = '1521'
    DATABASE = 'practbd.oracle0.ugr.es'
    USERNAME = 'x5353611'
    PASSWORD = 'x5353611'

    connection_string = f'DRIVER={{Oracle in instantclient_21_11}};DBQ={SERVER}:{PORT}/{DATABASE};UID={USERNAME};PWD={PASSWORD}'
    return pyodbc.connect(connection_string)

def close(conn):
    conn.close()
