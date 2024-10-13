#include <stdio.h>

//start main
int main(void) {
    //define an array to hold the months of the year
    char months[12][10] = {
        "January  ",
        "February ",
        "March    ",
        "April    ",
        "May      ",
        "June     ",
        "July     ",
        "August   ",
        "September",
        "October  ",
        "November ",
        "December "
    };
    //define an array to hold the sales of each month
    float sales[12];
    //ask for sales each month
    for (int i = 0; i < 12; i++) {
        printf("\nPlease enter the sames amount from month %s\n", months[i]);
        //store the sales
        scanf("%f", &sales[i]);
    }

    //print monthly sales report header
    printf("\n\n\nMonthly Sales Report for 2024\n\nMonth     Sales\n\n");

    //print out sales for each month
    for (int i = 0; i < 12; i++) {
        printf("%s %f\n", months[i],sales[i]);
    }

    //print six-month moving average report header
    printf("\n\n\nSix-Month moving average report:\n\n");

    //calculate and print the six-month moving average for months 1-7
    for (int i = 0; i <7; i++) {
        printf("%s - %s   %f\n",months[i], months[i+5], (sales[i]+ sales[i+1]+ sales[i+2] +sales[i+3] + sales[i+4] + sales[i+5]) / 6.0  );
    }

    //sort the sales and months using bubble sort
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            //swap if the current months sales are greater than the next
            if (sales[j+1] < sales[j]) {
                //swap sales values
                //store one of the values in temp
                float temp = sales[j];
                //replace the next balue into the current value's positon
                sales[j] = sales[j+1];
                //copy temp back into older position
                sales[j+1] = temp;

                //swap the corresponding month names
                char temp2[10];
                //copy current month to temp2
                for (int k = 0; k < 10; k++) {
                    temp2[k] = months[j][k];
                }
                //copy next month into the current month's positon
                for (int k = 0; k < 10; k++) {
                    months[j][k] = months[j+1][k];
                }
                //copy temp2 back into the older positon
                for (int k = 0; k < 10; k++) {
                    months[j+1][k] = temp2[k];
                }
            }
        }
    }

    //print sales report from highest to lowest
    printf("\n\n\nSales report (highest to lowest):\n\nMonth     Sales\n\n");

    //iterate through sorted sales
    for (int i =11; i > -1; i--) {
        printf("%s %f\n", months[i],sales[i]);
    }

    //print sales summary report header
    printf("\n\n\nSales summary report:\n\n");

    //print the month with min sales
    printf("Minimum Sales: %f %s\n",sales[0] ,months[0]);
    //print the month with max sales
    printf("Minimum Sales: %f %s\n",sales[11] ,months[11]);
    //print the average sales
    printf("%f\n", (sales[0]+sales[1]+sales[2]+sales[3]+sales[4]+sales[5]+sales[6]+sales[7]+sales[8]+sales[9]+sales[10]+sales[11])/12.0);

    //end of main function
    return 0;
}
