import multiprocessing
#Vladimir Ariel Lizarro Velasquez
def generaSerie(i, n):
    v=[]
    for j in range(n):
        x=(i*n+j+1)*2
        v.append(x)
    return (i, v)

if __name__ == "__main__":
    m=int(input("Numero de vectores: "))
    n=int(input("Numero de terminos: "))
    v=[]
    pool=multiprocessing.Pool(processes=m)
    vR=pool.starmap(generaSerie, [(i, n) for i in range(m)])
    pool.close()
    pool.join()
    vR.sort(key=lambda x: x[0])
    for i, fila in vR:
        v.append(fila)
    for i, fila in enumerate(v):
        print(f"{i}: {' '.join(map(str, fila))}")
