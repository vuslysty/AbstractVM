//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_ADDFACTORY_HPP
#define ABSTRACTVM_ADDFACTORY_HPP


#include "InstructionFactory.hpp"
#include "../AddInstruction.hpp"

class AddFactory : public InstructionFactory
{
public:
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_ADDFACTORY_HPP
