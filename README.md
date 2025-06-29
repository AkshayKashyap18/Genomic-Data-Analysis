# 🧬 Genomic Data Analysis

A C-based console application to:
- Dynamically store and analyze DNA sequences
- Calculate GC content
- Predict secondary structure of a protein sequence (Helix, Sheet, Coil)

---

## 📌 Features
- Uses Linked List to handle genomic input dynamically.
- Calculates GC Content from user input.
- Predicts protein secondary structure based on amino acids.
- Memory is dynamically allocated and deallocated to prevent leaks.

---

## Getting Started

### Compile
```bash
gcc main.c -o genomic
```
### Run
```
./genomic
```
## Sample Input
```
Enter the genomic sequence (A, T, G, C): ATGCGCAT
Genomic GC Content: 50.00%

Enter the protein sequence: AVLEKD
Protein Secondary Structure Prediction:
Helix
Helix
Helix
Sheet
Sheet
Sheet
```
## References
Genome.gov - Genomic Data Science

Nature Article on Genomics
