#include <stdio.h>

void countdown(int n)
{
  while(n > 0){
    printf("%d\n", n--);
  }
  printf("Blast off!\n");
}

void fizzbuzz(int n)
{
  for(int i = 1; i <= n; i++) {
    if(i % 15 == 0)
      printf("Fizz Buzz\n");
    else if(i % 3 == 0)
      printf("Fizz\n");
    else if(i % 5 == 0)
      printf("Buzz\n");
    else
      printf("%d\n", i);
  }
}

char* punc(int i, int modulus, int end)
{
    if(i == end)
      return ".\n";
    else if(i % modulus == 0)
      return ",\n";
    else
      return ", ";
}

void fizzbuzz_compact(int n)
{
  for(int i = 1; i <= n; i++) {
    if(i % 15 == 0)
      printf("Fizz Buzz%s", punc(i, 10, n));
    else if(i % 3 == 0)
      printf("Fizz%s", punc(i, 10, n));
    else if(i % 5 == 0)
      printf("Buzz%s", punc(i, 10, n));
    else
      printf("%d%s", i, punc(i, 10, n));
  }
}


/*
 * Can you make fizzbuzz print out lines that are no longer than a fixed number of characters?
*/

void ascii()
{
  for(int i = 0; i < 26; i++){
    printf("The ASCII code for %c is %d.\n", 'a' + i, 'a' + i);
  }
}


void fizzbuzz2(int n)
{
  int FLAG;
  for(int i = 1; i <= n; i++){
    FLAG = 0;
    if(i % 3 == 0){
      printf("Fizz");
      FLAG = 1;
    }
    if(i % 5 == 0){
      printf("Buzz");
      FLAG = 1;
    }
    if(i % 7 == 0){
      printf("Foo");
      FLAG = 1;
    }
    if(FLAG == 0)
      printf("%d", i);
    printf("\n");
  }
}


int main()
{
  //countdown(3);
  //fizzbuzz(30);
  //fizzbuzz_compact(100);
  //ascii();
  fizzbuzz2(45);
  return 0;
}
