//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_ASSERTFACTORY_HPP
#define ABSTRACTVM_ASSERTFACTORY_HPP


#include "InstructionFactory.hpp"

class AssertFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_ASSERTFACTORY_HPP
