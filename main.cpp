#include <iostream>
#include "funcs.h"

int main()
{
  std::cout << solve(encryptCaesar("Hello World", 15)) << std::endl;

  std::cout << "\n" << solve(encryptCaesar("My name is Crystal", 10)) << std::endl;

  std::cout << "\n" << solve(encryptCaesar("My name is Muhammed", 20)) << std::endl;
  
  return 0;
}