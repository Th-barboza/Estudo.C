#include <stdio.h>

#define MAX_PESSOAS 250

// Função para realizar a busca em profundidade (DFS)
void dfs(int pessoa, int visitado[], int matrizAdj[MAX_PESSOAS][MAX_PESSOAS], int totalPessoas) {
    visitado[pessoa] = 1; // Marca a pessoa como visitada

    for (int amigo = 0; amigo < totalPessoas; amigo++) {
        // Se há uma conexão (amizade) e o amigo ainda não foi visitado
        if (matrizAdj[pessoa][amigo] && !visitado[amigo]) {
            dfs(amigo, visitado, matrizAdj, totalPessoas); // Explora o amigo
        }
    }
}

int main() {
    int pessouas, Conequiçoes; // pessouas: número de pessoas, conequiçoes: número de conexões
    scanf("%d %d", &pessouas, &Conequiçoes);

    // Inicializa a matriz de adjacência e o vetor de visitados
    int matrizAdj[MAX_PESSOAS][MAX_PESSOAS] = {0};
    int visitado[MAX_PESSOAS] = {0};

    // Lê as amizades e preenche a matriz de adjacência
    for (int i = 0; i < Conequiçoes; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // Verifica se os índices estão dentro do intervalo válido
        if (a >= 0 && a < pessouas && b >= 0 && b < pessouas) {
            matrizAdj[a][b] = 1;
            matrizAdj[b][a] = 1; // Amizade é bidirecional
        } else {
            printf("Erro: conexão inválida (%d, %d)\n", a, b);
            return 1; // Encerra o programa com erro
        }
    }

    int grupos = 0;

    // Itera sobre todas as pessoas
    for (int i = 0; i < pessouas; i++) {
        if (!visitado[i]) { // Se a pessoa ainda não foi visitada
            grupos++;       // Inicia um novo grupo
            dfs(i, visitado, matrizAdj, pessouas); // Realiza DFS para explorar o grupo
        }
    }

    // Exibe o número de grupos
    printf("%d\n", grupos);

    return 0;
}