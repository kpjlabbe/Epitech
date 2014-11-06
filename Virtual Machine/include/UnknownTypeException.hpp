/*
 ** UnknownTypeException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/UnknownTypeException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:06 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:06 AM 2014 kevin labbe
 */

#ifndef UNKNOWNTYPEEXCEPTION_HPP_
#define UNKNOWNTYPEEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class UnknownTypeException : public Exception::AVMException
  {
    public:
      UnknownTypeException(const std::string& errmsg) throw();

      UnknownTypeException(const std::string& errmsg, const int line) throw();

      virtual
      ~UnknownTypeException() throw();
  };

} /* namespace Exception */

#endif /* UNKNOWNTYPEEXCEPTION_HPP_ */
