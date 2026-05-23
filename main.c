#include <stdio.h>
#include <stdlib.h>

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


        float a = atof(argv[1]);
        float b = atof(argv[3]);

        // string argv[2] != char argv[2][0] (switch case works only with int and char)
        switch (argv[2][0])
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                printf("Error: division by zero\n");
            } 
            else {
                result = a / b;
            }
            break;
        default:
            printf("Error: unknown operator\n");
            break;
        }
        printf("The result is : %f", result);
    }

    return 0;
}