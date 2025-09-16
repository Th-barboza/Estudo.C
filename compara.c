#include <stdio.h>
#define MaximoValor 1000

int compara(int n, int m, int xs[], int ys[]){
    int i=0;
    while(i < n && i < m){
    if(xs[i] > ys[i]){
        printf("primeira\n");
        break;
    } else if(ys[i] > xs[i]){
        printf("segunda\n");
        break;
    } 
    
    if(xs[i] == ys[i]){
        i++;   
    }
    if(xs[n-1] == ys[m-1]){
        printf("iguais\n");
    }
    }
    return 0;
}

int main(){
    int xs[MaximoValor];
    int ys[MaximoValor];
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &xs[i]);  // Lê cada número e armazena no array xs[]
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ys[i]);  // Lê cada número e armazena no array ys[]
    }
    compara(n, m, xs, ys);
    return 0;
}