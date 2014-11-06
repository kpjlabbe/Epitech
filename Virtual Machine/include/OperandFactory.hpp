/*
 ** OperandFactory.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/OperandFactory.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 28, 2014 3:43:29 PM 2014 kevin labbe
 ** Last update Feb 28, 2014 3:43:29 PM 2014 kevin labbe
 */

#ifndef OPERANDFACTORY_HPP_
#define OPERANDFACTORY_HPP_

#include "IOperandFactory.hpp"

namespace Arithmetic
{
  class OperandFactory : public IOperandFactory
  {
    public:
      OperandFactory();

      virtual
      ~OperandFactory();

      IOperand*
      createOperand(eOperandType type, const std::string & value) const;

    private:
      IOperand*
      _createInt8(const std::string & value) const;

      IOperand*
      _createInt16(const std::string & value) const;

      IOperand*
      _createInt32(const std::string & value) const;

      IOperand*
      _createFloat(const std::string & value) const;

      IOperand*
      _createDouble(const std::string & value) const;

    private:
      IOperand*
      (OperandFactory::*_funcs[5])(const std::string &value) const;
  };

  OperandFactory*
  getOperandFactory();
} /* namespace Arithmetic */

#endif /* OPERANDFACTORY_HPP_ */
