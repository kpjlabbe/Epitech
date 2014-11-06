/*
 ** Utils.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/Utils.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 4:55:44 AM 2014 kevin labbe
 ** Last update Feb 26, 2014 4:55:44 AM 2014 kevin labbe
 */
#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

#include "Instruction.hpp"

namespace Parsing
{
  class Utils
  {
    public:
      Utils();

      virtual
      ~Utils();

      static const std::string&
      trim(std::string& str);

      static const std::vector<std::string>
      tokenize(const std::string& str, const char delim);

      static const std::string
      itoa(int nbr);

      static bool
      isOutOfRange(const std::string& nbr, const std::string& type);

    private:
      static bool
      _charactersAreEquals(char c1, char c2);
  };
} /* namespace Parsing */

#endif /* UTILS_HPP_ */
