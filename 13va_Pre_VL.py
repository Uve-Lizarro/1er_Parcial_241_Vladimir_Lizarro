import multiprocessing
#Vladimir Ariel Lizarro Velasquez
MAX_TERMS=100000
class param_Por_Pro:
    def __init__(self, ini, fin):
        self.ini=ini
        self.fin=fin
        self.v=multiprocessing.Array('i', [0]*(fin-ini+1))

def serieFibo(params):
    com=params.ini
    ter=params.fin
    params.v[0]=0
    if (ter-com>=1):
        params.v[1]=1
    for i in range(2, ter-com+1):
        valor=params.v[i-1]+params.v[i-2]
        params.v[i]=valor

def fiboDinamico(n):
    nroPro=multiprocessing.cpu_count()
    nroTerPorHilo=n//nroPro
    nroTerNoExac=n%nroPro
    a=0
    vR=[]
    for tid in range(nroPro):
        b=a+nroTerPorHilo-1
        if (tid<nroTerNoExac):
            b+=1
        vR.append(param_Por_Pro(a, b))
        a=b+1
    aux=[]
    for params in vR:
        vP=multiprocessing.Process(target=serieFibo, args=(params,))
        aux.append(vP)
        vP.start()
    for i in aux:
        i.join()
    for i, dato in enumerate(vR):
        print("Procesador", i, ":", end=" ")
        for j in range(dato.ini, dato.fin + 1):
            print(dato.v[j-dato.ini], end=" ")
        print()

if __name__ == '__main__':
    n=int(input("Tamanio de la Serie: "))
    fiboDinamico(n)