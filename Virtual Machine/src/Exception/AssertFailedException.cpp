/*
 ** AssertFailedException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/AssertFailedException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:19:47 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:19:47 AM 2014 kevin labbe
 */

#include "AssertFailedException.hpp"

namespace Exception
{

  AssertFailedException::AssertFailedException(
      const std::string& errmsg) throw () :
          AVMException("Assert instruction went wrong: " + errmsg)
  {
  }

  AssertFailedException::AssertFailedException(const std::string& errmsg,
      const int line) throw () :
          AVMException("Assert instruction went wrong: " + errmsg, line)
  {
  }

  AssertFailedException::~AssertFailedException() throw ()
  {
  }

} /* namespace Exception */
