#include <stdio.h>
#include <string.h>
#include <ctype.h>
void predict_gender(const char *name) {
    char name_lower[100];
    strcpy(name_lower, name);
    for (int i = 0; name_lower[i]; i++) {
        name_lower[i] = tolower(name_lower[i]);
    }
    if (strstr(name_lower, "van") != NULL ||strstr(name_lower, "tran") != NULL) {
        printf("Gioi tinh: Nam\n");
    } else if (strstr(name_lower, "thi") != NULL ||strstr(name_lower, "tan") != NULL) {
        printf("Gioi tinh: Nu\n");
    } else {
        printf("Khong doan duoc\n");
    }
}

int main() {
    char name[100];

    printf("Nhap ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    predict_gender(name);

    return 0;
}

