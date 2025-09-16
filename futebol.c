#include <stdio.h>

#define MAX_TIMES 99 // Número máximo de times
#define MAX_NOME 4 // Tamanho máximo do nome dos times (3 letras + '\0')

// Estrutura para armazenar os dados de cada time
typedef struct {
    char nome[MAX_NOME];
    int pontos;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
    int saldoGols;
} Time;

// Função para inicializar os dados de todos os times
void inicializaTimes(Time times[], int nTimes) {
    for (int i = 0; i < nTimes; i++) {
        times[i].pontos = 0;
        times[i].jogos = 0;
        times[i].vitorias = 0;
        times[i].empates = 0;
        times[i].derrotas = 0;
        times[i].golsPro = 0;
        times[i].golsContra = 0;
        times[i].saldoGols = 0;
    }
}

// Função para encontrar o índice de um time na lista baseado no nome
int encontraTime(Time times[], int nTimes, char nome[]) {
    for (int i = 0; i < nTimes; i++) {
        int iguais = 1;
        // Comparação manual do nome caractere por caractere
        for (int j = 0; j < MAX_NOME; j++) {
            if (times[i].nome[j] != nome[j]) {
                iguais = 0;
                break;
            }
        }
        if (iguais) {
            return i; // Retorna o índice do time encontrado
        }
    }
    return -1; // Retorna -1 se o time não for encontrado
}

// Função para ordenar os times com base nos critérios de desempate
void ordenaTimes(Time times[], int nTimes) {
    for (int i = 0; i < nTimes - 1; i++) {
        for (int j = i + 1; j < nTimes; j++) {
            // Verifica os critérios de desempate em ordem
            if (times[j].pontos > times[i].pontos ||
                (times[j].pontos == times[i].pontos && times[j].vitorias > times[i].vitorias) ||
                (times[j].pontos == times[i].pontos && times[j].vitorias == times[i].vitorias &&
                 times[j].saldoGols > times[i].saldoGols) ||
                (times[j].pontos == times[i].pontos && times[j].vitorias == times[i].vitorias &&
                 times[j].saldoGols == times[i].saldoGols && times[j].golsPro > times[i].golsPro) ||
                (times[j].pontos == times[i].pontos && times[j].vitorias == times[i].vitorias &&
                 times[j].saldoGols == times[i].saldoGols && times[j].golsPro == times[i].golsPro &&
                 times[j].nome[0] < times[i].nome[0])) {
                // Troca os elementos (bubble sort)
                Time temp = times[i];
                times[i] = times[j];
                times[j] = temp;
            }
        }
    }
}

int main() {
    int nTimes, nJogos;
    Time times[MAX_TIMES]; // Array para armazenar os times

    // Leitura do número de times
    scanf("%d", &nTimes);
    for (int i = 0; i < nTimes; i++) {
        scanf("%s", times[i].nome); // Leitura do nome de cada time
    }

    inicializaTimes(times, nTimes);  // Inicializa os dados dos times

    // Leitura do número de jogos e resultados
    scanf("%d", &nJogos);
    for (int i = 0; i < nJogos; i++) {
        char time1[MAX_NOME], time2[MAX_NOME];
        int gols1, gols2;
        scanf("%s %d %d %s", time1, &gols1, &gols2, time2); // Leitura de cada jogo

        // Encontra os índices dos times na tabela
        int idx1 = encontraTime(times, nTimes, time1);
        int idx2 = encontraTime(times, nTimes, time2);

        // Atualiza gols pró e gols contra
        times[idx1].jogos++;
        times[idx2].jogos++;
        times[idx1].golsPro += gols1;
        times[idx2].golsPro += gols2;
        times[idx1].golsContra += gols2;
        times[idx2].golsContra += gols1;

        // Atualiza o saldo de gols
        times[idx1].saldoGols = times[idx1].golsPro - times[idx1].golsContra;
        times[idx2].saldoGols = times[idx2].golsPro - times[idx2].golsContra;
        
        // Atualiza os resultados do jogo
        if (gols1 > gols2) { //vitória do time 1
            times[idx1].pontos += 3;
            times[idx1].vitorias++;
            times[idx2].derrotas++;
        } else if (gols2 > gols1) { //vitória do time 2
            times[idx2].pontos += 3;
            times[idx2].vitorias++;
            times[idx1].derrotas++;
        } else { //empate
            times[idx1].pontos++;
            times[idx2].pontos++;
            times[idx1].empates++;
            times[idx2].empates++;
        }
    }

    // Ordenação dos times pela classificação
    ordenaTimes(times, nTimes);

    // Imprime a tabela final
    printf("          P   J   V   E   D  GP  GC  SG\n");
    for (int i = 0; i < nTimes; i++) {
        printf("%2d. %s %3d %3d %3d %3d %3d %3d %3d %+3d\n",
               i + 1,
               times[i].nome,
               times[i].pontos,
               times[i].jogos,
               times[i].vitorias,
               times[i].empates,
               times[i].derrotas,
               times[i].golsPro,
               times[i].golsContra,
               times[i].saldoGols);
    }

    return 0;
}