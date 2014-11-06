/*
 ** Instruction.cpp for cpp_abstractvm in /var/projects/cpp_abstractvm/src/Parsing/Instruction.cpp
 ** 
 ** Made by kevin labbe
 ** Login   <labbe_k@epitech.net>
 ** 
 ** Started on  Feb 26, 2014 1:59:15 AM 2014 kevin labbe
// Last update Sat Mar  1 02:06:01 2014 kevin labbe
 */

#include "Instruction.hpp"

namespace Parsing
{
  std::map<std::string, Instruction::eInstruction> Instruction::mapInstructions;
  std::map<std::string, Arithmetic::eOperandType> Instruction::mapOperandTypes;

  Parsing::Instruction::Instruction() :
      _name(""),
      _line(0),
      _type(""),
      _value("")
  {
    if (!mapInstructions["push"]) {
      _initMapInstructions();
      _initMapOperandTypes();
    }
  }

  Parsing::Instruction::Instruction(const std::string& name, int line) :
      _name(name),
      _line(line),
      _type(""),
      _value("")
  {
    if (!mapInstructions["push"]) {
      _initMapInstructions();
      _initMapOperandTypes();
    }
  }

  bool
  Instruction::isCompound() const
  {
    if (_name == "push" || _name == "assert")
      return true;
    return false;
  }

  bool
  Instruction::isValidName() const
  {
    if (mapInstructions.find(_name) != mapInstructions.end())
      return true;
    return false;
  }

  bool
  Instruction::isValidType() const
  {
    if (mapOperandTypes.find(_type) != mapOperandTypes.end())
          return true;
    return false;
  }

  bool
  Instruction::isValidValue() const
  {
    if (_value.find_first_of("-") != _value.find_last_of("-"))
      return false;
    if (_type.find("int") != _type.npos)
        return (strspn(_value.c_str(), "-0123456789") == _value.length());
    if (strspn(_value.c_str(), "-0123456789.") != _value.length())
      return false;
    if (_value.find_first_of(".") == _value.find_last_of("."))
      return true;
    return false;
  }

  bool
  Instruction::isOutOfRange() const
  {
    return Utils::isOutOfRange(_value, _type);
  }

  int
  Instruction::getLine() const
  {
    return _line;
  }

  void
  Instruction::setLine(int line)
  {
    _line = line;
  }

  const std::string&
  Instruction::getName() const
  {
    return _name;
  }

  void
  Instruction::setName(const std::string& name)
  {
    _name = name;
  }

  const std::string&
  Instruction::getType() const
  {
    return _type;
  }

  void
  Instruction::setType(const std::string& type)
  {
    _type = type;
  }

  const std::string&
  Instruction::getValue() const
  {
    return _value;
  }

  void
  Instruction::setValue(const std::string& value)
  {
    _value = value;
  }

  void
  Instruction::_initMapInstructions()
  {
    mapInstructions["push"] = PUSH;
    mapInstructions["pop"] = POP;
    mapInstructions["dump"] = DUMP;
    mapInstructions["assert"] = ASSERT;
    mapInstructions["add"] = ADD;
    mapInstructions["sub"] = SUB;
    mapInstructions["mul"] = MUL;
    mapInstructions["div"] = DIV;
    mapInstructions["mod"] = MOD;
    mapInstructions["print"] = PRINT;
    mapInstructions["exit"] = EXIT;
  }

  void
  Instruction::_initMapOperandTypes()
  {
    mapOperandTypes["int8"] = Arithmetic::INT8;
    mapOperandTypes["int16"] = Arithmetic::INT16;
    mapOperandTypes["int32"] = Arithmetic::INT32;
    mapOperandTypes["float"] = Arithmetic::FLOAT;
    mapOperandTypes["double"] = Arithmetic::DOUBLE;
  }
} /* namespace Parsing */

std::ostream&
operator <<(std::ostream& stream, Parsing::Instruction* inst)
{
  stream
    << "instruction name=" << inst->getName() << std::endl
    << "line=" << inst->getLine() << std::endl
    << "type=" <<inst->getType() << std::endl
    << "value=" << inst->getValue() << std::endl;
  return stream;
}
