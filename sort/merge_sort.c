#include <stdio.h>

void print_array(int A[], int first, int last) {
    for (int i = first; i <= last; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void mergeArray(int A[], int first, int last, int mid) {
    int i = first, j = mid + 1;
    printf("Merging: ");
    print_array(A, first, last);
    int count = 0;
    while ((i <= mid) && (j <= last)) {
        if (A[i] <= A[j]) i++;
        else {
            int x = A[j];
            for (int k = j - 1; k >= i; k--)
            {
                A[k+1] = A[k];
            }
            A[i] = x;
            i++;
            j++;
            mid++;
            printf("Step %d: ", ++count);
            print_array(A, first, last);
        }
    }
}

void mergeSort(int A[], int first, int last)
{
    if (first >= last) return;
    int mid = (first + last) / 2;
    mergeSort(A, first, mid); // Slipt the left half
    mergeSort(A, mid + 1, last); // Slipt the right half
    mergeArray(A, first, last, mid); // Merge the two halves
}

int main() {
    int A[] = {5, 2, 8, 1, 3};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Initial array:\n");
    print_array(A, 0, size - 1);
    printf("\n");

    mergeSort(A, 0, size - 1);

    printf("Sorted array:\n");
    print_array(A, 0, size - 1);

    return 0;
}