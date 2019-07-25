//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_MULFACTORY_HPP
#define ABSTRACTVM_MULFACTORY_HPP

#include "InstructionFactory.hpp"

class MulFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_MULFACTORY_HPP
