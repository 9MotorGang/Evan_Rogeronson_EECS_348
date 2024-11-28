// Extra-Credit-Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//created by Evan Rogerson on Nov 27

#include <iostream>
#include <iomanip>
using namespace std;
const int bufferSize = 20;

//this function will get the input
//input: the string from the user
//output: none
void getInput(char input[bufferSize]) {

    //clear the buffer
    for (int count= 0; count < bufferSize; count++) {
        input[count] = 0;
    }

    //recieve input
    cout << "Enter a string (or 'END' to quit): ";
    cin.getline(input, bufferSize);

    // check buffer overflow
    if (cin.fail()) {
        cin.clear(); // clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the whole stream
        cout << "Your input Exceeded the max length of " << bufferSize << " characters.\nEnter a string (or 'END' to quit): ";
        getInput(input);
    }
}

//this function will check if the input is valid or not
//input: the string from the user
//output: whether or not the string is valid
bool isValid(char input[bufferSize]) {
    //check for incorrect +/- placement using ascii value
    for (int count = 1; count < bufferSize; count++) {
        if (input[count] == 43 /*+*/ || input[count] == 45 /*-*/) {
            return false;
        }
    }

    //check for non numeric characters
    for (int count = 0; count < bufferSize; count++) {
        if ((input[count] < 43 && input[count] > 0 /* exclusion for blank space*/) || input[count] == 44 || input[count] == 47 || input[count] > 57) {
            return false;
        }
    }

    //check for more than 1 decimal
    bool decimalSpotted = false;
    for (int count = 0; count < bufferSize; count++) {
        if (input[count] == 46) {
            //check if more than 1 decimal is present
            if (decimalSpotted ==false) {
                decimalSpotted = true;
            }
            else {            
                return false;
            }
        }
    }

    return true;

}

double extractNumeric(char input[]) {
    double output = 0;

    //varialbe to store decimal position
    int decimalPosition = bufferSize -1;

    //find the decimal
    for (int count = 0; count < bufferSize; count++) {
        if (input[count] == 0 || input[count] == 46) {
            decimalPosition = count;
            break;
        }
    }

    int orderOfMagnitude = 10;
    double temp;
    //preform computations right of the decimal
    for (int count = decimalPosition + 1; count < bufferSize; count++) {

        //check for not reading in empty input
        if (input[count] == 0) {
            break;
        }

        //convert from char to decimal
        temp = abs(input[count] - 48);
        output += temp / orderOfMagnitude;
        orderOfMagnitude *= 10;

    }

    orderOfMagnitude = 1;
    //preform computations left of the decimal
    for (int count = decimalPosition -1; count >0 ; count--) {
        //convert from char to decimal
        temp = abs(input[count] - 48);
        output += temp * orderOfMagnitude;
        orderOfMagnitude *= 10;

    }

    //check first character as it may be a value of a sign
    if (input[0] == 45) {
        output *= -1;
    }
    else if (input[0] != 43) {
        temp = abs(input[0] - 48);
        output += temp * orderOfMagnitude;
    }

    //special cases 
    // nunmber begins with decimal
    if (input[0] == 46) {
        output -= 2;
    }
    //number had no input
    if (input[0] == 0) {
        output = 0;
    }
    return output;
}


int main()
{
    char input[bufferSize];

    while (true) {
        getInput(input);

        //check if user wishes to exit the program
        if (input[0] == 'E' && input[1] == 'N' && input[2] == 'D') {
            break;
        }

        //check if input is valid
        if (isValid(input)) {
            //get output
            double output = extractNumeric(input);

            cout << "The input is: " << fixed << setprecision(4) << output << endl << endl;

        }
        else {
            cout << "The input is invalid." << endl;
        }
    }

}

