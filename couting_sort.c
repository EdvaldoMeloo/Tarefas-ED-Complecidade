#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int n, int vetor[n]);
int maiorElemento(int n, int vetor[n]);
void coutingSort(int n, int vetor[n], int B[n], int k);

int main(){
    int n, k;
    int i;

    /// Abrindo o arquivo:
    FILE * arq;
    arq = fopen("couting.txt", "r");

    if(arq == 0){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    fscanf(arq, "%d", &n); /// Obtendo o tamanho do vetor

    /// Obtendo os elementos do vetor:
    int vetor[n];
    for(i=0; i<n; i++){
        fscanf(arq, "%d\n", &vetor[i]);
    }

    fclose(arq);

    /// Ordenando o vetor
    int B[n];
    k = maiorElemento(n, vetor);
    coutingSort(n,vetor,B,k);
    exibeVetor(n, B);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

void exibeVetor(int n, int vetor[n]){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
}

int maiorElemento(int n, int vetor[n]){
    int i, maior;

    maior = vetor[0];

    for(i=1; i<n; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    return maior;
}

void coutingSort(int n, int vetor[n], int B[n], int k){
    int i;
    int C[k+1];

    /// Inicializando o vetor auxiliar com 0
    for(i=0; i<k+1; i++){
        C[i] = 0;
    }

    /// Obtendo a quantidade de cada elemento
    for(i=0; i<n; i++){
        C[vetor[i]] += 1;
    }

    /// Obtendo a posicao Final de cada elemento
    for(i=1; i<=k; i++){
        C[i] += C[i-1];
    }

    /// Ordenando o vetor B
    for(i=n-1; i>=0; i--){
        B[C[vetor[i]]-1] = vetor[i];
        C[vetor[i]] -= 1;
    }
}
