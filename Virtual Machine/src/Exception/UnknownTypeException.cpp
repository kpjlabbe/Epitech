/*
 ** UnknownTypeException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/UnknownTypeException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:06 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:06 AM 2014 kevin labbe
 */

#include "UnknownTypeException.hpp"

namespace Exception
{

  UnknownTypeException::UnknownTypeException(const std::string& errmsg) throw () :
        AVMException("Type undefined: " + errmsg)
  {
  }

  UnknownTypeException::UnknownTypeException(const std::string& errmsg,
      const int line) throw () :
        AVMException("Type undefined: " + errmsg, line)
  {
  }

  UnknownTypeException::~UnknownTypeException() throw ()
  {
  }

} /* namespace Exception */
