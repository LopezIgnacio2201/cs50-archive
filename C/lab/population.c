#include <cs50.h>
#include <stdio.h>

int llamasborn(int startingLlamas);
int llamasdie(int startingLlamas);

int main(void)
{
    int startingLlamas, goalLlamas, currentLlamas;
    int yearsTook = 0;

do
{
    startingLlamas = get_int("What is the current population of llamas?\n");
    goalLlamas = get_int("What is the goal population of llamas?\n");

    if (startingLlamas < 9)
    {
        printf("Population cant be less than 9 or it'll go extinct.\n");
    }
    else if (goalLlamas < startingLlamas)
    {
        printf("Population cant be less than desired population.\n");
    }
} while (startingLlamas < 9 || goalLlamas < startingLlamas);


do
{
    currentLlamas = startingLlamas + llamasborn(startingLlamas) - llamasdie(startingLlamas);
    startingLlamas = currentLlamas;
    yearsTook++;
} while (currentLlamas < goalLlamas);

    printf("It took %i years.\n", yearsTook);
}

int llamasborn(int startingLlamas)
{
    return startingLlamas / 3;
}

int llamasdie(int startingLlamas)
{
    return startingLlamas / 4;
}
