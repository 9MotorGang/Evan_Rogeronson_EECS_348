#include <stdio.h>

int main(void) {
    int score = 10;
    printf("Enter 0 or 1 to STOP\n");
    while(score > 1) {
        printf("Enter the NFL score: \n");
        scanf("%d", &score);
        if(score > 1) {
            printf("Possible combinations of scoring plays if a team's score is 25: \n");
            int combinationFound = 0;
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            int count4 = 0;
            int count5 = 0;
            while(count1 < score/8) {
                count2 = 0;
                while(count2 < score/7) {
                    count3 = 0;
                    while(count3 < score/6) {
                        count4 = 0;
                        while(count4 < score/3) {
                            count5 = 0;
                            while(count5 < score/2) {
                                if(count1*8+count2*7+count3*6+count4*3+count5*2 == score) {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", count1, count2, count3, count4, count5);
                                    combinationFound = 1;
                                }
                                count5++;
                            }
                            count4++;
                        }
                        count3++;
                    }
                    count2++;
                }
                count1++;
            }
            if(combinationFound == 0) {
                printf("This score is not possible.\n");
            }
        }
    }
    printf("Hello, World!\n");
    return 0;
}
