//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_DIVFACTORY_HPP
#define ABSTRACTVM_DIVFACTORY_HPP

#include "InstructionFactory.hpp"

class DivFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_DIVFACTORY_HPP
