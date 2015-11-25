#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "error.h"
#include "util.h"
#include "types/private/assembler.h"
#include "types/assembler.h"
#include "types/directiveType.h"
#include "types/instruction.h"
#include "types/instructionType.h"
#include "types/operandType.h"
#include "types/label.h"
#include "types/location.h"
#include "types/memoryMap.h"
#include "types/operand.h"
#include "types/position.h"
#include "types/table.h"
#include "types/wordType.h"
#include "types/symbol.h"

#include "operandTypes/dec0_1023.h"
#include "operandTypes/dec0_231.h"
#include "operandTypes/dec0_232.h"
#include "operandTypes/dec1_1023.h"
#include "operandTypes/decN231_231.h"
#include "operandTypes/hex.h"
#include "operandTypes/instructionLabel.h"
#include "operandTypes/none.h"
#include "operandTypes/label.h"
#include "operandTypes/symbol.h"

#include "directiveTypes/align.h"
#include "directiveTypes/org.h"
#include "directiveTypes/set.h"
#include "directiveTypes/wfill.h"
#include "directiveTypes/word.h"

#include "instructionTypes/add.h"
#include "instructionTypes/addM.h"
#include "instructionTypes/div.h"
#include "instructionTypes/jump.h"
#include "instructionTypes/jumpP.h"
#include "instructionTypes/load.h"
#include "instructionTypes/loadM.h"
#include "instructionTypes/loadMQ.h"
#include "instructionTypes/loadMQ_MX.h"
#include "instructionTypes/loadN.h"
#include "instructionTypes/lsh.h"
#include "instructionTypes/mul.h"
#include "instructionTypes/rsh.h"
#include "instructionTypes/stor.h"
#include "instructionTypes/storA.h"
#include "instructionTypes/sub.h"
#include "instructionTypes/subM.h"


CompareItemMethod compareOperandType(const OperandType *item, const char *key) {
	return false;
}

CompareItemMethod compareDirectiveType(const DirectiveType *item, const char *key) {
	return false;
}

