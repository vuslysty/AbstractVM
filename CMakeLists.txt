cmake_minimum_required(VERSION 3.14)
project(AbstractVM)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wconversion")
#set(CMAKE_CXX_STANDARD 98)

add_executable(AbstractVM main.cpp IOperand.hpp testFsm.cpp "Fsm additions/Fsm.cpp" "Fsm additions/Fsm.hpp" "Fsm additions/conditions.cpp" "Fsm additions/states.cpp" Instruction/Instruction.cpp Instruction/Instruction.hpp Instruction/PopInstruction.cpp Instruction/PopInstruction.hpp Instruction/PushInstruction.cpp Instruction/PushInstruction.hpp Instruction/AssertInstruction.cpp Instruction/AssertInstruction.hpp Instruction/ExitInstruction.cpp Instruction/ExitInstruction.hpp Instruction/DumpInstruction.cpp Instruction/DumpInstruction.hpp Instruction/PrintInstruction.cpp Instruction/PrintInstruction.hpp Instruction/AddInstruction.cpp Instruction/AddInstruction.hpp Instruction/SubInstruction.cpp Instruction/SubInstruction.hpp Instruction/MulInstruction.cpp Instruction/MulInstruction.hpp Instruction/DivInstruction.cpp Instruction/DivInstruction.hpp Instruction/ModInstruction.cpp Instruction/ModInstruction.hpp)