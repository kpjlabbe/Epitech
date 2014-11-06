/*
 ** EmptyStackException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/EmptyStackException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:18:17 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:18:17 AM 2014 kevin labbe
 */

#include "EmptyStackException.hpp"

namespace Exception
{

  EmptyStackException::EmptyStackException(const std::string& errmsg) throw () :
          AVMException("Stack not full enough to compute any operation: " + errmsg)
  {
  }

  EmptyStackException::EmptyStackException(const std::string& errmsg,
      const int line) throw () :
          AVMException("Stack not full enough to compute any operation: " + errmsg, line)
  {
  }

  EmptyStackException::~EmptyStackException() throw ()
  {
  }

} /* namespace Exception */
