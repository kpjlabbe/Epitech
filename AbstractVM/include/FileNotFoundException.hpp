/*
 ** FileNotFoundException.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/FileNotFoundException.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 2, 2014 7:21:45 PM 2014 kevin labbe
 ** Last update Mar 2, 2014 7:21:45 PM 2014 kevin labbe
 */

#ifndef FILENOTFOUNDEXCEPTION_HPP_
#define FILENOTFOUNDEXCEPTION_HPP_

#include "AVMException.hpp"

namespace Exception
{

  class FileNotFoundException : public Exception::AVMException
  {
    public:
      FileNotFoundException(const std::string& errmsg) throw();

      FileNotFoundException(const std::string& errmsg, const int line) throw();

      virtual
      ~FileNotFoundException() throw();
  };

} /* namespace Exception */

#endif /* FILENOTFOUNDEXCEPTION_HPP_ */
