#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

typedef struct 
{
    string name;
    string number;
}
person;


int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "534324432";

    people[1].name = "David";
    people[1].number = "432452343";

    string name = get_string("Name: \n");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found! %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}