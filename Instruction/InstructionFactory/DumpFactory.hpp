//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_DUMPFACTORY_HPP
#define ABSTRACTVM_DUMPFACTORY_HPP

#include "InstructionFactory.hpp"

class DumpFactory : public InstructionFactory
{
	IInstruction	*createInstruction(Fsm const &fsm) final;
};


#endif //ABSTRACTVM_DUMPFACTORY_HPP
