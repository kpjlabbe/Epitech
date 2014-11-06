/*
 ** Instruction.hpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/Instruction.hpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 1:59:15 AM 2014 kevin labbe
 ** Last update Feb 26, 2014 1:59:15 AM 2014 kevin labbe
 */

#ifndef INSTRUCTION_HPP_
#define INSTRUCTION_HPP_

#include <iostream>
#include <string>
#include <map>
#include <cstring>

#include "Utils.hpp"
#include "IOperand.hpp"

namespace Parsing
{
  class Instruction
  {
    public:
      enum eInstruction {
        PUSH,
        POP,
        DUMP,
        ASSERT,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        PRINT,
        EXIT
      };

      static std::map<std::string, eInstruction> mapInstructions;
      static std::map<std::string, Arithmetic::eOperandType> mapOperandTypes;

    public:
      Instruction();

      Instruction(const std::string& name, int line);

      bool
      isCompound() const;

      bool
      isValidName() const;

      bool
      isValidType() const;

      bool
      isValidValue() const;

      bool
      isOutOfRange() const;

      int
      getLine() const;

      void
      setLine(int line);

      const std::string&
      getName() const;

      void
      setName(const std::string& name);

      const std::string&
      getType() const;

      void
      setType(const std::string& type);

      const std::string&
      getValue() const;

      void
      setValue(const std::string& value);

    private:
      void
      _initMapInstructions();

      void
      _initMapOperandTypes();

    private:
      std::string   _name;
      int           _line;
      std::string   _type;
      std::string   _value;
  };

} /* namespace Parsing */

std::ostream&
operator <<(std::ostream& stream, Parsing::Instruction* inst);

#endif /* INSTRUCTION_HPP_ */
