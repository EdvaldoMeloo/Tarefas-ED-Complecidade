#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int n, int vetor[n]);
void heapSort(int n, int vetor[n]);
void build_max_heap(int n, int vetor[n], int tam_heap);
void max_heapify(int n, int vetor[n], int i, int tam_heap);

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
    heapSort(n, vetor);
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

void heapSort(int n, int vetor[n]){
    int i;
    int aux;
    int tam_heap = n-1;

    build_max_heap(n, vetor, tam_heap);

    for(i=n-1; i>0; i--){
        /// Troca dos elementos na pos 1 com a pos 'i'
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        tam_heap -= 1;
        max_heapify(n, vetor, 0, tam_heap);
    }
}

void build_max_heap(int n, int vetor[n], int tam_heap){
    int i;

    for(i=floor((n-1)/2); i>=0; i--){
        max_heapify(n, vetor, i, tam_heap);
    }
}

void max_heapify(int n, int vetor[n], int i, int tam_heap){
    int L, r;
    int maior;
    int aux;

    if(i==0){
        L=1;
        r=2;
    }
    else{
        L = 2*i; /// Filho a esquerda do no i
        r = 2*i+1; /// Filho a direita do no i
    }

    /// Verificando qual no tem o maior valor. O pai ou os seus filhos.
    if(L<=tam_heap && vetor[L]>vetor[i]){
        maior = L;
    }
    else{
        maior = i;
    }
    if(r<=tam_heap && vetor[r]>vetor[maior]){
        maior = r;
    }

    if(maior!=i){
        /// Troca dos elementos na pos 'i' com a pos 'maior'
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;

        max_heapify(n, vetor, maior, tam_heap);
    }
}
