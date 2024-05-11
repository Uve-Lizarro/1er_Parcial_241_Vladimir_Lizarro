#include <iostream>
//Vladimir Ariel Lizarro Velasquez
using namespace std;
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
        r=adi_Punteros(&r, a);
        rep=dif_Punteros(&rep, &aux);
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
        *a=dif_Punteros(a, &rep);
        r=adi_Punteros(&r, &aux);
    }
    return r;
}
int main() {
    int a, b;
    cout<<"Leer:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Adicion: "<<adi_Punteros(&a, &b)<<endl;
    cout<<"Diferencia: "<<dif_Punteros(&a, &b)<<endl;
    cout<<"Producto: "<<pro_Punteros(&a, &b)<<endl;
    cout<<"Division: "<<coc_Punteros(&a, &b)<<endl;
    return 0;
}
