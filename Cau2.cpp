#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inputString(char **str) {
    char buffer[1000];
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(*str, buffer);
}

void printString(char *str) {
    if (str != NULL) {
        printf("Chuoi vua nhap : %s\n", str);
    } else {
        printf("Khong co chuoi duoc tao \n");
    }
}

int countLetters(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countDigits(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countSpecialCharacters(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi và in ra\n");
        printf("4. Dem so luong chu so trong chuoi và in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi và in ra\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                printString(str);
                break;
            case 3:
                if (str != NULL) {
                    printf("So luong chu cai: %d\n", countLetters(str));
                } else {
                    printf("Khong co chuoi duoc tao \n");
                }
                break;
            case 4:
                if (str != NULL) {
                    printf("So luong chu so: %d\n", countDigits(str));
                } else {
                    printf("Khong co chuoi duoc tao \n");
                }
                break;
            case 5:
                if (str != NULL) {
                    printf("So luong ky tu dac biet : %d\n", countSpecialCharacters(str));
                } else {
                    printf("Khong co chuoi duoc tao \n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Vui long chon tu 1 - 6\n");
        }
    } while (choice != 6);
    free(str);
    return 0;
}

