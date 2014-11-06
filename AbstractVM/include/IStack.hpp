/*
** IStack.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/IStack.hpp
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mar 2, 2014 6:28:32 PM 2014 kevin labbe
** Last update Mar 2, 2014 6:28:32 PM 2014 kevin labbe
*/

#ifndef ISTACK_HPP_
#define ISTACK_HPP_

#include "IOperand.hpp"

namespace Arithmetic
{
  class IStack
  {
    public:
      virtual void
      execFunc(const std::string& name) = 0;

      virtual void
      push(IOperand* op) = 0;

      virtual void
      pop() = 0;

      virtual void
      assert(IOperand *op) = 0;

      virtual void
      dump() = 0;

      virtual void
      print() = 0;

      virtual void
      add() = 0;

      virtual void
      sub() = 0;

      virtual void
      mul() = 0;

      virtual void
      div() = 0;

      virtual void
      mod() = 0;

      virtual
      ~IStack() {}
  };
}
#endif /* ISTACK_HPP_ */
