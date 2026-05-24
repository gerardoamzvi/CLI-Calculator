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

void replace_string_by_value(char buff[100], float ans)
{
    // look for ans in buff
    // if (strstr(buff, "ans") != NULL) {
    //  convert ans into string and add to ans_str
    char ans_str[50];
    sprintf(ans_str, "%f", ans);
    // create now buff (string) where we replace the value of ans

    char new_buff[100];
    char *pos = strstr(buff, "ans");
    int before_ans = pos - buff;

    strncpy(new_buff, buff, before_ans);
    new_buff[before_ans] = '\0'; // We are building a string, for that we etell strcat where to start
    strcat(new_buff, ans_str);   // add ans to new buff
    strcat(new_buff, pos + 3);   // The rest of the elements of the buff after ans

    ///
    strcpy(buff, new_buff);

    //}
}
void run_interactive()
{
    char buff[100];
    float a, b;
    char sign;
    int error = 0;
    float ans;
    int has_ans = 0;
    char history[100][200]; // contains history of only 100 calculations
    int counter = 0;
    while (1)
    {
        printf("calc> ");
        fgets(buff, 100, stdin);
        if (strncmp(buff, "exit", 4) == 0)
        {
            break;
        }
        if (strncmp(buff, "history", 7) == 0)
        {
            if (counter == 0)
            {
                printf("The history is currenty empty\n");
            }
            else
            {
                for (int i = 0; i < counter; i++)
                {
                    printf("%s", history[i]);
                }
            }
            continue;
        }

        if (strstr(buff, "ans") != NULL)
        {
            if (has_ans == 0)
            {
                printf("Error : There is no previous answer  you have to make at least one calculation\n");
                continue;
            }
            else
            {
                replace_string_by_value(buff, ans);
            }
        }

        int has_all_varaibles = sscanf(buff, "%f %c %f", &a, &sign, &b);

        if (has_all_varaibles == 3)
        {
            float result = calculate(a, b, sign, &error);
            if (!error)
            {
                printf("The result is : %f\n", result);
                has_ans = 1;
                counter += 1;
                ans = result;
                char history_item[200];
                buff[strcspn(buff, "\n")] = '\0'; // goes at where we have \n and replace it by a \0
                sprintf(history_item, "%d : %s= %f \n", counter, buff, result);
                strcpy(history[counter - 1], history_item);
            }
            result = 0;
        }
        else
        {
            printf("Enter the correct form of calculation : 3 + 5\n");
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
