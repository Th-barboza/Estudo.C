#include <stdio.h>
#define ValMax 1000

int AjuntaLista(int n, int m, int xs[], int ys[], int NovaLista[]){
    for (int i = 1; i < n; i++) {
        if (xs[i] < xs[i - 1]) {
            printf("Não é crescente\n");
            return 1;  // Se encontrar um número menor que o anterior, não é crescente
        }
    }
    for (int i = 1; i < n; i++) {
        if (ys[i] < ys[i - 1]) {
            printf("Não é crescente\n");
            return 1;  // Se encontrar um número menor que o anterior, não é crescente
        }
    }
    
    int i=0, j = 0, k =0;
    //Cria uma nova lista juntando as duas anteriores
    while(j < m && i < n){
        if(xs[i] < ys[j]){
        NovaLista[k] = xs[i];
        i++;
            }else{
            NovaLista[k] = ys[j];
            j++;
        }
        k++;
      } 
    //Coloca os elementos que sobraram do primeiro loop
     while(i<n){
            NovaLista[k] = xs[i];
            i++;
           k++;
      }
      while(j < m){
           NovaLista[k] = ys[j];
           j++;
           k++;
     }
  
      return 0;
}

int main(){
    int xs[ValMax];
    int ys[ValMax];
    int NovaLista[ValMax];
    int n, m;
    
    scanf("%d", &n);
    if (n < 2) {
        printf("lista pequena demais\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &xs[i]);  // Lê cada número e armazena no array xs[]
    }
    scanf("%d", &m);
    if (m < 2) {
        printf("lista pequena demais\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &ys[i]);  // Lê cada número e armazena no array ys[]
    }
    //Chama a função que junta as listas e dps mostra a lista no terminal
    if (AjuntaLista(n, m, xs, ys, NovaLista) != 1){
        for(int i=0; i < n + m;i++){
        printf("%d ", NovaLista[i]);
    }
    printf("\n");
    }
    return 0;
}