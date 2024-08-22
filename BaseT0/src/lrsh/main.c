#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "../input_manager/manager.h"
#include "../lrsh/hello/hello.h"
#include "../lrsh/sum/sum.h"
#include "../lrsh/is_prime/is_prime.h"



int main(int argc, char const *argv[])
{
  char** input = read_user_input();
  // printf("%s\n", input[0]);

  if (strcmp(input[0], "hello") == 0) {
    hello_command();
  } else if (strcmp(input[0], "sum") == 0) {
    sum_command(input[1], input[2]);
  } else if (strcmp(input[0], "is_prime") == 0) {
    is_prime_command(input[1]);
  } 

  free_user_input(input);
}

