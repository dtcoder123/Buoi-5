#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void VietThuong(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void DemSoTu(const char *str) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int word_count = 0;
    
    char temp_str[MAX_WORD_LENGTH];
    int temp_index = 0;

    for (int i = 0; i <= strlen(str); i++) {
        if (isspace(str[i]) || str[i] == '\0') {
            if (temp_index > 0) {
                temp_str[temp_index] = '\0';
                VietThuong(temp_str);

                int found = 0;
                for (int j = 0; j < word_count; j++) {
                    if (strcmp(words[j], temp_str) == 0) {
                        counts[j]++;
                        found = 1;
                        break;
                    }
                }

                if (!found && word_count < MAX_WORDS) {
                    strcpy(words[word_count], temp_str);
                    counts[word_count] = 1;
                    word_count++;
                }

                temp_index = 0;
            }
        } else {
            temp_str[temp_index++] = str[i];
        }
    }

    printf("Tu dem:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }
}

int main() {
    char name[] = "Nguyen Tran Dinh Thanh";

    printf("Original name: %s\n", name);

    DemSoTu(name);

    return 0;
}

