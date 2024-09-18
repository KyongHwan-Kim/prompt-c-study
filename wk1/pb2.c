#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if the input is an integer
int isNatural(int input) {
    // Check if the input is empty
    if (input < 0) return 0;

    return 1;
}

int main() {
    int hour, minute;
    char inputCase[255];
    char inputCal[255];
    int calInput;

    scanf("%d %d", &hour, &minute);
    printf("시/분 중 어떤 것을 입력 받을까요?\n");
    scanf("%s", inputCase);
    if (strcmp(inputCase, "시") && strcmp(inputCase, "분")) {
        printf("잘못된 입력입니다.\n");
        return 0;
    } 
    printf("어떻게 계산할까요? 1. 더하기 2. 빼기\n");
    scanf("%s", inputCal);
    if (strcmp(inputCal, "더하기") && strcmp(inputCal, "빼기")) {
        printf("잘못된 입력입니다.\n");
        return 0;
    } 
    printf("숫자를 입력하세요\n");
    scanf("%d", &calInput);

    // Check if the input is an integer
    if (calInput < 0) {
        printf("잘못된 입력입니다.\n");
        return 0;
    }

    if (!strcmp(inputCase, "시")) {
        if (!strcmp(inputCal, "더하기")) {
            hour += calInput;
        } else {
            if (hour - calInput < 0) {
                hour = 24 + (hour - calInput);
            } else {
                hour -= calInput;
            }
        }
    } else {
        if (!strcmp(inputCal, "더하기")) {
            minute += calInput;
        } else {
            if (minute - calInput < 0) {
                hour -= 1;
                if (hour < 0) {
                    hour = 23;
                }
                minute = 60 + (minute - calInput);
            } else {
                minute -= calInput;
            }
        }
    }
    if (minute >= 60) {
        while (minute >= 60) {
            hour += 1;
            minute -= 60;
        }
    }
    if (hour >= 24) {
        while (hour >= 24) {
            hour -= 24;
        }
    }
    printf("%d %d", hour, minute);
    return 0;
}
