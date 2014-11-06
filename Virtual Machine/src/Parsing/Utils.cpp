/*
 ** Utils.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/Utils.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 4:55:44 AM 2014 kevin labbe
 ** Last update Feb 26, 2014 4:55:44 AM 2014 kevin labbe
 */

#include <algorithm>
#include "Utils.hpp"

namespace Parsing
{

  Utils::Utils()
  {
  }

  Utils::~Utils()
  {
  }

  const std::string&
  Utils::trim(std::string& str)
  {
    std::string::iterator it = std::unique(str.begin(), str.end(), _charactersAreEquals);
    str.erase(it, str.end());
    std::replace(str.begin(), str.end(), '\t', ' ');
    return str;
  }

  const std::vector<std::string>
  Utils::tokenize(const std::string& str, const char delim)
  {
    std::vector<std::string> array;

    size_t start = 0, end = 0;
    while ((end = str.find(delim, start)) != std::string::npos) {
      array.push_back(str.substr(start, end - start));
      start = end + 1;
    }
    array.push_back(str.substr(start));

    return array;
  }

  const std::string
  Utils::itoa(int nbr)
  {
    std::stringstream sstream;
    sstream << nbr;
    return sstream.str();
  }

  bool
  Utils::isOutOfRange(const std::string& nbr,
      const std::string& type)
  {
    double              value;
    std::stringstream   stream(nbr);
    stream >> value;

    if (type == "int8")
      return (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min());
    if (type == "int16")
      return (value > std::numeric_limits<short int>::max() || value < std::numeric_limits<short int>::min());
    if (type == "int32")
      return (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min());
    if (type == "float")
      return (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min());
    if (type == "double")
      return (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min());
    return false;
  }

  bool
  Utils::_charactersAreEquals(char c1, char c2)
  {
    return (c1 == c2) && (c1 == ' ' || c1 == '\t');
  }

} /* namespace Parsing */
