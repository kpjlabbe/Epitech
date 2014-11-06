/*
 ** ModuloByZeroException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/ModuloByZeroException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 2, 2014 7:40:22 PM 2014 kevin labbe
 ** Last update Mar 2, 2014 7:40:22 PM 2014 kevin labbe
 */
#include "ModuloByZeroException.hpp"

namespace Exception
{
  ModuloByZeroException::ModuloByZeroException(
      const std::string& errmsg) throw () :
    AVMException("Modulo by zero not allowed: " + errmsg)
  {
  }

  ModuloByZeroException::ModuloByZeroException(const std::string& errmsg,
      const int line) throw () :
    AVMException("Modulo by zero not allowed: " + errmsg, line)
  {
  }

  ModuloByZeroException::~ModuloByZeroException() throw()
  {
  }
} /* namespace Exception */
