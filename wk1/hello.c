#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    if (input == 0) return 0;
    for(int i = 0; i < input; i++) {
        for(int j = 0; j < input - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
// 1
// *
// 2
//  * 
// ***
// 3
//   * 
//  ***
// *****