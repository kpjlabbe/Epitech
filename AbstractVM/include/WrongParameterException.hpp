/*
 ** WrongParameterException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/WrongParameterException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:23 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:23 AM 2014 kevin labbe
 */

#ifndef WRONGPARAMETEREXCEPTION_HPP_
#define WRONGPARAMETEREXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class WrongParameterException : public Exception::AVMException
  {
    public:
      WrongParameterException(const std::string& errmsg) throw();

      WrongParameterException(const std::string& errmsg, const int line) throw();

      virtual
      ~WrongParameterException() throw();
  };

} /* namespace Exception */

#endif /* WRONGPARAMETEREXCEPTION_HPP_ */
