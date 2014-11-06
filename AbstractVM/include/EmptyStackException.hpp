/*
 ** EmptyStackException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/EmptyStackException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:18:17 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:18:17 AM 2014 kevin labbe
 */

#ifndef EMPTYSTACKEXCEPTION_HPP_
#define EMPTYSTACKEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class EmptyStackException : public Exception::AVMException
  {
    public:
      EmptyStackException(const std::string& errmsg) throw();

      EmptyStackException(const std::string& errmsg, const int line) throw();

      virtual
      ~EmptyStackException() throw();
  };

} /* namespace Exception */

#endif /* EMPTYSTACKEXCEPTION_HPP_ */
