#include <stdio.h>

void exibeVetor(int n, int vetor[n]);
void selectionSort(int n, int vetor[n]);

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

    selectionSort(n, vetor); /// Ordenando o vetor
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

void selectionSort(int n, int vetor[n]){
    int i, j;
    int i_min;
    int temp;

    for(i=0; i<=n-1; i++){
        i_min = i;
        for(j=i+1; j<=n-1; j++){
            if(vetor[j] < vetor[i_min]){
                i_min = j;
            }
        }
        if(vetor[i] != vetor[i_min]){
            temp = vetor[i];
            vetor[i] = vetor[i_min];
            vetor[i_min] = temp;
        }
    }
}
