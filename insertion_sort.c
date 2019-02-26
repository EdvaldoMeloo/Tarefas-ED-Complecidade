#include <stdio.h>

void exibeVetor(int n, int vetor[n]);
void insertionSort(int n, int vetor[n]);

int main(){
    int n;
    int i;

    /// Lendo o arquivo
    FILE * arq;
    arq = fopen("instancias-num/num.1000.1.in", "r");

    if(arq == 0){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    fscanf(arq, "%d", &n); /// Obtendo o tamanho do array

    int vetor[n];

    /// Obtendo os elementos do vetor
    for(i=0; i<n; i++){
        fscanf(arq, "%d\n", &vetor[i]);
    }

    fclose(arq);

    insertionSort(n, vetor); /// Ordenando o vetor
    exibeVetor(n, vetor); /// Exibindo o vetor

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

void insertionSort(int n, int vetor[n]){
    int pivo;
    int i, j;

    for(i=1; i<=n-1; i++){
        pivo = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>pivo){
            vetor[j+1] = vetor[j];
            j -= 1;
        }
        vetor[j+1] = pivo;
    }
}
