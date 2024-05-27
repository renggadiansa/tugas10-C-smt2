#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 450000

void InsertionSort(int arr[], int n, int ascending) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int arr[], int n, int ascending) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (ascending ? arr[j] < arr[min_idx] : arr[j] > arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void BubbleSort(int arr[], int n, int ascending) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSortWithFlag(int arr[], int n, int ascending) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

void ShellSort(int arr[], int n, int ascending) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && (ascending ? arr[j - gap] > temp : arr[j - gap] < temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int Partition(int arr[], int p, int r, int ascending) {
    int pivot = arr[p];
    int i = p - 1;
    int j = r + 1;
    int temp;

    while (1) {
        if (ascending) {
            do { j--; } while (arr[j] > pivot);
            do { i++; } while (arr[i] < pivot);
        } else {
            do { j--; } while (arr[j] < pivot);
            do { i++; } while (arr[i] > pivot);
        }

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            return j;
        }
    }
}

void QuickSort(int arr[], int p, int r, int ascending) {
    if (p < r) {
        int q = Partition(arr, p, r, ascending);
        QuickSort(arr, p, q, ascending);
        QuickSort(arr, q + 1, r, ascending);
    }
}

void Merge(int arr[], int left, int median, int right, int ascending) {
    int i, j, k;
    int n1 = median - left + 1;
    int n2 = right - median;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[median + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (ascending ? L[i] <= R[j] : L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void MergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int median = left + (right - left) / 2;
        MergeSort(arr, left, median, ascending);
        MergeSort(arr, median + 1, right, ascending);
        Merge(arr, left, median, right, ascending);
    }
}

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int soal4() {
    int data_awal[MAX];
    int i, algorithm_choice, order_choice;
    int ascending;
    clock_t start, end;
    double milliseconds;

    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        data_awal[i] = rand() % 1000 + 1;
    }

    printf("ALGORITMA SORTING\n");
    printf("1. Insertion\n");
    printf("2. Selection\n");
    printf("3. Bubble\n");
    printf("4. Bubble dengan Flag\n");
    printf("5. Shell\n");
    printf("6. Quick\n");
    printf("7. Merge\n");
    printf("Pilihan : ");
    scanf("%d", &algorithm_choice);

    printf("\n1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan : ");
    scanf("%d", &order_choice);

    ascending = (order_choice == 1) ? 1 : 0;

    int data_urut[MAX];
    memcpy(data_urut, data_awal, MAX * sizeof(int));

    printf("\nData sebelum pengurutan:\n");
    PrintArray(data_urut, MAX);

    start = clock();
    switch (algorithm_choice) {
        case 1:
            InsertionSort(data_urut, MAX, ascending);
            break;
        case 2:
            SelectionSort(data_urut, MAX, ascending);
            break;
        case 3:
            BubbleSort(data_urut, MAX, ascending);
            break;
        case 4:
            BubbleSortWithFlag(data_urut, MAX, ascending);
            break;
        case 5:
            ShellSort(data_urut, MAX, ascending);
            break;
        case 6:
            QuickSort(data_urut, 0, MAX - 1, ascending);
            break;
        case 7:
            MergeSort(data_urut, 0, MAX - 1, ascending);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }
    end = clock();

    milliseconds = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\nData setelah pengurutan:\n");
    PrintArray(data_urut, MAX);

    printf("\nWaktu: %.3f milidetik\n", milliseconds);

    return 0;
}
