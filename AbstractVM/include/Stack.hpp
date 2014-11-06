/*
 ** Stack.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/Stack.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 1, 2014 2:15:12 AM 2014 kevin labbe
 ** Last update Mar 1, 2014 2:15:12 AM 2014 kevin labbe
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "IStack.hpp"
#include <string>
#include <deque>
#include <map>

namespace Arithmetic
{
  class Stack : public IStack
  {
    public:
      Stack();

      virtual
      ~Stack();

      void
      execFunc(const std::string& name);

      void
      push(IOperand* op);

      void
      pop();

      void
      assert(IOperand *op);

      void
      dump();

      void
      print();

      void
      add();

      void
      sub();

      void
      mul();

      void
      div();

      void
      mod();

    private:
      void
      _loadOperands();

      void
      _pushResult(IOperand* result);

    private:
      std::deque<IOperand*>
      _stack;

      std::map<std::string, void (Stack::*)()>
      _funcs;

      IOperand*
      _op1;

      IOperand*
      _op2;
  };
} /* namespace Arithmetic */

#endif /* STACK_HPP_ */
