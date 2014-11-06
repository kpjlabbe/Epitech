/*
 ** Operand.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Operand.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 11:12:51 PM 2014 kevin labbe
 ** Last update Feb 27, 2014 11:12:51 PM 2014 kevin labbe
 */

#ifndef OPERAND_HPP_
#define OPERAND_HPP_

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "InvalidFloatOperation.hpp"
#include "DivideByZeroException.hpp"
#include "ModuloByZeroException.hpp"
#include <sstream>
#include <iomanip>

namespace Arithmetic
{
  template <class T>
  class Operand : public IOperand
  {
    public:
      static T
      strToNumber(const std::string& value);

    public:
      Operand(const std::string& value, eOperandType type);

      virtual
      ~Operand();

      std::string const&
      toString() const;

      int
      getPrecision() const;

      eOperandType
      getType() const;

      IOperand*
      operator+(const IOperand &rhs) const;

      IOperand*
      operator-(const IOperand &rhs) const;

      IOperand*
      operator*(const IOperand &rhs) const;

      IOperand*
      operator%(const IOperand &rhs) const;

      IOperand*
      operator/(const IOperand &rhs) const;

    private:
      IOperand*
      _getOperandCreated(const IOperand& rhs, double nbr) const;

    private:
      T                 _value;
      std::string       _strval;
      eOperandType      _type;
      IOperandFactory*   _factory;
  };

  template<>
  inline Arithmetic::IOperand*
  Operand<float>::operator %(const IOperand& rhs) const
  {
    throw Exception::InvalidFloatOperation(_strval + " % " + rhs.toString());
    return NULL;
  }

  template<>
  inline Arithmetic::IOperand*
  Operand<double>::operator %(const IOperand& rhs) const
  {
    throw Exception::InvalidFloatOperation(_strval + " % " + rhs.toString());
    return NULL;
  }
} /* namespace Arithmetic */

template<class T>
inline T
Arithmetic::Operand<T>::strToNumber(const std::string& value)
{
    double   nbr;
    std::stringstream   stream;

    stream.str(value);
    stream >> nbr;
    return nbr;
}

template<class T>
inline
Arithmetic::Operand<T>::Operand(const std::string& value, eOperandType type) :
  _strval(value),
  _type(type)
{
    _value = strToNumber(value);
    _factory = getOperandFactory();
}

template<class T>
inline
Arithmetic::Operand<T>::~Operand()
{
}

template<class T>
inline const std::string&
Arithmetic::Operand<T>::toString() const
{
    return _strval;
}

template<class T>
inline int
Arithmetic::Operand<T>::getPrecision() const
{
    size_t pos;

    if ((pos = _strval.find_first_of('.'))  != std::string::npos)
      return (_strval.substr(pos + 1, _strval.length() - 1).length());
    return (_type);
}

template<class T>
inline Arithmetic::eOperandType
Arithmetic::Operand<T>::getType() const
{
    return _type;
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::operator +(const IOperand& rhs) const
{
    return _getOperandCreated(rhs, (double) (_value + strToNumber(rhs.toString())));
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::operator -(const IOperand& rhs) const
{
    return _getOperandCreated(rhs, (double) (_value - strToNumber(rhs.toString())));
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::operator *(const IOperand& rhs) const
{
    return _getOperandCreated(rhs, (double) (_value * strToNumber(rhs.toString())));
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::operator %(const IOperand& rhs) const
{
    if (strToNumber(rhs.toString()) == 0)
      throw Exception::ModuloByZeroException(std::string(Parsing::Utils::itoa(_value)) + " % 0");
    return _getOperandCreated(rhs, (double) (_value % strToNumber(rhs.toString())));
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::operator /(const IOperand& rhs) const
{
    double nbr = strToNumber(rhs.toString());
    if (nbr == 0)
      throw Exception::DivideByZeroException(std::string(Parsing::Utils::itoa(_value)) + " / 0");
    return _getOperandCreated(rhs, (double) (_value / nbr));
}

template<class T>
inline Arithmetic::IOperand*
Arithmetic::Operand<T>::_getOperandCreated(const IOperand& rhs, double nbr) const
{
    const std::string   value;
    eOperandType        type;
    int                 precision;
    std::stringstream   stream;

    type = (getPrecision() > rhs.getPrecision()) ? _type : rhs.getType();
    precision = (getPrecision() > rhs.getPrecision()) ? getPrecision() : rhs.getPrecision();
    if (type == FLOAT || type == DOUBLE)
      stream << std::fixed << std::setprecision(precision) << nbr;
    else
      stream << nbr;
    return _factory->createOperand(type, stream.str());
}

#endif /* OPERAND_HPP_ */
