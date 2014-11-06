/*
 ** OperandFactory.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/OperandFactory.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 28, 2014 3:43:29 PM 2014 kevin labbe
 ** Last update Feb 28, 2014 3:43:29 PM 2014 kevin labbe
 */

#include "Operand.hpp"
#include "OperandFactory.hpp"
#include "Utils.hpp"
#include "OutOfRangeException.hpp"

namespace Arithmetic
{

  OperandFactory::OperandFactory()
  {
    _funcs[INT8]    = &OperandFactory::_createInt8;
    _funcs[INT16]   = &OperandFactory::_createInt16;
    _funcs[INT32]   = &OperandFactory::_createInt32;
    _funcs[FLOAT]   = &OperandFactory::_createFloat;
    _funcs[DOUBLE]  = &OperandFactory::_createDouble;
  }

  OperandFactory::~OperandFactory()
  {
  }

  IOperand*
  OperandFactory::createOperand(eOperandType type, const std::string& value) const
  {
    if (type >= INT8 && type <= DOUBLE)
      return ((this->*_funcs[type])(value));
    return (NULL);
  }

  IOperand*
  OperandFactory::_createInt8(const std::string& value) const
  {
    if (Parsing::Utils::isOutOfRange(value, "int8"))
      throw Exception::OutOfRangeException(value);
    return (new Operand<char>(value, INT8));
  }

  IOperand*
  OperandFactory::_createInt16(const std::string& value) const
  {
    if (Parsing::Utils::isOutOfRange(value, "int16"))
          throw Exception::OutOfRangeException(value);
    return (new Operand<short int>(value, INT16));
  }

  IOperand*
  OperandFactory::_createInt32(const std::string& value) const
  {
    if (Parsing::Utils::isOutOfRange(value, "int32"))
          throw Exception::OutOfRangeException(value);
    return (new Operand<int>(value, INT32));
  }

  IOperand*
  OperandFactory::_createFloat(const std::string& value) const
  {
    if (Parsing::Utils::isOutOfRange(value, "float"))
          throw Exception::OutOfRangeException(value);
    return (new Operand<float>(value, FLOAT));
  }

  IOperand*
  OperandFactory::_createDouble(const std::string& value) const
  {
    if (Parsing::Utils::isOutOfRange(value, "double"))
          throw Exception::OutOfRangeException(value);
    return (new Operand<double>(value, DOUBLE));
  }

  OperandFactory*
  getOperandFactory()
  {
    static OperandFactory* factory;

    if (!factory)
      factory = new OperandFactory();
    return (factory);
  }
} /* namespace Arithmetic */
