/*
 ** FileNotFoundException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/FileNotFoundException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Mar 2, 2014 7:21:45 PM 2014 kevin labbe
 ** Last update Mar 2, 2014 7:21:45 PM 2014 kevin labbe
 */
#include "FileNotFoundException.hpp"

namespace Exception
{

  FileNotFoundException::FileNotFoundException(
      const std::string& errmsg) throw () :
    AVMException("File not found: " + errmsg)
  {
  }

  FileNotFoundException::FileNotFoundException(const std::string& errmsg,
      const int line) throw () :
    AVMException("File not found: " + errmsg, line)
  {
  }

  FileNotFoundException::~FileNotFoundException() throw()
  {
  }

} /* namespace Exception */
