/*
 ** ExitMissingException.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Exception/ExitMissingException.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 27, 2014 3:17:47 AM 2014 kevin labbe
 ** Last update Feb 27, 2014 3:17:47 AM 2014 kevin labbe
 */

#include "ExitMissingException.hpp"

namespace Exception
{

  ExitMissingException::ExitMissingException() throw () :
     AVMException("No exit instruction found at the end of the program")
  {
  }

  ExitMissingException::~ExitMissingException() throw ()
  {
  }

} /* namespace Exception */
