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
    printf("��/�� �� � ���� �Է� �������?\n");
    scanf("%s", inputCase);
    if (strcmp(inputCase, "��") && strcmp(inputCase, "��")) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 0;
    } 
    printf("��� ����ұ��? 1. ���ϱ� 2. ����\n");
    scanf("%s", inputCal);
    if (strcmp(inputCal, "���ϱ�") && strcmp(inputCal, "����")) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 0;
    } 
    printf("���ڸ� �Է��ϼ���\n");
    scanf("%d", &calInput);

    // Check if the input is an integer
    if (calInput < 0) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 0;
    }

    if (!strcmp(inputCase, "��")) {
        if (!strcmp(inputCal, "���ϱ�")) {
            hour += calInput;
        } else {
            if (hour - calInput < 0) {
                hour = 24 + (hour - calInput);
            } else {
                hour -= calInput;
            }
        }
    } else {
        if (!strcmp(inputCal, "���ϱ�")) {
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
