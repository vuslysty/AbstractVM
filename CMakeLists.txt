cmake_minimum_required(VERSION 3.14)
project(AbstractVM)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wconversion")
set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp)
add_executable(AbstractVM main.cpp IOperand.hpp ExceptionAVM.cpp ExceptionAVM.hpp Operand.hpp Convertor.cpp Convertor.hpp
        OperandFactory/OperandFactory.hpp
        Instruction/AInstruction.hpp Instruction/PopInstruction.cpp Instruction/PushInstruction.cpp Instruction/AssertInstruction.cpp Instruction/ExitInstruction.cpp Instruction/DumpInstruction.cpp Instruction/PrintInstruction.cpp Instruction/AddInstruction.cpp Instruction/SubInstruction.cpp Instruction/MulInstruction.cpp Instruction/DivInstruction.cpp Instruction/ModInstruction.cpp
        Instruction/InstructionFactory/InstructionFactory.cpp Instruction/InstructionFactory/InstructionFactory.hpp AVM.hpp OperandFactory/OperandFactory.cpp AVM.cpp Instruction/AInstruction.cpp Lexer/Token.cpp Lexer/Token.hpp Lexer/Lexer.cpp Lexer/Lexer.hpp Lexer/conditions.cpp Lexer/finiteStates.cpp Lexer/errors.cpp Parser/Parser.cpp Parser/Parser.hpp Exceptions/ExceptionAVM.cpp Exceptions/ExceptionAVM.hpp Parser/errors.cpp Parser/finiteStates.cpp)