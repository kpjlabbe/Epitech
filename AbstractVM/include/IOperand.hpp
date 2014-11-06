/*
 ** IOperand.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/IOperand.hpp
 **
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 **
 ** Started on  Feb 27, 2014 10:27:58 PM 2014 kevin labbe
 ** Last update Feb 27, 2014 10:27:58 PM 2014 kevin labbe
 */

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>

namespace Arithmetic
{
  enum    eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  };

  class   IOperand
  {
    public:
      virtual std::string const&  toString() const = 0;
      virtual int                 getPrecision() const = 0;
      virtual eOperandType        getType() const = 0;

      virtual IOperand *          operator+(const IOperand &rhs) const = 0;
      virtual IOperand *          operator-(const IOperand &rhs) const = 0;
      virtual IOperand *          operator*(const IOperand &rhs) const = 0;
      virtual IOperand *          operator%(const IOperand &rhs) const = 0;
      virtual IOperand *          operator/(const IOperand &rhs) const = 0;

      virtual                     ~IOperand() {}
  };
}

#endif /* IOPERAND_HPP_ */
