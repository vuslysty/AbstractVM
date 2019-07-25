//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_PUSHFACTORY_HPP
#define ABSTRACTVM_PUSHFACTORY_HPP


#include "InstructionFactory.hpp"

class PushFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_PUSHFACTORY_HPP
