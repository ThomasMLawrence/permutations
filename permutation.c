//Michael Lawrence

#include <stdio.h>
#include <string.h>
#include "permutation.h"

int main(int argc, char * argv[])
{
  if(argc == 1 || argc > 2)
  {
    printf("%d", argc);
    fprintf(stderr, "Error: Enter a string to be permuted.\n");
    return 0;
  }
  else
  {
    permutation_wrap(argv[1]);
  }
}

int permutation_wrap(char * input)
{
  int length = 0;
  if(input != NULL)
  {
    length = strlen(input);
  }
  else
  {
    return -1;
  }
  int total = permutation(input, length, 0);
  printf("The total number of permutations is %d.\n", total);
  return 0;
}

int permutation(char * input, int end, int start)
{
  if(start == end)
  {
    printf("%s\n", input);
    return 1;
  }
  int total = 0;
  for(int i = start; i < end; ++i)
  {
    char temp = input[start];
    input[start] = input[i];
    input[i] = temp;
    total += permutation(input, end, start + 1);
    temp = input[start];
    input[start] = input[i];
    input[i] = temp;
  }
  return total;
}
