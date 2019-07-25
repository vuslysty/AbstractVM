//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_POPFACTORY_HPP
#define ABSTRACTVM_POPFACTORY_HPP


#include "InstructionFactory.hpp"

class PopFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_POPFACTORY_HPP
