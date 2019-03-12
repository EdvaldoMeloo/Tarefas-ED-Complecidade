#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void exibeVetor(int n, int vetor[n]);
void mergeSort(int n, int vetor[n], int p, int r);
void merge(int n, int vetor[n], int p, int q, int r);

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
    mergeSort(n, vetor, 0, n-1);
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

void mergeSort(int n, int vetor[n], int p, int r){
    int q;

    if(p<r){
        q = floor((p+r)/2);
        mergeSort(n, vetor, p, q);
        mergeSort(n, vetor, q+1, r);
        merge(n, vetor, p, q, r);
    }
}

void merge(int n, int vetor[n], int p, int q, int r){
    int L[n], R[n];
    int i, k;
    int j=0;

    /// Preenchencdo o vetor L
    for(i=p; i<=q; i++){
        L[j] = vetor[i];
        j=j+1;
    }
    L[j] = INT_MAX;

    /// Preenchendo o vetor R
    j=0;
    for(i=q+1; i<=r; i++){
        R[j] = vetor[i];
        j=j+1;
    }
    R[j] = INT_MAX;

    i=0;
    j=0;

    /// Ordenando
    for(k=p; k<=r; k++){
        if(L[i] < R[j]){
            vetor[k] = L[i];
            i = i+1;
        }
        else{
            vetor[k] = R[j];
            j = j+1;
        }
    }
}
