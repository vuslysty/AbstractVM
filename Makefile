NAME = abstractVM

FLAGS = -Wall -Wextra -Werror -std=c++14

SRCS =	./srcs/Exceptions/ExceptionAVM.cpp\
		./srcs/Exceptions/FileException.cpp\
		./srcs/Exceptions/LexerException.cpp\
		./srcs/Exceptions/LimitException.cpp\
		./srcs/Exceptions/ParserException.cpp\
		./srcs/Exceptions/RunTimeExceptions.cpp\
		\
		./srcs/Executor/Executor.cpp\
		./srcs/Executor/FileAndOutput.cpp\
		\
		./srcs/Instruction/InstructionFactory/InstructionFactory.cpp\
		\
		./srcs/Instruction/AddInstruction.cpp\
		./srcs/Instruction/AInstruction.cpp\
		./srcs/Instruction/AssertInstruction.cpp\
		./srcs/Instruction/BackInstruction.cpp\
		./srcs/Instruction/DivInstruction.cpp\
		./srcs/Instruction/DumpInstruction.cpp\
		./srcs/Instruction/ExitInstruction.cpp\
		./srcs/Instruction/FrontInstruction.cpp\
		./srcs/Instruction/MaxInstruction.cpp\
		./srcs/Instruction/MinInstruction.cpp\
		./srcs/Instruction/ModInstruction.cpp\
		./srcs/Instruction/MulInstruction.cpp\
		./srcs/Instruction/PopInstruction.cpp\
		./srcs/Instruction/PrintInstruction.cpp\
		./srcs/Instruction/PushInstruction.cpp\
		./srcs/Instruction/SubInstruction.cpp\
		\
		./srcs/Lexer/conditions.cpp\
		./srcs/Lexer/errors.cpp\
		./srcs/Lexer/finiteStates.cpp\
		./srcs/Lexer/Lexer.cpp\
		./srcs/Lexer/Token.cpp\
		\
		./srcs/OperandFactory/OperandFactory.cpp\
		\
		./srcs/Parser/errors.cpp\
		./srcs/Parser/finiteStates.cpp\
		./srcs/Parser/Parser.cpp\
		\
		./srcs/AVM.cpp\
		./srcs/checkLimits.cpp\
		./srcs/Convertor.cpp\
		./srcs/main.cpp\
		./srcs/Operand.cpp

OBJS = $(SRCS:.cpp=.o)

INC =	./srcs/AVM.hpp\
		./srcs/OperandFactory/OperandFactory.hpp\
		./srcs/IOperand.hpp\
		./srcs/Executor/Executor.hpp\
		./srcs/Lexer/Token.hpp\
		./srcs/Operand.hpp\
		./srcs/Exceptions/ExceptionAVM.hpp\
		./srcs/Instruction/InstructionFactory/InstructionFactory.hpp\
		./srcs/Lexer/Lexer.hpp\
		./srcs/Exceptions/RunTimeExceptions.hpp\
		./srcs/Instruction/AInstruction.hpp\
		./srcs/Convertor.hpp\
		./srcs/Exceptions/FileException.hpp\
		./srcs/Exceptions/LimitException.hpp\
		./srcs/Parser/Parser.hpp

.PHONY : all
all: $(NAME)


$(NAME): $(OBJS)
	@echo "Building of $(NAME)..."
	@clang++ -o $(NAME) $(OBJS)

%.o: %.cpp $(INC)
	clang++ $(FLAGS) -o $@ -c $<

.PHONY : clean
clean:
	@rm -f $(OBJS)

.PHONY : fclean
fclean: clean
	@rm -f $(NAME)

.PHONY : re
re: fclean all

