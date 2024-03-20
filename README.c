# Conjuntos-com-Array-vetores-
Conjuntos com Array (vetores)
include <stdio.h>   
#include<math.h>  
#include<Array.h>

void imprimir_array(imprimir_array int ar[], unsigned int qntd); 

{  

printf("Conjuntos com Array (vetores)");(imprimir_array sizeA vectorA sizeB vectorB ());


}  




void inputVector(int vector[], int size) {
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }
}

void printVector(int vector[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("}\n");
}

void unionVectors(int vectorA[], int sizeA, int vectorB[], int sizeB) {
    int unionVector[sizeA + sizeB];
    int unionSize = 0;

    for (int i = 0; i < sizeA; i++) {
        unionVector[unionSize++] = vectorA[i];
    }

    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (vectorB[i] == vectorA[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unionVector[unionSize++] = vectorB[i];
        }
    }

    printf("União dos conjuntos: ");
    printVector(unionVector, unionSize);
}

void intersectionVectors(int vectorA[], int sizeA, int vectorB[], int sizeB) {
    printf("Interseção dos conjuntos: { ");
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (vectorA[i] == vectorB[j]) {
                printf("%d ", vectorA[i]);
                break;
            }
        }
    }
    printf("}\n");
}

void differenceVectors(int vectorA[], int sizeA, int vectorB[], int sizeB) {
    printf("Diferença A - B: { ");
    for (int i = 0; i < sizeA; i++) {
        int found = 0;
        for (int j = 0; j < sizeB; j++) {
            if (vectorA[i] == vectorB[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", vectorA[i]);
        }
    }
    printf("}\n");

    printf("Diferença B - A: { ");
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (vectorB[i] == vectorA[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", vectorB[i]);
        }
    }
    printf("}\n");
}

int main() {
    int sizeA, sizeB;
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &sizeA);

    int vectorA[sizeA];
    inputVector(vectorA, sizeA);

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &sizeB);

    int vectorB[sizeB];
    inputVector(vectorB, sizeB);

    unionVectors(vectorA, sizeA, vectorB, sizeB);
    intersectionVectors(vectorA, sizeA, vectorB, sizeB);
    differenceVectors(vectorA, sizeA, vectorB, sizeB);

    return 0;
}
