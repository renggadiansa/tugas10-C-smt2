//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 20
//
//typedef struct {
//    char nrp[10];
//    char nama[20];
//    int kelas;
//} Mahasiswa;
//
//void ShellSort(Mahasiswa arr[], int n) {
//    int gap, i, j;
//    Mahasiswa temp;
//    for (gap = n / 2; gap > 0; gap /= 2) {
//        for (i = gap; i < n; i++) {
//            temp = arr[i];
//            for (j = i; j >= gap && strcmp(arr[j - gap].nrp, temp.nrp) > 0; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//            arr[j] = temp;
//        }
//    }
//}
//
//void Merge(Mahasiswa arr[], int left, int median, int right) {
//    int i, j, k;
//    int n1 = median - left + 1;
//    int n2 = right - median;
//
//    Mahasiswa *L = (Mahasiswa *)malloc(n1 * sizeof(Mahasiswa));
//    Mahasiswa *R = (Mahasiswa *)malloc(n2 * sizeof(Mahasiswa));
//
//    for (i = 0; i < n1; i++)
//        L[i] = arr[left + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[median + 1 + j];
//
//    i = 0;
//    j = 0;
//    k = left;
//    while (i < n1 && j < n2) {
//        if (strcmp(L[i].nrp, R[j].nrp) <= 0) {
//            arr[k] = L[i];
//            i++;
//        } else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//
//    free(L);
//    free(R);
//}
//
//void MergeSort(Mahasiswa arr[], int left, int right) {
//    if (left < right) {
//        int median = left + (right - left) / 2;
//        MergeSort(arr, left, median);
//        MergeSort(arr, median + 1, right);
//        Merge(arr, left, median, right);
//    }
//}
//
//void PrintMahasiswa(Mahasiswa arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("NRP: %s, Nama: %s, Kelas: %d\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
//    }
//}
//
//int soal3() {
//    Mahasiswa data_awal[MAX];
//    int n, i;
//
//    printf("Masukkan jumlah mahasiswa (maksimum %d): ", MAX);
//    scanf("%d", &n);
//    getchar();
//
//    for (i = 0; i < n; i++) {
//        printf("Masukkan data mahasiswa ke-%d:\n", i + 1);
//        printf("NRP: ");
//        fgets(data_awal[i].nrp, sizeof(data_awal[i].nrp), stdin);
//        data_awal[i].nrp[strcspn(data_awal[i].nrp, "\n")] = 0;
//
//        printf("Nama: ");
//        fgets(data_awal[i].nama, sizeof(data_awal[i].nama), stdin);
//        data_awal[i].nama[strcspn(data_awal[i].nama, "\n")] = 0;
//
//        printf("Kelas: ");
//        scanf("%d", &data_awal[i].kelas);
//        getchar();
//    }
//
//    printf("\nData sebelum pengurutan:\n");
//    PrintMahasiswa(data_awal, n);
//
//    Mahasiswa data_urut[MAX];
//    memcpy(data_urut, data_awal, n * sizeof(Mahasiswa));
//
//    printf("\nData setelah Shell Sort berdasarkan NRP:\n");
//    ShellSort(data_urut, n);
//    PrintMahasiswa(data_urut, n);
//
//    memcpy(data_urut, data_awal, n * sizeof(Mahasiswa));
//
//    printf("\nData setelah Merge Sort berdasarkan NRP:\n");
//    MergeSort(data_urut, 0, n - 1);
//    PrintMahasiswa(data_urut, n);
//
//    return 0;
//}
