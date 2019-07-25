//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_SUBFACTORY_HPP
#define ABSTRACTVM_SUBFACTORY_HPP


#include "InstructionFactory.hpp"

class SubFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_SUBFACTORY_HPP
