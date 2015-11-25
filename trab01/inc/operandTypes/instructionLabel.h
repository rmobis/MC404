

#pragma once

#include "types/typedefs.h"

bool validateInstructionLabelOpType(char const* token);

long long getInstructionLabelOpTypeValue(char const* token, Assembler *asmb);