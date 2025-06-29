#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GenomicNode {
    char base;
    struct GenomicNode* next;
} GenomicNode;

GenomicNode* createNode(char base) {
    GenomicNode* newNode = (GenomicNode*)malloc(sizeof(GenomicNode));
    if (newNode != NULL) {
        newNode->base = base;
        newNode->next = NULL;
    }
    return newNode;
}

void insertBase(GenomicNode** head, char base) {
    GenomicNode* newNode = createNode(base);
    if (*head == NULL) {
        *head = newNode;
    } else {
        GenomicNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

double calculateGCContent(GenomicNode* head) {
    int gcCount = 0, totalBases = 0;
    while (head != NULL) {
        if (head->base == 'G' || head->base == 'C') gcCount++;
        totalBases++;
        head = head->next;
    }
    return (double)gcCount / totalBases;
}

void predictSecondaryStructure(char* proteinSequence) {
    printf("Protein Secondary Structure Prediction:\n");
    for (int i = 0; i < strlen(proteinSequence); i++) {
        char aa = proteinSequence[i];
        if (aa == 'A' || aa == 'V' || aa == 'L') printf("Helix\n");
        else if (aa == 'D' || aa == 'E' || aa == 'K') printf("Sheet\n");
        else printf("Coil\n");
    }
}

void freeGenomicSequence(GenomicNode* head) {
    GenomicNode* current = head;
    while (current != NULL) {
        GenomicNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    printf("Enter the genomic sequence (A, T, G, C): ");
    char genomicSequenceInput[100];
    fgets(genomicSequenceInput, sizeof(genomicSequenceInput), stdin);

    GenomicNode* genomicSequence = NULL;
    for (int i = 0; i < strlen(genomicSequenceInput); i++) {
        if (genomicSequenceInput[i] != '\n') {
            insertBase(&genomicSequence, genomicSequenceInput[i]);
        }
    }

    double gcContent = calculateGCContent(genomicSequence);
    printf("Genomic GC Content: %.2f%%\n", gcContent * 100);

    printf("Enter the protein sequence: ");
    char proteinSequenceInput[100];
    fgets(proteinSequenceInput, sizeof(proteinSequenceInput), stdin);

    predictSecondaryStructure(proteinSequenceInput);

    freeGenomicSequence(genomicSequence);
    return 0;
}
