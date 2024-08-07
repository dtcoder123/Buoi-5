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

int main() {
    char name[] = "Nguyen Tran Dinh Thanh";
    printf("%s\n", name);

    if (CoGhiHoa(name)) {
        printf("Chuoi co chua ki tu hoa.\n");
    } else {
        printf("Chuoi khong chua ki tu hoa.\n");
    }

    return 0;
}

