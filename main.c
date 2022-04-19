#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *str = malloc(sizeof(char) * 10);
    char *sec = malloc(sizeof(char) * 20);

    
    str[0] = 'O';
    str[1] = 'k';
    str[20] = 'Y';
//    sec = malloc(sizeof(char) * 20);
    sec[0] = 'Y';
    sec[1] = 'E';
    printf("%s and %s\n", str, sec);
    return 0;
}
