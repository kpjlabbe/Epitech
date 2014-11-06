/*
 ** ExitMissingException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/ExitMissingException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:47 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:47 AM 2014 kevin labbe
 */

#ifndef EXITMISSINGEXCEPTION_HPP_
#define EXITMISSINGEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class ExitMissingException : public Exception::AVMException
  {
    public:
      ExitMissingException() throw();

      virtual
      ~ExitMissingException() throw();
  };

} /* namespace Exception */

#endif /* EXITMISSINGEXCEPTION_HPP_ */
