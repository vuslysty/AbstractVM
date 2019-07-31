//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"

ExitInstruction::ExitInstruction(Token *tok)
{
	instructionToken = tok;
}

void ExitInstruction::doInstruction(std::deque<const IOperand *> &) const
{

}