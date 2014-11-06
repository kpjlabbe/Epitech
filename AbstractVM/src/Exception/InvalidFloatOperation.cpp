/*
 ** InvalidFloatOperation.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/InvalidFloatOperation.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 28, 2014 8:34:31 PM 2014 kevin labbe
 ** Last update Feb 28, 2014 8:34:31 PM 2014 kevin labbe
 */
#include "InvalidFloatOperation.hpp"

namespace Exception
{
  InvalidFloatOperation::InvalidFloatOperation(
      const std::string& errmsg) throw () :
        AVMException("Invalid float operation: " + errmsg)
  {
  }

  InvalidFloatOperation::InvalidFloatOperation(const std::string& errmsg,
      const int line) throw () :
        AVMException("Invalid float operation:: " + errmsg, line)
  {
  }

  InvalidFloatOperation::~InvalidFloatOperation() throw ()
  {
  }

} /* namespace Exception */
