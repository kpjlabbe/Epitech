/*
 ** UnknownInstructionException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/UnknownInstructionException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:14:07 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:14:07 AM 2014 kevin labbe
 */

#include "UnknownInstructionException.hpp"

namespace Exception
{

  UnknownInstructionException::UnknownInstructionException(
      const std::string& errmsg) throw () :
          AVMException("Instruction undefined: " + errmsg)
  {
  }

  UnknownInstructionException::UnknownInstructionException(
      const std::string& errmsg, const int line) throw () :
          AVMException("Instruction undefined: " + errmsg, line)
  {
  }

  UnknownInstructionException::~UnknownInstructionException() throw ()
  {
  }

} /* namespace Exception */
