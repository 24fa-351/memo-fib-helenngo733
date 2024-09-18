#include <stdio.h>
#include <stdlib.h>

//Remember that fib(1) = 0. fib(2) = 1 ....

unsigned long memo[100] = {0};

unsigned long int fib_recursive(unsigned long int fib_nth);

unsigned long int fib_recursive_wrapper(unsigned long int fib_nth) {
   if (fib_nth == 1) {
      return 0;
   } else if (fib_nth == 2) {
      return 1;
   }
   return fib_recursive(fib_nth - 1) + fib_recursive(fib_nth - 2);
}

unsigned long int fib_iterative_wrapper(unsigned long int fib_nth) {
   if (fib_nth == 1) {
      return 0;
   } else if (fib_nth == 2) {
      return 1;
   }
   
   unsigned long int prev_num = 0, current_num = 1, temp_next_num;
   for (unsigned long int i = 3; i <= fib_nth; i++) {
      temp_next_num = prev_num + current_num;
      prev_num = current_num;
      current_num = temp_next_num;
   }
   return current_num;
}

unsigned long int fib_recursive(unsigned long int fib_nth) {
   if (memo[fib_nth] == 0) {
      memo[fib_nth] = fib_recursive_wrapper(fib_nth);
   }
   return memo[fib_nth];
}

unsigned long int fib_iterative(unsigned long int fib_nth) {
   if (memo[fib_nth] == 0) {
      memo[fib_nth] = fib_iterative_wrapper(fib_nth);
   }
   return memo[fib_nth];
}

int main (int argc, char *argv[]) {

   unsigned long int fib_nth = strtoul(argv[1], NULL, 10); //handles unsigned long int 
   unsigned long int result;

   if (argv[2][0] == 'r') {
      result = fib_recursive(fib_nth);
   } else if (argv[2][0] == 'i') {
      result = fib_iterative(fib_nth);
   }

   printf("%lu\n", result);
}

