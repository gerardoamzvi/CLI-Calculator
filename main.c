#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate(float a, float b, char sign, int *error)
{
    //*error goes to the address and reads OR writes the value

    switch (sign)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
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

void run_from_args(char *argv[])
{
    int error = 0;
    float a = atof(argv[1]);
    float b = atof(argv[3]);
    // string argv[2] != char argv[2][0] (switch case works only with int and char)
    char sign = argv[2][0];
    float result = calculate(a, b, sign, &error);
    if (!error)
    {
        printf("The result is : %f\n", result);
    }
}

void run_interactive()
{

    char buff[100];
    float a, b;
    char sign;
    int error = 0;
    while (1)
    {
        printf("calc> ");
        fgets(buff, 100, stdin);
        if (strncmp(buff, "exit", 4) == 0)
        {
            break;
        }
        int has_all_varaibles = sscanf(buff, "%f %c %f", &a, &sign, &b);

        if (has_all_varaibles == 3)
        {
            float result = calculate(a, b, sign, &error);
            if (!error)
            {
                printf("The result is : %f\n", result);
            }
            result = 0;
        }
        else
        {
            printf("Enter the correct form of cal culation : 3 + 5\n");
        }
        error = 0;
    }
}

int main(int argc, char *argv[])
{
    int number_of_word = argc - 1;
    printf("Number of arguments %d\n", number_of_word);
    if (number_of_word == 0)
    {
        printf("Welcome to the CLI calculator you can rather launch the app by writting '.\\calc 3 + 5' or './calc 3 + 5' \n for direct calculation or when you-e laucnched the app type the calculation\n");
        run_interactive();
    }
    else
    {
        run_from_args(argv);
    }

    return 0;
}
