#include <stdio.h>

void print_array(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

int partition_array(int A[], int left, int right, int pivot)
{
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        while (A[l] < A[pivot]) l++;
        while (A[r] > A[pivot]) r--;

        if (l < r)
        {
            swap(&A[l], &A[r]); 
            l++;
            r--;
        }
    }
    swap(&A[left], &A[r]);
    return r;
}

void quick_sort(int A[], int left, int right, int step_count, int size)
{
    if (left >= right)
    {
        return; 
    }
    else
    {
        printf("Step %d: ", step_count);
        print_array(A, size);
        int pivot = left;
        int partition = partition_array(A, left, right, pivot);
        quick_sort(A, left, partition - 1, step_count + 1, size);
        quick_sort(A, partition + 1, right, step_count + 1, size);
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++){
        printf("\nNhap phan tu thu %d: ", i);
        scanf("%d", &A[i]);
    }
    int size = sizeof(A) / sizeof(A[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n\n");

    quick_sort(A, 0, size - 1, 0, n);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n\n");
    return 0;
}
