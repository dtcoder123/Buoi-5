#include <stdio.h>
#include <string.h>

void move_name_to_front(char *full_name, char *new_name) {
    char *last_space = strrchr(full_name, ' ');

    if (last_space != NULL) {
        // Copy the last name
        strcpy(new_name, last_space + 1);
        strcat(new_name, ", ");

        // Copy the first and middle names
        strncat(new_name, full_name, last_space - full_name);
    } else {
        // If no space is found, just copy the name
        strcpy(new_name, full_name);
    }
}

int main() {
    char name[] = "Nguyen Tran Dinh Thanh";
    char new_name[100]; // Make sure this is large enough to hold the result

    printf("Original name: %s\n", name);

    move_name_to_front(name, new_name);

    printf("Name with last name first: %s\n", new_name);

    return 0;
}
