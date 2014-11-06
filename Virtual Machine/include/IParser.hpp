/*
** IParser.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/IParser.hpp
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mar 2, 2014 5:59:17 PM 2014 kevin labbe
** Last update Mar 2, 2014 5:59:17 PM 2014 kevin labbe
*/

#ifndef IPARSER_HPP_
#define IPARSER_HPP_

#include "Instruction.hpp"

namespace Parsing
{
  class IParser
  {
    public:
      virtual void
      execInstructions() = 0;

      virtual const std::deque<Instruction*>&
      getData() const = 0;

      virtual
      ~IParser() {}
  };
}

#endif /* IPARSER_HPP_ */
