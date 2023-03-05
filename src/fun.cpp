// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    int result = 0;
    bool num = false;
    int begin = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && begin == -1) begin = i;
        if ('0' <= str[i] && str[i] <= '9') num = true;
        if (str[i] == ' ') {
            if (begin != -1 && !num) result++;
            num = false;
            begin = -1;
        }
    }
    if (begin != -1 && !num) result++;
    return result;
}

unsigned int faStr2(const char* str) {
    int result = 0;
    bool flag = true;
    int begin = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (flag && begin != -1) result++;
            begin = -1;
            flag = true;
        } else {
            if (begin == -1) {
                if (!('A' <= str[i] && str[i] <= 'Z')) flag = false;
                begin = i;
            } else {
                if (!('a' <= str[i] && str[i] <= 'z')) flag = false;
            }
        }
    }
    if (flag && begin != -1) result++;
    return result;
}

unsigned int faStr3(const char* str) {
    int result = 0;
    int begin = -1;
    int num = 0, l = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (begin != -1) num++;
            begin = -1;
        } else {
            begin = i;
            l++;
        }
    }
    if (begin != -1) num++;
    int now = (10 * l) / num;
    result = now / 10;
    if (now % 10 >= 5) result++;
    return result;
}
