/*
 ** AVMException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/AVMException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 2:57:38 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 2:57:38 AM 2014 kevin labbe
 */

#ifndef AVMEXCEPTION_HPP_
#define AVMEXCEPTION_HPP_

#include <string>
#include <cstdlib>
#include <exception>
#include "Utils.hpp"

namespace Exception
{

  class AVMException : public std::exception
  {
    public:
      AVMException(const std::string& errmsg) throw();

      AVMException(const std::string& errmsg, int line) throw();

      virtual const char*
      what() const throw();

      virtual
      ~AVMException() throw();

    protected:
      std::string   _errmsg;
  };

} /* namespace Exception */

#endif /* AVMEXCEPTION_HPP_ */
