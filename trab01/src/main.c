#include <stdio.h>
#include "error.h"
#include "util.h"
#include "types/label.h"
#include "types/location.h"
#include "types/position.h"
#include "types/table.h"
#include "types/wordType.h"
#include "types/word.h"
#include "types/assembler.h"


int main(int argc, char const *argv[]) {

#ifdef _DEBUG
	argc = 2;
	argv[1] = "D:/test.ias";
#endif

	if (argc != 2 && argc != 3) {
		reportError(ERROR_INVALID_ARGS, 0);
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		reportError(ERROR_READ_FILE, 0);
	}

	Assembler *asmb = createAssembler(f, 500, 500);

	getchar();
	return 0;
}