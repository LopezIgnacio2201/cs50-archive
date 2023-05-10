#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define NUM_ITEMS 10

typedef struct
{
    string item;
    float price;
}
menu_item;

menu_item menu[NUM_ITEMS];


void add_items(void);

float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }
        total += get_cost(item);
    }
    printf("Your total cost is: $%.2f\n", total);
}

void add_items(void)
{
    string item_names[] = {"Burger", "Vegan Burger", "Hot Dog", "Cheese Dog", "Fries", "Chesee Fries", "Cold Pressed Juice", "Cold Brew", "Water", "Soda" };
    float item_prices[] = {9.5, 11, 5, 7, 5, 6, 7, 3, 2, 2};

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        menu[i].item = item_names[i];
        menu[i].price = item_prices[i];
    }  
    return;
}

float get_cost(string item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        int value = strcmp(menu[i].item, item);
        if (value == 0)
        {
            return menu[i].price;
        }
    }
    return 0;
}