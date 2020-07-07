#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/String.h"

int indexOf_BF(char *str, char *pat) {
    int i = 0;
    int j = 0;
    unsigned long long len1 = strlen(str);
    unsigned long long len2 = strlen(pat);
    while (i < len1 && j < len2) {
        if (str[i] == pat[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    int index = -1;
    if (j == len2) index = i - j;
    return index;
}

/**
 * next数组定义
 * j == 0 => next[j] = 0;
 * 最长公共前后子缀存在 => next[j] = 最长公共前后子缀长度;
 * 其他情况 => next[j] = 1;
 * @param pat
 * @return
 */
int* next(char* pat) {
    unsigned long long len = strlen(pat);
    int* next = malloc(sizeof(int) * (len + 1));
    if (next == NULL) {
        printf("NULL Pointer Exception!!!");
        exit(0);
    }
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < len + 1) {
        if (j == 0 || pat[i] == pat[j]) {
            i++;
            j++;
            if (pat[i] != pat[j]) next[i] = j;
            else next[i] = next[j];
        } else j = next[j];
    }
    return next;
}

int indexOf_KMP(char* str, char* pat) {
    int* _next = next(pat);
    int i = 0;
    int j = 0;
    unsigned long long len1 = strlen(str);
    unsigned long long len2 = strlen(pat);
    while (i < len1 && j < len2) {
        if (j == 0 || str[i] == pat[j]) {
            i++;
            j++;
        } else j = _next[j];
    }
    int index = -1;
    if (j == len2) index = i - j;
    return index;
}

