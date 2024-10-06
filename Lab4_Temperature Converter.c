#include <stdio.h>

//function to convert between celsius and fahrenheit
//input: a temperature in celsius
//out: a temperature in fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32; //calculate correct value
    return fahrenheit; //return correct value
}

//function to convert between fahrenheit and celsius
//input: a temperature in fahrenheit
//out: a temperature in celcius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5.0 / 9.0; //calculate correct value
    return celsius; //return correct value
}

//function to convert between celsius and kelvin
//input: a temperature in celsius
//out: a temperature in kelvin
float celsius_to_kelvin(float celsius) {
    float kelvin = (celsius + 273.15); //calculate correct value
    return kelvin; //return correct value
}

//function to convert between kelvin and celsius
//input: a temperature in kelvin
//out: a temperature in celsius
float kelvin_to_celsius(float kelvin) {
    float celsius = (kelvin - 273.15); //calculate correct value
    return celsius; //return correct value
}

//function to convert between kelvin and fahrenheit
//input: a temperature in kelvin
//out: a temperature in fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin); //convert to celsius first
    float fahrenheit = celsius_to_fahrenheit(celsius); //convert to fahrenheit
    return fahrenheit; //return correct value
}

//function to convert between fahrenheit and kelvin
//input: a temperature in fahrenheit
//out: a temperature in kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit); //convert to celsius first
    float kelvin = celsius_to_kelvin(celsius); //convert to kelvin
    return kelvin; //return correct value
}

//main function
int main(void) {
    //intialize varialbes
    float inputTemperature, kelvinTemp, outputTemp; //floats
    int inputType, outputType; //ints
    int valid = 0; //valid to check if the program has output correctly
    while(valid == 0) {
        //ask for a tempature
        printf("Enter the temperature: \n");
        scanf("%f", &inputTemperature); //get user input
        //ask for the intitial tempature type
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        scanf("%d", &inputType); //get user input for initial scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        scanf("%d", &outputType); //get user input for desired scale

        //convert the input to kelvin to use later to determine temperature ranges and if the temperature is valid
        if(inputType == 1) {
            kelvinTemp = celsius_to_kelvin(inputTemperature); //convert from celsius
        }
        else if(inputType == 2) {
            kelvinTemp = fahrenheit_to_kelvin(inputTemperature); //convert from fahrenheit
        }
        else {
            kelvinTemp = inputTemperature; //if input is already in kelvin
        }

        //cehck for errors
        //check if input/output is the same
        if(inputType == outputType) {
            printf("Error: no conversion needed.\n"); //same input and output type
        }
        else if( inputType < 1 || inputType > 3 || outputType < 1 || outputType > 3) {
            printf("Error: temperature type input must between 1 and 3.\n"); //invalid input or output type
        }
        else if (kelvinTemp < 0) {
            printf("Error: temperature below absolute 0.\n"); //temperature too low
        }

        //code for if the input is valid
        else {
            valid = 1; //mark the input as valid
            //find the type of conversion needed
            if(inputType == 1 && outputType == 2 ) {
                outputTemp = celsius_to_fahrenheit(inputTemperature); //celsius to fahrenheit
            }
            else if(inputType == 2 && outputType == 1 ) {
                outputTemp = fahrenheit_to_celsius(inputTemperature); //fahrenheit to celsius
            }
            else if(inputType == 1 && outputType == 3 ) {
                outputTemp = celsius_to_kelvin(inputTemperature); //celsius to kelvin
            }
            else if(inputType == 3 && outputType == 1 ) {
                outputTemp = kelvin_to_celsius(inputTemperature); //kelvin to celsius
            }
            else if(inputType == 2 && outputType == 3 ) {
                outputTemp = fahrenheit_to_kelvin(inputTemperature); //fahrenheit to kelvin
            }
            else if(inputType == 3 && outputType == 2 ) {
                outputTemp = kelvin_to_fahrenheit(inputTemperature); //kelvin to fahrenheit
            }

            //print out the converted temperature
            printf("Converted temperature: %f", outputTemp); //display result

            //print out the proper units for the tempature
            //print celsius
            if(outputType == 1) {
                printf(" C\n"); //celsius
            }
            else if(outputType == 2) {
                printf(" F\n"); //fahrenheit
            }
            else if(outputType == 3) {
                printf("K\n"); //kelvin
            }

            //weather advisory statments
            if(kelvinTemp < 273.15) {
                printf("Temperature category: Freezing\nWeather advisory: Wear a coat.\n"); //cold advisory
            }
            else if(kelvinTemp < 283.15) {
                printf("Temperature category: Cold\nWeather advisory: Wear a light jacket.\n"); //slightly cold
            }
            else if(kelvinTemp < 293.15) {
                printf("Temperature category: Comfortable\nWeather advisory: Enjoy the weather.\n"); //comfortable
            }
            else if(kelvinTemp < 313.15) {
                printf("Temperature category: Hot\nWeather advisory: Drink lots of water.\n"); //hot
            }
            else {
                printf("Temperature category: Extreme Heat\nWeather advisory: Stay inside.\n"); //extremely hot
            }
        }
    }
    return 0; //exit program
}
