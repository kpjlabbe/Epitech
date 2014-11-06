/*
 ** UnknownInstructionException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/UnknownInstructionException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:14:07 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:14:07 AM 2014 kevin labbe
 */

#ifndef UNKNOWNINSTRUCTIONEXCEPTION_HPP_
#define UNKNOWNINSTRUCTIONEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{
  class UnknownInstructionException : public Exception::AVMException
  {
    public:
      UnknownInstructionException(const std::string& errmsg) throw();

      UnknownInstructionException(const std::string& errmsg, const int line) throw();

      virtual
      ~UnknownInstructionException() throw();
  };
} /* namespace Exception */

#endif /* UNKNOWNINSTRUCTIONEXCEPTION_HPP_ */
