/*
 ** AssertFailedException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/AssertFailedException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:19:47 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:19:47 AM 2014 kevin labbe
 */

#ifndef ASSERTFAILEDEXCEPTION_HPP_
#define ASSERTFAILEDEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class AssertFailedException : public Exception::AVMException
  {
    public:
      AssertFailedException(const std::string& errmsg) throw();

      AssertFailedException(const std::string& errmsg, const int line) throw();

      virtual
      ~AssertFailedException() throw();
  };

} /* namespace Exception */

#endif /* ASSERTFAILEDEXCEPTION_HPP_ */
