/*
 ** DivideByZeroException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/DivideByZeroException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:19:08 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:19:08 AM 2014 kevin labbe
 */

#ifndef DIVIDEBYZEROEXCEPTION_HPP_
#define DIVIDEBYZEROEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class DivideByZeroException : public Exception::AVMException
  {
    public:
      DivideByZeroException(const std::string& errmsg) throw();

      DivideByZeroException(const std::string& errmsg, const int line) throw();

      virtual
      ~DivideByZeroException() throw();
  };

} /* namespace Exception */

#endif /* DIVIDEBYZEROEXCEPTION_HPP_ */
