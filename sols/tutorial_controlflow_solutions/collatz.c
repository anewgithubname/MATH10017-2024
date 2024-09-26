#include <stdio.h>

int main()
{
  int num = 67;

  printf("%d\n", num);
  
  while(num > 1){
    if (num % 2 == 0)
      num = num / 2;
    else
      num = 3 * num + 1;
    printf("%d\n",num);
  }
}
