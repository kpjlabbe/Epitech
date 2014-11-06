/*
 ** ModuloByZeroException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/ModuloByZeroException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 2, 2014 7:40:22 PM 2014 kevin labbe
 ** Last update Mar 2, 2014 7:40:22 PM 2014 kevin labbe
 */
#ifndef MODULOBYZEROEXCEPTION_HPP_
#define MODULOBYZEROEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{
  class ModuloByZeroException : public Exception::AVMException
  {
    public:
      ModuloByZeroException(const std::string& errmsg) throw();

      ModuloByZeroException(const std::string& errmsg, const int line) throw();

      virtual
      ~ModuloByZeroException() throw();
  };
} /* namespace Exception */

#endif /* MODULOBYZEROEXCEPTION_HPP_ */