void initializeAssembler(Assembler *asmb) {

	////    ____                                  __   ______
	////   / __ \____  ___  _________ _____  ____/ /  /_  __/_  ______  ___  _____
	////  / / / / __ \/ _ \/ ___/ __ `/ __ \/ __  /    / / / / / / __ \/ _ \/ ___/
	//// / /_/ / /_/ /  __/ /  / /_/ / / / / /_/ /    / / / /_/ / /_/ /  __(__  )
	//// \____/ .___/\___/_/   \__,_/_/ /_/\__,_/    /_/  \__, / .___/\___/____/
	////     /_/                                         /____/_/

	OperandType *opDec0_1023   = createOperandType(&validateDec0_1023OpType, &getDec0_1023OpTypeValue);
	OperandType *opDec0_231    = createOperandType(&validateDec0_231OpType, &getDec0_231OpTypeValue);
	OperandType *opDec0_232    = createOperandType(&validateDec0_232OpType, &getDec0_232OpTypeValue);
	OperandType *opDec1_1023   = createOperandType(&validateDec1_1023OpType, &getDec1_1023OpTypeValue);
	OperandType *opDecN231_231 = createOperandType(&validateDecN231_231OpType, &getDecN231_231OpTypeValue);
	OperandType *opHex         = createOperandType(&validateHexOpType, &getHexOpTypeValue);
	OperandType *opInstrLabel  = createOperandType(&validateInstructionLabelOpType, &getInstructionLabelOpTypeValue);
	OperandType *opLabel       = createOperandType(&validateLabelOpType, &getLabelOpTypeValue);
	OperandType *opNone        = createOperandType(&validateNoneOpType, &getNoneOpTypeValue);
	OperandType *opSym         = createOperandType(&validateSymbolOpType, &getSymbolOpTypeValue);




	////     ____  _                __  _               ______
	////    / __ \(_)_______  _____/ /_(_)   _____     /_  __/_  ______  ___  _____
	////   / / / / / ___/ _ \/ ___/ __/ / | / / _ \     / / / / / / __ \/ _ \/ ___/
	////  / /_/ / / /  /  __/ /__/ /_/ /| |/ /  __/    / / / /_/ / /_/ /  __(__  )
	//// /_____/_/_/   \___/\___/\__/_/ |___/\___/    /_/  \__, / .___/\___/____/
	////                                                  /____/_/

	DirectiveType *dirAlign = createDirectiveType(
		".align",
		false,
		(OperandType*[]) { opDec1_1023, NULL },
		(OperandType*[]) { opNone, NULL },
		&executeAlignDirective
	);

	DirectiveType *dirOrg = createDirectiveType(
		".org",
		false,
		(OperandType*[]) { opHex, opDec0_1023, NULL },
		(OperandType*[]) { opNone, NULL },
		&executeOrgDirective
	);

	DirectiveType *dirSet = createDirectiveType(
		".set",
		true,
		(OperandType*[]) { opSym, NULL },
		(OperandType*[]) { opHex, opDec0_231, NULL },
		&executeSetDirective
	);

	DirectiveType *dirWfill = createDirectiveType(
		".wfill",
		true,
		(OperandType*[]) { opDec1_1023, NULL },
		(OperandType*[]) { opHex, opDecN231_231, opLabel, opSym, NULL },
		&executeWfillDirective
	);

	DirectiveType *dirWord = createDirectiveType(
		".word",
		false,
		(OperandType*[]) { opHex, opDec0_232, opLabel, opSym, NULL },
		(OperandType*[]) { opNone, NULL },
		&executeWordDirective
	);



	InstructionType *instrAdd       = createInstructionType("ADD",     0x05, false, true);
	InstructionType *instrAddM      = createInstructionType("ADD|",    0x07, false, true);
	InstructionType *instrDiv       = createInstructionType("DIV",     0x0C, false, true);
	InstructionType *instrJump      = createInstructionType("JMP",     0x0D, true,  true);
	InstructionType *instrJumpP     = createInstructionType("JUMP+",   0x0F, true,  true);
	InstructionType *instrLoad      = createInstructionType("LD",      0x01, false, true);
	InstructionType *instrLoadM     = createInstructionType("LD|",     0x03, false, true);
	InstructionType *instrLoadMQ    = createInstructionType("LDmq",    0x0A, false, true);
	InstructionType *instrLoadMQ_MX = createInstructionType("LDmq_mx", 0x09, false, true);
	InstructionType *instrLoadN     = createInstructionType("LD-",     0x02, false, true);
	InstructionType *instrLsh       = createInstructionType("LSH",     0x14, false, false);
	InstructionType *instrMul       = createInstructionType("MUL",     0x0B, false, true);
	InstructionType *instrRsh       = createInstructionType("RSH",     0x15, false, false);
	InstructionType *instrStor      = createInstructionType("ST",      0x21, false, true);
	InstructionType *instrStorA     = createInstructionType("STaddr",  0x12, true,  true);
	InstructionType *instrSub       = createInstructionType("SUB",     0x06, false, true);
	InstructionType *instrSubM      = createInstructionType("SUB|",    0x08, false, true);






	Table *opTypeTable     =
	asmb->operandTypeTable = createTable(10, (bool (*)(const void*, const void*))compareOperandType);

	opTypeTable->addItem(opTypeTable, opDec0_1023);
	opTypeTable->addItem(opTypeTable, opDec0_231);
	opTypeTable->addItem(opTypeTable, opDec0_232);
	opTypeTable->addItem(opTypeTable, opDec1_1023);
	opTypeTable->addItem(opTypeTable, opDecN231_231);
	opTypeTable->addItem(opTypeTable, opHex);
	opTypeTable->addItem(opTypeTable, opInstrLabel);
	opTypeTable->addItem(opTypeTable, opLabel);
	opTypeTable->addItem(opTypeTable, opNone);
	opTypeTable->addItem(opTypeTable, opSym);







	Table *dirTypeTable      =
	asmb->directiveTypeTable = createTable(5, (bool (*)(const void*, const void*))compareDirectiveType);

	dirTypeTable->addItem(dirTypeTable, dirAlign);
	dirTypeTable->addItem(dirTypeTable, dirOrg);
	dirTypeTable->addItem(dirTypeTable, dirSet);
	dirTypeTable->addItem(dirTypeTable, dirWfill);
	dirTypeTable->addItem(dirTypeTable, dirWord);
}

