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
int main() {
    char name[] = "Nguyen Tran Dinh Thanh";
    char ch;
    printf("%s\n", name);

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
    return 0;
}

