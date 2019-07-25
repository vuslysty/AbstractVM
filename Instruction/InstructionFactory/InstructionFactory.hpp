//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_INSTRUCTIONFACTORY_HPP
#define ABSTRACTVM_INSTRUCTIONFACTORY_HPP


#include "../IInstruction.hpp"

class InstructionFactory
{
private:

	static InstructionFactory	*factories[11];

public:

	virtual IInstruction	*createInstruction(Fsm const &fsm);
};


#endif //ABSTRACTVM_INSTRUCTIONFACTORY_HPP
