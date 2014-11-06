/*
 ** AVMException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/AVMException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 2:57:38 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 2:57:38 AM 2014 kevin labbe
 */

#include "AVMException.hpp"

namespace Exception
{
  AVMException::AVMException(const std::string& errmsg) throw () :
      _errmsg(errmsg)
  {
  }

  AVMException::AVMException(const std::string& errmsg, int line) throw () :
    _errmsg(errmsg + std::string(" on line ") + Parsing::Utils::itoa(line))
  {
  }

  const char*
  AVMException::what() const throw ()
  {
    return _errmsg.c_str();
  }

  AVMException::~AVMException() throw()
  {
  }

} /* namespace Exception */
