#include <stdio.h>
#include <string.h>
#include <ctype.h>

int CoGhiHoa(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            return 1;
        }
    }
    return 0;
}

int DemSoTu(const char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

int contains_char(const char *str, char ch) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            return 1;
        }
    }
    return 0;
}

void TachTen(const char *full_name, char *first_name, char *last_name) {
    char *DauCach = strrchr(full_name, ' ');

    if (DauCach != NULL) {
        strcpy(last_name, DauCach + 1);
        strncpy(first_name, full_name, DauCach - full_name);
        first_name[DauCach - full_name] = '\0';
    } else {
        strcpy(first_name, full_name);
        last_name[0] = '\0';
    }
}

void ChuanHoaChuThuong(char *str) {
    int in_word = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            in_word = 0; // Not in a word
        } else {
            if (!in_word) {
                // Capitalize the first letter of the word
                str[i] = toupper(str[i]);
                in_word = 1;
            } else {
                // Convert other letters to lowercase
                str[i] = tolower(str[i]);
            }
        }
    }
}

int main() {
    char name[] = "Nguyen Tran Dinh Thanh";
    char ch;

    printf("Original name: %s\n", name);

    if (CoGhiHoa(name)) {
        printf("Chuoi co chua ki tu hoa.\n");
    } else {
        printf("Chuoi khong chua ki tu hoa.\n");
    }

    int word_count = DemSoTu(name);
    printf("Chuoi co %d tu.\n", word_count);

    printf("Nhap mot ky tu: ");
    scanf(" %c", &ch); 

    if (contains_char(name, ch)) {
        printf("Ky tu '%c' co trong chuoi.\n", ch);
    } else {
        printf("Ky tu '%c' khong co trong chuoi.\n", ch);
    }

    char full_name[] = "Nguyen Tran Dinh Thanh";
    char first_name[50];
    char last_name[50];

    TachTen(full_name, first_name, last_name);
    printf("Ho: %s\n", first_name);
    printf("Ten: %s\n", last_name);

    ChuanHoaChuThuong(name);
    printf("Ten Thuong: %s\n", name);

    return 0;
}

