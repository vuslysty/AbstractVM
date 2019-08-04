cmake_minimum_required(VERSION 3.13)
project(AbstractVM)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wconversion")
set(CMAKE_CXX_STANDARD 14)

add_executable(test srcs/main.cpp)
add_executable(AbstractVM srcs/main.cpp srcs/IOperand.hpp srcs/Operand.hpp srcs/Convertor.cpp srcs/Convertor.hpp
        srcs/OperandFactory/OperandFactory.hpp
        srcs/Instruction/AInstruction.hpp srcs/Instruction/PopInstruction.cpp srcs/Instruction/PushInstruction.cpp srcs/Instruction/AssertInstruction.cpp srcs/Instruction/ExitInstruction.cpp srcs/Instruction/DumpInstruction.cpp srcs/Instruction/PrintInstruction.cpp srcs/Instruction/AddInstruction.cpp srcs/Instruction/SubInstruction.cpp srcs/Instruction/MulInstruction.cpp srcs/Instruction/DivInstruction.cpp srcs/Instruction/ModInstruction.cpp
        srcs/Instruction/InstructionFactory/InstructionFactory.cpp srcs/Instruction/InstructionFactory/InstructionFactory.hpp srcs/AVM.hpp srcs/OperandFactory/OperandFactory.cpp srcs/AVM.cpp srcs/Instruction/AInstruction.cpp srcs/Lexer/Token.cpp srcs/Lexer/Token.hpp srcs/Lexer/Lexer.cpp srcs/Lexer/Lexer.hpp srcs/Lexer/conditions.cpp srcs/Lexer/finiteStates.cpp srcs/Lexer/errors.cpp srcs/Parser/Parser.cpp srcs/Parser/Parser.hpp srcs/Exceptions/ExceptionAVM.hpp srcs/Parser/errors.cpp srcs/Parser/finiteStates.cpp srcs/Exceptions/LexerException.cpp srcs/Exceptions/ParserException.cpp srcs/Exceptions/LimitException.cpp srcs/Exceptions/LimitException.hpp srcs/Exceptions/ExceptionAVM.cpp srcs/Operand.cpp srcs/Exceptions/RunTimeExceptions.cpp srcs/Exceptions/RunTimeExceptions.hpp srcs/Exceptions/FileException.cpp srcs/Executor/Executor.cpp srcs/Executor/Executor.hpp srcs/Executor/FileAndOutput.cpp srcs/Exceptions/FileException.hpp srcs/Instruction/MinInstruction.cpp srcs/Instruction/MaxInstruction.cpp srcs/Instruction/FrontInstruction.cpp srcs/Instruction/BackInstruction.cpp srcs/checkLimits.cpp)