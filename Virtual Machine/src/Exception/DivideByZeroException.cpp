/*
 ** DivideByZeroException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/DivideByZeroException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:19:08 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:19:08 AM 2014 kevin labbe
 */

#include "DivideByZeroException.hpp"

namespace Exception
{

  DivideByZeroException::DivideByZeroException(
      const std::string& errmsg) throw () :
          AVMException("Divide by zero not allowed: " + errmsg)
  {
  }

  DivideByZeroException::DivideByZeroException(const std::string& errmsg,
      const int line) throw () :
          AVMException("Divide by zero not allowed: " + errmsg, line)
  {
  }

  DivideByZeroException::~DivideByZeroException() throw ()
  {
  }

} /* namespace Exception */
