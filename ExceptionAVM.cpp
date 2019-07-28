//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "ExceptionAVM.hpp"

const char* ExceptionAVM::EmptyStack::what() const throw()
{
	return ("  ");
}

ExceptionAVM::EmptyStack::EmptyStack() {}
ExceptionAVM::EmptyStack::EmptyStack(const ExceptionAVM::EmptyStack &) throw() {}
ExceptionAVM::EmptyStack& ExceptionAVM::EmptyStack::operator=(const ExceptionAVM::EmptyStack &){return *this;}
ExceptionAVM::EmptyStack::~EmptyStack() throw() {}


const char* ExceptionAVM::UndeclaratedIdentifier::what() const throw()
{
	return ("  ");
}

ExceptionAVM::UndeclaratedIdentifier::UndeclaratedIdentifier() {}
ExceptionAVM::UndeclaratedIdentifier::UndeclaratedIdentifier(const ExceptionAVM::UndeclaratedIdentifier &) throw() {}
ExceptionAVM::UndeclaratedIdentifier& ExceptionAVM::UndeclaratedIdentifier::operator=(const ExceptionAVM::UndeclaratedIdentifier &){return *this;}
ExceptionAVM::UndeclaratedIdentifier::~UndeclaratedIdentifier() throw() {}


const char* ExceptionAVM::ValueOverflow::what() const throw()
{
	return ("  ");
}

ExceptionAVM::ValueOverflow::ValueOverflow() {}
ExceptionAVM::ValueOverflow::ValueOverflow(const ExceptionAVM::ValueOverflow &) throw() {}
ExceptionAVM::ValueOverflow& ExceptionAVM::ValueOverflow::operator=(const ExceptionAVM::ValueOverflow &){return *this;}
ExceptionAVM::ValueOverflow::~ValueOverflow() throw() {}


const char* ExceptionAVM::ValueUnderflow::what() const throw()
{
	return ("  ");
}

ExceptionAVM::ValueUnderflow::ValueUnderflow() {}
ExceptionAVM::ValueUnderflow::ValueUnderflow(const ExceptionAVM::ValueUnderflow &) throw() {}
ExceptionAVM::ValueUnderflow& ExceptionAVM::ValueUnderflow::operator=(const ExceptionAVM::ValueUnderflow &){return *this;}
ExceptionAVM::ValueUnderflow::~ValueUnderflow() throw() {}


const char* ExceptionAVM::PopOnEmptyStack::what() const throw()
{
	return ("  ");
}

ExceptionAVM::PopOnEmptyStack::PopOnEmptyStack() {}
ExceptionAVM::PopOnEmptyStack::PopOnEmptyStack(const ExceptionAVM::PopOnEmptyStack &) throw() {}
ExceptionAVM::PopOnEmptyStack& ExceptionAVM::PopOnEmptyStack::operator=(const ExceptionAVM::PopOnEmptyStack &){return *this;}
ExceptionAVM::PopOnEmptyStack::~PopOnEmptyStack() throw() {}


const char* ExceptionAVM::DivisionByZero::what() const throw()
{
	return ("  ");
}

ExceptionAVM::DivisionByZero::DivisionByZero() {}
ExceptionAVM::DivisionByZero::DivisionByZero(const ExceptionAVM::DivisionByZero &) throw() {}
ExceptionAVM::DivisionByZero& ExceptionAVM::DivisionByZero::operator=(const ExceptionAVM::DivisionByZero &){return *this;}
ExceptionAVM::DivisionByZero::~DivisionByZero() throw() {}


const char* ExceptionAVM::ModuloByZero::what() const throw()
{
	return ("  ");
}

ExceptionAVM::ModuloByZero::ModuloByZero() {}
ExceptionAVM::ModuloByZero::ModuloByZero(const ExceptionAVM::ModuloByZero &) throw() {}
ExceptionAVM::ModuloByZero& ExceptionAVM::ModuloByZero::operator=(const ExceptionAVM::ModuloByZero &){return *this;}
ExceptionAVM::ModuloByZero::~ModuloByZero() throw() {}


const char* ExceptionAVM::NoExit::what() const throw()
{
	return ("  ");
}

