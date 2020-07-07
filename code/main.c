#include <stdio.h>
#include <stdlib.h>
#include "include/String.h"

int main() {
    char *str = "aaaaaaae";
    char *pat = "aaae";
    int index = indexOf_KMP(str, pat);
    printf("%d\n", index);
    return 0;
}