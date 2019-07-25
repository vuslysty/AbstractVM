//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_EXITFACTORY_HPP
#define ABSTRACTVM_EXITFACTORY_HPP

#include "InstructionFactory.hpp"

class ExitFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_EXITFACTORY_HPP
