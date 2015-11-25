/**
 * Error Reporting API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#define SYNTAX_ERROR(E) ((E) | ERROR_SYNTAX)

#define ERROR_INVALID_ARGS              0x001
#define ERROR_READ_FILE                 0x002
#define ERROR_TABLE_FULL                0x002

#define ERROR_SYNTAX                    0x1000
#define ERROR_UNEXPECTED_TOKEN          SYNTAX_ERROR(0x001)
#define ERROR_LABEL_REDEFINITION        SYNTAX_ERROR(0x002)
#define ERROR_INVALID_DIRECTIVE_OPERAND SYNTAX_ERROR(0x003)
#define ERROR_INVALID_INSTRUCTION_OPERAND SYNTAX_ERROR(0x004)
#define ERROR_MEMORY_MAP_REDEFINITION SYNTAX_ERROR(0x005)
#define ERROR_UNDEFINED_SYMBOL SYNTAX_ERROR(0x006)
#define ERROR_UNDEFINED_LABEL SYNTAX_ERROR(0x007)
#define ERROR_RIGHT_ALIGNED_WORD SYNTAX_ERROR(0x008)

#define ERROR_MSG_INVALID_ARGS     "Invalid arguments passed! Please call the assembler using the following syntax:\n/ias-as <source-file> [<map-file>]\n"
#define ERROR_MSG_READ_FILE        "Unable to open source file!"
#define ERROR_MSG_UNKNOWN          "Unknown error occured!"
#define ERROR_MSG_UNEXPECTED_TOKEN "Unexpected token found!"



/**
 * Outputs to stderr the message corresponding to the error code passed. If it
 * is a syntax error, also outputs the line on which it occurred first.
 *
 * @param	errorCode	The error code.
 * @param	line		The line.
 */
void reportError(int errorCode, int line);

/**
 * Gets the error message corresponding to the error code passed.
 *
 * @param	errorCode	The error code.
 *
 * @return	The error message.
 */
char const *getErrorMessage(int errorCode);