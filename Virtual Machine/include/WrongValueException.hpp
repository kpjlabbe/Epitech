/*
 ** WrongValueException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/WrongValueException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:16:39 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:16:39 AM 2014 kevin labbe
 */

#ifndef WRONGVALUEEXCEPTION_HPP_
#define WRONGVALUEEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class WrongValueException : public Exception::AVMException
  {
    public:
      WrongValueException(const std::string& errmsg) throw();

      WrongValueException(const std::string& errmsg, const int line) throw();

      virtual
      ~WrongValueException() throw();
  };

} /* namespace Exception */

#endif /* WRONGVALUEEXCEPTION_HPP_ */
