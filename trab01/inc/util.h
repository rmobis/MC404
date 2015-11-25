#pragma once

#include <stdbool.h>
#include <stddef.h>

#define COMMENT_CHAR '#'
#define SPACE_CHARACTERS " \t\n"

static const char *knownDirectives[] = {
	".set", ".org",
	".align", ".wfill",
	".word", NULL
};

static const char *knownMnemonics[] = {
	"LD", "LD-", "LD|", "LDmq",
	"LDmq_mx", "ST", "JMP", "JUMP+",
	"ADD", "ADD|", "SUB", "SUB|",
	"MUL", "DIF", "LSH", "RSH",
	"STaddr", NULL
};

#define LABEL_MAX_LENGTH 64
#define LABEL_ENDING_CHAR ':'

#define SYMBOL_MAX_LENGTH 64
#define MAX_INPUT_FILE_LENGTH 4096
#define MAX_LINE_LENGTH MAX_INPUT_FILE_LENGTH
#define MAX_TOKEN_LENGTH MAX_LINE_LENGTH

void strrep(char *str, char needle, char repl);


char *nextToken();

bool isSymbol(const char *token);
bool isLabel(const char *token);
bool isDirective(const char *token);
bool isInstruction(const char *token);
bool isComment(const char *token);
bool isNumeric(const char *str);
bool isHexadecimal(const char *str);
bool isAlphabetic(const char *str);
bool isAlphanumeric(const char *str);
bool isAlphanumeric_(const char *str);