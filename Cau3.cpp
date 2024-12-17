#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inputString(char **str) {
    char buffer[1000];
    getchar();
    printf("Nhap vao chuoi : ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(*str, buffer);
}

void reverseString(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc tao\n");
        return;
    }
    int length = strlen(str);
    printf("Chuoi dao nguoc : ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int countWords(char *str) {
    if (str == NULL) return 0;
    int count = 0, inWord = 0;
    while (*str) {
        if (!isspace(*str) && !inWord) {
            inWord = 1;
            count++;
        } else if (isspace(*str)) {
            inWord = 0;
        }
        str++;
    }
    return count;
}

void compareStrings(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc tao\n");
        return;
    }
    char buffer[1000];
    printf("Nhap vao chuoi khac: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    int length1 = strlen(str);
    int length2 = strlen(buffer);
    if (length1 > length2) {
        printf("Chuoi khac ngan hon chuoi ban dau\n");
    } else if (length1 < length2) {
        printf("Chuoi khac dai hon chuoi ban dau\n");
    } else {
        printf("Hai chuoi dai bang nhau\n");
    }
}

void toUpperCase(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc tao\n");
        return;
    }
    while (*str) {
        *str = toupper(*str);
        str++;
    }
    printf("Chuoi sau khi in hoa: %s\n", str);
}

void concatenateStrings(char **str) {
    if (*str == NULL) {
        printf("Chuoi chua duoc tao\n");
        return;
    }
    char buffer[1000];
    printf("Nhap vao chuoi khac: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    *str = (char *)realloc(*str, strlen(*str) + strlen(buffer) + 1);
    strcat(*str, buffer);
    printf("Chuoi sau khi noi: %s\n", *str);
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac , so sanh chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                reverseString(str);
                break;
            case 3:
                if (str != NULL) {
                    printf("So luong tu trong chuoi: %d\n", countWords(str));
                } else {
                    printf("Chuoi chua duoc tao\n");
                }
                break;
            case 4:
                compareStrings(str);
                break;
            case 5:
                toUpperCase(str);
                break;
            case 6:
                concatenateStrings(&str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Vui long choon tu 1 - 7\n");
        }
    } while (choice != 7);

    free(str);
    return 0;
}

