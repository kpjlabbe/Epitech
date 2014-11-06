/*
 ** OverflowException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/OverflowException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:18:39 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:18:39 AM 2014 kevin labbe
 */

#include "OutOfRangeException.hpp"

namespace Exception
{

  OutOfRangeException::OutOfRangeException(const std::string& errmsg) throw () :
          AVMException("Out of range: " + errmsg)
  {
  }

  OutOfRangeException::OutOfRangeException(const std::string& errmsg,
      const int line) throw () :
          AVMException("Out of range: " + errmsg, line)
  {
  }

  OutOfRangeException::~OutOfRangeException() throw()
  {
  }

} /* namespace Exception */
