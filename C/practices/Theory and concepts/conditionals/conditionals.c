#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("What's the value of X?\n");
    int y = get_int("What's the value of Y?\n");

  if (x < y)
  {
    printf("x is less than y\n");
  }
  else if (x > y)
  {
    printf("x is not less than y\n");
  }
  else 
  {
    printf("x is equal to y\n");
  }
}