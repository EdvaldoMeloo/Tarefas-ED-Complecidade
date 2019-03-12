#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int n, int vetor[n]);
void quickSort(int n, int vetor[n], int I, int r);
int partition(int n, int vetor[n], int inicio, int fim);

int main(){
    int n;
    int i;

    /// Abrindo o arquivo:
    FILE * arq;
    arq = fopen("instancias-num/num.1000.1.in", "r");

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
    quickSort(n, vetor, 0, n-1);
    exibeVetor(n, vetor);

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

void quickSort(int n, int vetor[n], int I, int r){
    int q;

    if(I<r){
        q = partition(n, vetor, I, r);
        quickSort(n, vetor, I, q-1);
        quickSort(n, vetor, q+1, r);
    }
}

int partition(int n, int vetor[n], int inicio, int fim){
    int pivo, i, j, aux;

    pivo = vetor[inicio];
    i = inicio - 1;
    j = fim + 1;

    while(1){
        do{
            i = i+1;
        }while(vetor[i] <= pivo);

        do{
            j = j-1;
        }while(vetor[j] > pivo);

        if(i >= j){
            break;
        }

        /// Fazendo a troca do elemento em i pelo elemento em j
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }

    /// Fazendo a troca do elemento em inicio pelo elemento em j
    aux = vetor[inicio];
    vetor[inicio] = vetor[j];
    vetor[j] = aux;

    return j;
}
