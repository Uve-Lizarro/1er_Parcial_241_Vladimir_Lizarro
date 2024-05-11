#include <stdio.h>
//Vladimir Ariel Lizarro Velasquez
int adi_Punteros(int *a, int *b) {
    return *a+*b;
}
int dif_Punteros(int *a, int *b) {
    return *a-*b;
}
int pro_Punteros(int *a, int *b) {
    int r=0;
    int rep=*b;
    int aux=1;
    while (rep>0) {
        r=adi_Punteros(&r,a);
        rep=dif_Punteros(&rep,&aux);
    }
    return r;
}
int coc_Punteros(int *a, int *b) {
    int r=0;
    int rep=*b;
    int aux=1;
	if (*a<rep) {
        int c=*a;
        *a=rep;
        rep=c;
    }
    while (*a>=rep) {
        *a=dif_Punteros(a,&rep);
        r=adi_Punteros(&r,&aux);
    }
    return r;
}
void main() {
    int a, b;
    printf("Leer:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("Adicion: %d\n", adi_Punteros(&a,&b));
    printf("Diferencia: %d\n", dif_Punteros(&a,&b));
    printf("Producto: %d\n", pro_Punteros(&a,&b));
    printf("Division: %d\n", coc_Punteros(&a,&b));
}
