//task 4 #8 P_Mikhail
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
    srand(time(0));
    int num = rand() % 306;
    num -= num % 6;
    
    int counter = 1, userNum = 301, guess = 0;
    do {
        scanf("%d", &userNum);
        printf(userNum < num ? "Bigger\n" : userNum == num? "You win!\n%d attempts" : "Smaller\n",counter);
        if (userNum == num) {
            guess ++;
        }
        ++counter;
    }
    while (guess == 0);
    return 0;
}










