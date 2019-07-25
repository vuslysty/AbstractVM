//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_EXCEPTIONAVM_HPP
#define ABSTRACTVM_EXCEPTIONAVM_HPP


#include <exception>

class ExceptionAVM
{
public:
	
	class	EmptyStack : public std::exception
	{
	public:
		EmptyStack();
		EmptyStack(EmptyStack const &src) throw();
		EmptyStack &operator=(EmptyStack const &rhs);
		~EmptyStack() throw();

		const char 			*what(void) const throw();
	};


	class	InvalidInstruction : public std::exception
	{
	public:
		InvalidInstruction();
		InvalidInstruction(InvalidInstruction const &src) throw();
		InvalidInstruction &operator=(InvalidInstruction const &rhs);
		~InvalidInstruction() throw();

		const char 			*what(void) const throw();
	};


	class	ValueOverflow : public std::exception
	{
	public:
		ValueOverflow();
		ValueOverflow(ValueOverflow const &src) throw();
		ValueOverflow &operator=(ValueOverflow const &rhs);
		~ValueOverflow() throw();

		const char 			*what(void) const throw();
	};


	class	ValueUnderflow : public std::exception
	{
	public:
		ValueUnderflow();
		ValueUnderflow(ValueUnderflow const &src) throw();
		ValueUnderflow &operator=(ValueUnderflow const &rhs);
		~ValueUnderflow() throw();

		const char 			*what(void) const throw();
	};


	class	PopOnEmptyStack : public std::exception
	{
	public:
		PopOnEmptyStack();
		PopOnEmptyStack(PopOnEmptyStack const &src) throw();
		PopOnEmptyStack &operator=(PopOnEmptyStack const &rhs);
		~PopOnEmptyStack() throw();

		const char 			*what(void) const throw();
	};


	class	DivisionByZero : public std::exception
	{
	public:
		DivisionByZero();
		DivisionByZero(DivisionByZero const &src) throw();
		DivisionByZero &operator=(DivisionByZero const &rhs);
		~DivisionByZero() throw();

		const char 			*what(void) const throw();
	};

	
	class	ModuloByZero : public std::exception
	{
	public:
		ModuloByZero();
		ModuloByZero(ModuloByZero const &src) throw();
		ModuloByZero &operator=(ModuloByZero const &rhs);
		~ModuloByZero() throw();

		const char 			*what(void) const throw();
	};


	class	NoExit : public std::exception
	{
	public:
		NoExit();
		NoExit(NoExit const &src) throw();
		NoExit &operator=(NoExit const &rhs);
		~NoExit() throw();

		const char 			*what(void) const throw();
	};


	class	AssertIsNotTrue : public std::exception
	{
	public:
		AssertIsNotTrue();
		AssertIsNotTrue(AssertIsNotTrue const &src) throw();
		AssertIsNotTrue &operator=(AssertIsNotTrue const &rhs);
		~AssertIsNotTrue() throw();

		const char 			*what(void) const throw();
	};


	class	LessThanTwoElem : public std::exception
	{
	public:
		LessThanTwoElem();
		LessThanTwoElem(LessThanTwoElem const &src) throw();
		LessThanTwoElem &operator=(LessThanTwoElem const &rhs);
		~LessThanTwoElem() throw();

		const char 			*what(void) const throw();
	};


	class	LexicalError : public std::exception
	{
	public:
		LexicalError();
		LexicalError(LexicalError const &src) throw();
		LexicalError &operator=(LexicalError const &rhs);
		~LexicalError() throw();

		const char 			*what(void) const throw();
	};


	class	SyntaxError : public std::exception
	{
	public:
		SyntaxError();
		SyntaxError(SyntaxError const &src) throw();
		SyntaxError &operator=(SyntaxError const &rhs);
		~SyntaxError() throw();

		const char 			*what(void) const throw();
	};


	class	ValueIsNotASCII : public std::exception
	{
	public:
		ValueIsNotASCII();
		ValueIsNotASCII(ValueIsNotASCII const &src) throw();
		ValueIsNotASCII &operator=(ValueIsNotASCII const &rhs);
		~ValueIsNotASCII() throw();

		const char 			*what(void) const throw();
	};

	class	InvalidBinaryOperation : public std::exception
	{
	public:
		InvalidBinaryOperation();
		InvalidBinaryOperation(InvalidBinaryOperation const &src) throw();
		InvalidBinaryOperation &operator=(InvalidBinaryOperation const &rhs);
		~InvalidBinaryOperation() throw();

		const char 			*what(void) const throw();
	};
	
};


#endif //ABSTRACTVM_EXCEPTIONAVM_HPP
