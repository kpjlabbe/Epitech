/*
 ** WrongValueException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/WrongValueException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:16:39 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:16:39 AM 2014 kevin labbe
 */

#include "WrongValueException.hpp"

namespace Exception
{

  WrongValueException::WrongValueException(const std::string& errmsg) throw () :
      AVMException("Value doesn't match its type: " + errmsg)
  {
  }

  WrongValueException::WrongValueException(const std::string& errmsg,
      const int line) throw () :
      AVMException("Value doesn't match its type: " + errmsg, line)
  {
  }

  WrongValueException::~WrongValueException() throw ()
  {
  }

} /* namespace Exception */
