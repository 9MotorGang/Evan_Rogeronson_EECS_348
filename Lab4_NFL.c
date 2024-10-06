#include <stdio.h>

//main function
int main(void) {
    int score = 10; //initialize score to 10
    printf("Enter 0 or 1 to STOP\n"); //prompt user to stop with 0 or 1
    while(score > 1) { //loop continues while score is greater than 1
        printf("Enter the NFL score: \n"); //ask for an NFL score
        scanf("%d", &score); //get user input for the score
        if(score > 1) { //only process if score is greater than 1
            printf("Possible combinations of scoring plays if a team's score is %d: \n", score); //output prompt with score
            int combinationFound = 0; //flag to check if a combination was found
            int count1 = 0; //initialize counter for touchdowns with 2-point conversion
            int count2 = 0; //initialize counter for touchdowns with field goals
            int count3 = 0; //initialize counter for touchdowns
            int count4 = 0; //initialize counter for 3-point field goals
            int count5 = 0; //initialize counter for safeties
            
            //loop through possible numbers of touchdowns with 2-point conversions
            while(count1 < score/8) {
                count2 = 0; //reset counter for touchdowns with field goals
                while(count2 < score/7) {
                    count3 = 0; //reset counter for touchdowns
                    while(count3 < score/6) {
                        count4 = 0; //reset counter for 3-point field goals
                        while(count4 < score/3) {
                            count5 = 0; //reset counter for safeties
                            while(count5 < score/2) {
                                //check if the combination matches the score
                                if(count1*8+count2*7+count3*6+count4*3+count5*2 == score) {
                                    //print the current combination
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", count1, count2, count3, count4, count5);
                                    combinationFound = 1; //mark that at least one combination was found
                                }
                                count5++; //increment counter for safeties
                            }
                            count4++; //increment counter for 3-point field goals
                        }
                        count3++; //increment counter for touchdowns
                    }
                    count2++; //increment counter for touchdowns with field goals
                }
                count1++; //increment counter for touchdowns with 2-point conversions
            }
            
            //if no valid combinations were found
            if(combinationFound == 0) {
                printf("This score is not possible.\n"); //output that no combinations were found
            }
        }
    }
    return 0; //exit the program
}
