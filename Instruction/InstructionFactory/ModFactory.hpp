//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_MODFACTORY_HPP
#define ABSTRACTVM_MODFACTORY_HPP

#include "InstructionFactory.hpp"

class ModFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_MODFACTORY_HPP
