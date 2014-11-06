/*
 ** WrongParameterException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/WrongParameterException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:23 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:23 AM 2014 kevin labbe
 */

#include "WrongParameterException.hpp"

namespace Exception
{

  WrongParameterException::WrongParameterException(
      const std::string& errmsg) throw () :
          AVMException("Parameter not expected: " + errmsg)
  {
  }

  WrongParameterException::WrongParameterException(const std::string& errmsg,
      const int line) throw () :
          AVMException("Parameter not expected: " + errmsg, line)
  {
  }

  WrongParameterException::~WrongParameterException() throw ()
  {
  }

} /* namespace Exception */
