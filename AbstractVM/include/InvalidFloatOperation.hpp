/*
 ** InvalidFloatOperation.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/include/InvalidFloatOperation.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 28, 2014 8:34:31 PM 2014 kevin labbe
 ** Last update Feb 28, 2014 8:34:31 PM 2014 kevin labbe
 */
#ifndef INVALIDFLOATOPERATION_HPP_
#define INVALIDFLOATOPERATION_HPP_

#include "AVMException.hpp"

namespace Exception
{
  class InvalidFloatOperation : public Exception::AVMException
  {
    public:
      InvalidFloatOperation(const std::string& errmsg) throw();

      InvalidFloatOperation(const std::string& errmsg, const int line) throw();

      virtual
      ~InvalidFloatOperation() throw();
  };

} /* namespace Exception */

#endif /* INVALIDFLOATOPERATION_HPP_ */
