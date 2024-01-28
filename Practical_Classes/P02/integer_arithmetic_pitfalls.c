//
// Tomás Oliveira e Silva, AED, October 2021
//
// explain the program output
//
// try also compiling the program with the -Wsign-compare compilation flag
//

#include <stdio.h>

int main(void)
{
  unsigned int i = 1;
  int j = -1;
  int k = -2147483648;

  printf("original i = %u\n",i);
  printf("original j = %d\n",j);
  printf("original k = %d\n",k);
  // compare i with j
  if(i > j) // como i é unsigned e j é signed não  faz sentido comparar; a comparação tem de ser feita num dos dominios
    printf("i > j is true\n");
  else
    printf("i > j is false\n");
  // replace k by its absolute value and print the result
  if(k < 0)
    k = -k;
  printf("absolute value of k = %d\n",k); // na impressao o k continua negativo porque em complemento para dois é o numero mais negativo que se pode escrever
                                          // na conversão de bits -8 (1000) >> -(-8) >> 1000 logo -(-8) == -8
  return 0;
}
