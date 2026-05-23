#include <stdio.h>
#include <stdlib.h>



float calculate(float a, float b, char sign, int *error){
    //*error goes to the address and reads OR writes the value

    switch (sign)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: division by zero\n");
                *error = 1;
                return 0;
            }
            return a / b;
        default:
            printf("Error: unknown operator\n");
            *error = 1;
            return 0;
    }
}


int main(int argc, char *argv[])
{   
    int number_of_word = argc - 1;
    float result;
    /*
    I can use sizeof() to get the size of the entire array and knowing how much a single element of this array
    we can get number of element
    */
    printf("Number of arguments %d\n", number_of_word);
    if (number_of_word == 0)
    {
        printf("Welcome to the CLI calculator you can rather lauch the app by writting '.\\calc 3 + 5' or './calc 3 + 5' \n for direct calculation or when you-e laucnched the app type the calculation\n");
    }
    else
    {
        // string argv[2] != char ;argv[2][0] (switch case works only with int and char)
        int error = 0;
        float a = atof(argv[1]);
        float b = atof(argv[3]);
        char sign = argv[2][0];
        result = calculate(a, b, sign, &error);
        if (error){
            printf("\n");
        }
        else{
            printf("The result is : %f", result);
        }

    }

    return 0;
}
