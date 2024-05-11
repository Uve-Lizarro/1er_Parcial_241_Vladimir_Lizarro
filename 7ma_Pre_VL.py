import multiprocessing
#Vladimir Ariel Lizarro Velasquez
def metodoIntegral(i, j, n):
    s=0.0
    b=1.0/n
    for i in range(i, j):
        x=(i+0.5)*b
        fx=4.0/(1.0+(x*x))
        s+=fx
    return s

def calculoPi(n):
    nroPro=multiprocessing.cpu_count()
    pool=multiprocessing.Pool(processes=nroPro)
    lim=n//nroPro
    vR=[(i*lim, (i+1)*lim) if (i<nroPro-1) else (i*lim,n) for i in range(nroPro)]
    v=pool.starmap(metodoIntegral, [(i, j, n) for i, j in vR])
    pool.close()
    pool.join()
    pi=(sum(v))*1.0/n
    print("Valor de Pi:", pi)

if __name__ == "__main__":
    n=int(input("Numero de iteraciones: "))
    calculoPi(n)
