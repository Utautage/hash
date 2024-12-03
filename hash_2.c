#include <stdio.h>
#include <string.h>
#define HASH_SIZE 100
#define NAME_SIZE 20
char name[HASH_SIZE][NAME_SIZE];
int hash_func(char str[]) {
    int value = 0;
    for(int index = 0; str[index] != '\0' ; index++) {
        value = value * 2 + str[index];
    }
    return value % HASH_SIZE;
}
int main() {
    char s[NAME_SIZE];
    int index;
    while (1) {
        scanf("%s", s);
        if (s[0] == '.')
            break;
        index = hash_func(s);
        strcpy(name[index], s);
    }
    scanf("%s", s);
    index = hash_func(s);
    printf("%s", name[index]);
}
