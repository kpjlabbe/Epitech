/*
 ** Stack.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/Stack.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 1, 2014 2:15:13 AM 2014 kevin labbe
 ** Last update Mar 1, 2014 2:15:13 AM 2014 kevin labbe
 */

#include "EmptyStackException.hpp"
#include "AssertFailedException.hpp"
#include "WrongParameterException.hpp"
#include "Stack.hpp"

namespace Arithmetic
{
  Stack::Stack()
  {
    _funcs["add"] = &Stack::add;
    _funcs["sub"] = &Stack::sub;
    _funcs["mul"] = &Stack::mul;
    _funcs["div"] = &Stack::div;
    _funcs["mod"] = &Stack::mod;
    _funcs["pop"] = &Stack::pop;
    _funcs["dump"] = &Stack::dump;
    _funcs["print"] = &Stack::print;
  }

  Stack::~Stack()
  {
  }

  void
  Stack::execFunc(const std::string& name)
  {
    if (_funcs[name.c_str()])
      (this->*_funcs[name.c_str()])();
  }

  void
  Stack::push(IOperand* op)
  {
    _stack.push_front(op);
  }

  void
  Stack::pop()
  {
    if (_stack.empty())
      throw Exception::EmptyStackException("pop");
    delete _stack.front();
    _stack.pop_front();
  }

  void
  Stack::assert(IOperand* op)
  {
    if (_stack.empty())
      throw Exception::AssertFailedException("Stack empty");
    if (_stack.front()->getPrecision() != op->getPrecision()
        || _stack.front()->getType() != op->getType()
        || _stack.front()->toString() != op->toString())
      throw Exception::AssertFailedException("Operand different at the top of the stack");
  }

  void
  Stack::dump()
  {
    for (std::deque<IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++)
      std::cout << (*it)->toString() << std::endl;
  }

  void
  Stack::print()
  {
    std::stringstream   stream;
    char                chr;
    int                 nbr;

    if (_stack.empty())
      throw Exception::EmptyStackException("print");
    if (_stack.front()->getType() != INT8)
      throw Exception::WrongParameterException("print expects an int8 at the top of the stack");
    stream << _stack.front()->toString();
    stream >> nbr;
    chr = nbr;
    std::cout << chr << std::endl;
  }

  void
  Stack::add()
  {
    _loadOperands();
    _pushResult(*_op1 + *_op2);
  }

  void
  Stack::sub()
  {
    _loadOperands();
    _pushResult(*_op1 - *_op2);
  }

  void
  Stack::mul()
  {
    _loadOperands();
    _pushResult(*_op1 * *_op2);
  }

  void
  Stack::div()
  {
    _loadOperands();
    _pushResult(*_op1 / *_op2);
  }

  void
  Stack::mod()
  {
    _loadOperands();
    _pushResult(*_op1 % *_op2);
  }

  void
  Stack::_loadOperands()
  {
    if (_stack.size() < 2)
      throw Exception::EmptyStackException("Calc");
    _op1 = _stack.front();
    _stack.pop_front();
    _op2 = _stack.front();
    _stack.pop_front();
  }

  void
  Stack::_pushResult(IOperand* result)
  {
    _stack.push_front(result);
    delete _op1;
    delete _op2;
  }

} /* namespace Arithmetic */
