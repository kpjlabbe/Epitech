/*
 ** AvmParser.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/AvmParser.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 3:25:49 AM 2014 kevin labbe
 ** Last update Feb 26, 2014 3:25:49 AM 2014 kevin labbe
 */

#include <algorithm>
#include "AvmParser.hpp"
#include "Utils.hpp"
#include "Operand.hpp"

namespace Parsing
{
  AvmParser::AvmParser(std::istream& input) :
          _input(input)
  {
  }

  AvmParser::~AvmParser()
  {
    for (std::deque<Instruction *>::iterator it = _data.begin(); it != _data.end(); it++)
      delete *it;
    _data.clear();
  }

  void
  AvmParser::execInstructions()
  {
    Arithmetic::IOperandFactory *factory = new Arithmetic::OperandFactory;
    Arithmetic::IStack          *stack = new Arithmetic::Stack;

    _parseFile();
    std::deque<Instruction *>::const_iterator it = _data.begin();
    while (it != _data.end() && *it != NULL && (*it)->getName() != "exit")
    {
      _callAssociatedFunction(*it, factory, stack);
      it++;
    }
    delete factory;
    delete stack;
  }

  const std::deque<Instruction*>&
  AvmParser::getData() const
  {
    return _data;
  }

  void
  AvmParser::_parseFile()
  {
    _computeLexer();
    _computeParser();
  }

  void
  AvmParser::_computeLexer()
  {
    std::string              line;
    std::vector<std::string> tokens;
    Instruction*             inst;
    bool                     stop = false;

    size_t p1 = 0, p2 = 0, nbrLine = 1;
    while (!stop && getline(_input, line))
    {
      Utils::trim(line);
      tokens = Utils::tokenize(line, ' ');

      if (tokens.size() >= 1 && tokens[0].length() && tokens[0].at(0) != ';') {
        inst = new Instruction(tokens[0], nbrLine);
        if (tokens.size() >= 2 && tokens[1].length() && tokens[1].at(0) != ';') {
          if ((p1 = tokens[1].find_first_of('(')) != std::string::npos)
          {
            inst->setType(tokens[1].substr(0, p1));
            if ((p2 = tokens[1].find_last_of(')')) != std::string::npos && p1 != p2)
              inst->setValue(tokens[1].substr(p1 + 1, p2 - p1 - 1));
          } else {
            inst->setType(tokens[1]);
          }

          if (tokens.size() >= 3 && tokens[2].length() && tokens[2].at(0) != ';')
            throw Exception::WrongParameterException("(" + inst->getName() + ") " + tokens[2], nbrLine);
        }
        _data.push_back(inst);
      } else if (tokens.size() >= 1 && tokens[0].length() >= 2 && tokens[0] == ";;")
        stop = true;
      nbrLine++;
    }
  }

  void
  AvmParser::_computeParser()
  {
    bool exitcmd = false;
    for (std::deque<Instruction *>::const_iterator it = _data.begin(); it != _data.end() && !exitcmd; it++) {
      if ((*it)->getName() == "exit")
        exitcmd = true;
      else {
        std::string firstParam((*it)->getType() + "(" + (*it)->getValue() + ")");

        if (!(*it)->isValidName())
          throw Exception::UnknownInstructionException((*it)->getName(), (*it)->getLine());

        if ((*it)->getType().length() || (*it)->getValue().length()) {
          if ((*it)->isCompound()) {
            if (!(*it)->isValidType())
              throw Exception::UnknownTypeException((*it)->getType(), (*it)->getLine());

            if (!(*it)->isValidValue())
              throw Exception::WrongValueException(firstParam, (*it)->getLine());

            if ((*it)->isOutOfRange())
              throw Exception::OutOfRangeException(firstParam, (*it)->getLine());
          } else {
            throw Exception::WrongParameterException(firstParam, (*it)->getLine());
          }
        }
      }
    }
    if (!exitcmd)
      throw Exception::ExitMissingException();
  }

  void
  AvmParser::_callAssociatedFunction(Instruction *inst,
      Arithmetic::IOperandFactory* factory,
      Arithmetic::IStack* stack)
  {
    if (inst->getName() == "push")
      stack->push(factory->createOperand(inst->mapOperandTypes[inst->getType()], inst->getValue()));
    else if (inst->getName() == "assert")
      stack->assert(factory->createOperand(inst->mapOperandTypes[inst->getType()], inst->getValue()));
    else
      stack->execFunc(inst->getName());
  }

  void
  AvmParser::_dump()
  {
    for (std::deque<Instruction *>::const_iterator it = _data.begin(); it != _data.end(); it++)
      std::cout << *it << std::endl;
  }

} /* namespace Parsing */
