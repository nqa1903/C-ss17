#include <stdio.h>
#include <stdlib.h>

void inputArray(int **arr, int *size) {
    printf("Nhap phan tu cua mang: ");
    scanf("%d", size);
    *arr = (int *)malloc((*size) * sizeof(int));
    for (int i = 0; i < *size; i++) {
        printf("Phan tu [%d]: ", i + 1);
        scanf("%d", (*arr) + i);
    }
}

void displayArray(int *arr, int size) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int calculateLength(int *arr, int size) {
    return size;
}

int calculateSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int findMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int size = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu trong mang va cac phan tu");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputArray(&arr, &size);
                break;
            case 2:
                if (arr != NULL) {
                    displayArray(arr, size);
                } else {
                    printf("Vui long nhap mang\n");
                }
                break;
            case 3:
                printf("Do dai mang: %d\n", calculateLength(arr, size));
                break;
            case 4:
                if (arr != NULL) {
                    printf("Tong cac phan tu trong mang : %d\n", calculateSum(arr, size));
                } else {
                    printf("Vui long nhap mang\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    printf("Phan tu lon nhat trong mang: %d\n", findMax(arr, size));
                } else {
                    printf("Vui long nhap mang\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh \n");
                break;
            default:
                printf("Vui long chon tu 1 - 6\n");
        }
    } while (choice != 6);
    free(arr);
    return 0;
}