ExceptionAVM::NoExit::NoExit() {}
ExceptionAVM::NoExit::NoExit(const ExceptionAVM::NoExit &) throw() {}
ExceptionAVM::NoExit& ExceptionAVM::NoExit::operator=(const ExceptionAVM::NoExit &){return *this;}
ExceptionAVM::NoExit::~NoExit() throw() {}


const char* ExceptionAVM::AssertIsNotTrue::what() const throw()
{
	return ("  ");
}

ExceptionAVM::AssertIsNotTrue::AssertIsNotTrue() {}
ExceptionAVM::AssertIsNotTrue::AssertIsNotTrue(const ExceptionAVM::AssertIsNotTrue &) throw() {}
ExceptionAVM::AssertIsNotTrue& ExceptionAVM::AssertIsNotTrue::operator=(const ExceptionAVM::AssertIsNotTrue &){return *this;}
ExceptionAVM::AssertIsNotTrue::~AssertIsNotTrue() throw() {}


const char* ExceptionAVM::LessThanTwoElem::what() const throw()
{
	return ("  ");
}

ExceptionAVM::LessThanTwoElem::LessThanTwoElem() {}
ExceptionAVM::LessThanTwoElem::LessThanTwoElem(const ExceptionAVM::LessThanTwoElem &) throw() {}
ExceptionAVM::LessThanTwoElem& ExceptionAVM::LessThanTwoElem::operator=(const ExceptionAVM::LessThanTwoElem &){return *this;}
ExceptionAVM::LessThanTwoElem::~LessThanTwoElem() throw() {}


const char* ExceptionAVM::LexicalError::what() const throw()
{
	return ("  ");
}

ExceptionAVM::LexicalError::LexicalError() {}
ExceptionAVM::LexicalError::LexicalError(const ExceptionAVM::LexicalError &) throw() {}
ExceptionAVM::LexicalError& ExceptionAVM::LexicalError::operator=(const ExceptionAVM::LexicalError &){return *this;}
ExceptionAVM::LexicalError::~LexicalError() throw() {}


const char* ExceptionAVM::SyntaxError::what() const throw()
{
	return ("  ");
}
ExceptionAVM::SyntaxError::SyntaxError() {}
ExceptionAVM::SyntaxError::SyntaxError(const ExceptionAVM::SyntaxError &) throw() {}
ExceptionAVM::SyntaxError& ExceptionAVM::SyntaxError::operator=(const ExceptionAVM::SyntaxError &){return *this;}


ExceptionAVM::SyntaxError::~SyntaxError() throw() {}


const char* ExceptionAVM::ValueIsNotASCII::what() const throw()
{
	return ("  ");
}
ExceptionAVM::ValueIsNotASCII::ValueIsNotASCII() {}
ExceptionAVM::ValueIsNotASCII::ValueIsNotASCII(const ExceptionAVM::ValueIsNotASCII &) throw() {}
ExceptionAVM::ValueIsNotASCII& ExceptionAVM::ValueIsNotASCII::operator=(const ExceptionAVM::ValueIsNotASCII &){return *this;}


ExceptionAVM::ValueIsNotASCII::~ValueIsNotASCII() throw() {}


const char* ExceptionAVM::InvalidBinaryOperation::what() const throw()
{
	return ("  ");
}
ExceptionAVM::InvalidBinaryOperation::InvalidBinaryOperation() {}
ExceptionAVM::InvalidBinaryOperation::InvalidBinaryOperation(const ExceptionAVM::InvalidBinaryOperation &) throw() {}
ExceptionAVM::InvalidBinaryOperation& ExceptionAVM::InvalidBinaryOperation::operator=(const ExceptionAVM::InvalidBinaryOperation &){return *this;}


ExceptionAVM::InvalidBinaryOperation::~InvalidBinaryOperation() throw() {}


const char* ExceptionAVM::UnknownInstruction::what() const throw()
{
	return ("  ");
}

ExceptionAVM::UnknownInstruction::UnknownInstruction() {}
ExceptionAVM::UnknownInstruction::UnknownInstruction(const ExceptionAVM::UnknownInstruction &) throw() {}
ExceptionAVM::UnknownInstruction& ExceptionAVM::UnknownInstruction::operator=(const ExceptionAVM::UnknownInstruction &){return *this;}
ExceptionAVM::UnknownInstruction::~UnknownInstruction() throw() {}