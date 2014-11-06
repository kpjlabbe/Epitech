/*
** main.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/main.cpp
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Feb 26, 2014 1:37:50 AM 2014 kevin labbe
** Last update Feb 26, 2014 1:37:50 AM 2014 kevin labbe
*/

#include <iostream>
#include <cstdlib>

#include "Instruction.hpp"
#include "AvmParser.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "Stack.hpp"
#include "FileNotFoundException.hpp"
#include <iostream>

void    readFile(char *filename)
{
  Parsing::IParser *avm;

  std::ifstream file(filename);
  if (!file.is_open())
    throw Exception::FileNotFoundException(filename);
  avm = new Parsing::AvmParser(file);
  avm->execInstructions();
  delete avm;
}

int     main(int ac, char **av)
{
  Parsing::IParser *avm;

  try {
    if (ac > 1) {
      for (int i = 1; i < ac; i++) {
        if (i > 1)
          std::cout << "----- " << av[i] << " -----" << std::endl;
        readFile(av[i]);
        if ((i + 1) < ac)
          std::cout << std::endl;
      }
    } else {
      avm = new Parsing::AvmParser(std::cin);
      avm->execInstructions();
      delete avm;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return (0);
}
