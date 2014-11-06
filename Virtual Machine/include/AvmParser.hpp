/*
 ** AvmParser.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/AvmParser.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 3:25:49 AM 2014 kevin labbe
 ** Last update Feb 26, 2014 3:25:49 AM 2014 kevin labbe
 */

#ifndef AVMPARSER_HPP_
#define AVMPARSER_HPP_

#include <iostream>
#include <fstream>
#include <deque>

#include "IParser.hpp"
#include "Instruction.hpp"
#include "Stack.hpp"
#include "OperandFactory.hpp"
#include "UnknownInstructionException.hpp"
#include "UnknownTypeException.hpp"
#include "WrongParameterException.hpp"
#include "WrongValueException.hpp"
#include "OutOfRangeException.hpp"
#include "ExitMissingException.hpp"

namespace Parsing
{
  class AvmParser : public IParser
  {
    public:
      AvmParser(std::istream& input);

      virtual
      ~AvmParser();

      void
      execInstructions();

      const std::deque<Instruction*>&
      getData() const;

    private:
      void
      _parseFile();

      void
      _computeLexer();

      void
      _computeParser();

      void
      _callAssociatedFunction(Instruction *inst,
          Arithmetic::IOperandFactory* factory,
          Arithmetic::IStack* stack);

      void
      _dump();

    private:
      std::istream&
      _input;

      std::deque<Instruction *>
      _data;
  };
} /* namespace Parsing */

#endif /* AVMPARSER_HPP_ */
