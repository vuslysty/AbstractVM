//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_PRINTFACTORY_HPP
#define ABSTRACTVM_PRINTFACTORY_HPP


#include "InstructionFactory.hpp"

class PrintFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_PRINTFACTORY_HPP
