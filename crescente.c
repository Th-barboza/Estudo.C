#include <stdio.h>
#define Maximus 1000 //Em honra ao general romano Maximus Decimus Meridius Terceiro
int crescente(int n, int xs[]){
    for (int i = 1; i < n; i++) {
        if (xs[i] < xs[i - 1]) {
            return 0;  // Se encontrar um número menor que o anterior, não é crescente
        }
    }
    return 1;  // A lista é crescente ou igual
}
int decrescente(int n, int xs[]){
    for (int i = 0; i < n - 1; i++) {
        if (xs[i] < xs[i + 1]) {
            return 0; // Retorna 0 se a lista não for decrescente
        }
    }
    return 1; // Retorna 1 se a lista for decrescente
}


int main(){
    int xs[Maximus];
    int n;
 
    scanf("%d", &n);
    if (n < 2) {
        printf("lista pequena demais\n");
        return 0;
    } //Recebe o tamanho da lista

    for (int i = 0; i < n; i++) {
        scanf("%d", &xs[i]);  // Lê cada número e armazena no array xs[]
    }

    
    if (crescente(n, xs)) {
        printf("crescente\n");
    } // Verifica se a lista é crescente
    else if (decrescente(n, xs)) {
        printf("decrescente\n");
    }//se a lista é decrescente
    else {
        printf("fora de ordem\n");
    } // Se não for nenhum dos anteriores a lista está fora de ordem
}