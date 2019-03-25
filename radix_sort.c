#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int n, int vetor[n]);
int maiorElemento(int n, int vetor[n]);
int quantDigitos(int k);
void radixSort(int n, int vetor[n], int d);
void coutingSort(int n, int vetor[n], int B[n], int A[n], int k);
int potencia10(int num);

int main(){
    int n, k, d;
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

    /// Obtendo a quantidade de digitos do vetor
    k = maiorElemento(n, vetor);
    d = quantDigitos(k);

    /// Ordenando o vetor
    radixSort(n, vetor, d);
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

int quantDigitos(int k){
    int d=0;

    if(k==0){
        d = 1;
    }
    else{
        while(k != 0){
            d += 1;
            k = k/10;
        }
    }

    return d;
}

void radixSort(int n, int vetor[n], int d){
    int i, j;
    int C[n], B[n];


    /// Percorre a quantidade de digitos
    for(i=1; i<=d; i++){
        for(j=0; j<n; j++){
            C[j] = vetor[j]%potencia10(i);
            C[j] = C[j]/potencia10(i-1);
        }

        /// Ordenando o vetor de acordo com o digito
        coutingSort(n, C, B, vetor, 9);

        for(j=0; j<n; j++){
            vetor[j] = B[j];
        }
    }
}

void coutingSort(int n, int vetor[n], int B[n], int A[n], int k){
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
        B[C[vetor[i]]-1] = A[i];
        C[vetor[i]] -= 1;
    }
}

int potencia10(int num){
    int i;
    int pot=1;

    for(i=1; i<=num; i++){
        pot = pot * 10;
    }

    return pot;
}
