/*
** IOperandFactory.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/IOperandFactory.hpp
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mar 2, 2014 6:19:30 PM 2014 kevin labbe
** Last update Mar 2, 2014 6:19:30 PM 2014 kevin labbe
*/

#ifndef IOPERANDFACTORY_HPP_
#define IOPERANDFACTORY_HPP_

#include "IOperand.hpp"

namespace Arithmetic
{
  class IOperandFactory
  {
    public:
      virtual IOperand*
      createOperand(eOperandType type, const std::string& value) const = 0;

      virtual
      ~IOperandFactory() {}
  };
}

#endif /* IOPERANDFACTORY_HPP_ */