Assembler *createAssembler(FILE *sourceFile, int maxLabels, int maxSymbols) {
	Assembler *asmb = malloc(sizeof(Assembler));

	asmb->LC = createLocation(0, LeftPosition);
	asmb->labelTable = createTable(LABEL_TABLE_SIZE, (bool (*)(const void*, const void*))compareLabel);
	asmb->symbolTable = createTable(SYMBOL_TABLE_SIZE, (bool (*)(const void*, const void*))compareSymbol);
	asmb->memoryMap = createMemoryMap(MEMORY_MAP_SIZE);

	asmb->parse = &parse;
	asmb->parseLine = &parseLine;
	asmb->handleLabel = &handleLabel;
	asmb->handleDirective = &handleDirective;
	asmb->handleInstruction = &handleInstruction;
	asmb->free = &freeAssembler;

	initializeAssembler(asmb);

	return asmb;
}

void parse(Assembler *this) {
	char line[MAX_LINE_LENGTH];

	rewind(this->sourceFile);
	this->fileLine = 0;

	while (fgets(line, sizeof(line), this->sourceFile)) {
		this->fileLine++;
		this->parseLine(this, line);
	}
}

void parseLine(Assembler *this, char* line) {
	char *token = strtok(line, SPACE_CHARACTERS);

	if (isLabel(token)) {
		this->handleLabel(this, token);

		token = nextToken();
	}

	if (isDirective(token)) {
		this->handleDirective(this, token);
		token = nextToken();
	} else if (isInstruction(token)) {
		this->handleInstruction(this, token);

		token = nextToken();
	}


	if (token != NULL && !isComment(token)) {
		reportError(ERROR_UNEXPECTED_TOKEN, this->fileLine);
	}
}

void handleLabel(Assembler *this, char *token) {
	// Trim the ending colon
	token[strlen(token) - 1] = '\0';

	Table *labelTable = this->labelTable;

	// Labels MUST NOT be declared twice
	if (labelTable->getItem(labelTable, token) != NULL) {
		reportError(ERROR_LABEL_REDEFINITION, this->fileLine);
	}

	Location *loc = cloneLocation(this->LC);
	Label    *lab = createLabel(token, loc);

	if (!labelTable->addItem(labelTable, lab)) {
		reportError(ERROR_TABLE_FULL, this->fileLine);
	}
}

void handleDirective(Assembler *this, char *token) {
	Table *directiveTypeTable = this->directiveTypeTable;

	DirectiveType *dirType = directiveTypeTable->getItem(directiveTypeTable, token);

	Operand *firstOp = createOperand(
		nextToken(),
		dirType->firstOperandTypes
	);

	Operand *secondOp = createOperand(
		dirType->hasSecondOperand ? nextToken() : NULL,
		dirType->secondOperandTypes
	);

	if (firstOp == NULL || secondOp == NULL) {
		reportError(ERROR_INVALID_DIRECTIVE_OPERAND, this->fileLine);
	}

	dirType->execute(dirType, firstOp, secondOp, this);
	dirType->free(dirType);
}

void handleInstruction(Assembler *this, char *token) {
	Table *instructionTypeTable = this->instructionTypeTable;

	InstructionType *instrType = instructionTypeTable->getItem(instructionTypeTable, token);

	Operand *op = createOperand(
		instrType->hasOperand ? nextToken() : NULL,
		instrType->operandTypes
	);

	if (op == NULL) {
		reportError(ERROR_INVALID_INSTRUCTION_OPERAND, this->fileLine);
	}

	Instruction *instr = createInstruction(instrType, op);

	MemoryMap *memoryMap = this->memoryMap;
	if (memoryMap->isFilled(memoryMap, this->LC, InstructionWord)) {
		reportError(ERROR_MEMORY_MAP_REDEFINITION, this->fileLine);
	}

	memoryMap->addInstruction(memoryMap, instr, this->LC);
}

bool compareLabel(const Label *item, const char *key) {
	return false;
}

bool compareSymbol(const Symbol *item, const char *key) {
	return false;
}

void freeAssembler(Assembler *this) {

}

Table *buildDirectiveTypeTable(Assembler *asmb) {
	return NULL;
}