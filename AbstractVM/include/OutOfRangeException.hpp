/*
 ** OverflowException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/OverflowException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:18:39 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:18:39 AM 2014 kevin labbe
 */

#ifndef OVERFLOWEXCEPTION_HPP_
#define OUTOFRANGEEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class OutOfRangeException : public Exception::AVMException
  {
    public:
      OutOfRangeException(const std::string& errmsg) throw();

      OutOfRangeException(const std::string& errmsg, const int line) throw();

      virtual
      ~OutOfRangeException() throw();
  };

} /* namespace Exception */

#endif /* OVERFLOWEXCEPTION_HPP_ */
