#include <stdio.h>
#include <string.h>

int main(void) {
    char str[30] = "happy C programming";

    printf("문자열 \"%s\"의 길이 : %zu\n", str, strlen(str));

    return 0;
}
