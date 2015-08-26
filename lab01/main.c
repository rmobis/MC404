#include <stdio.h>

int sum(int a, int b);
void logMsg(const char *msg);

int main() {
	logMsg("I'm on main!\n");

	printf("%d + %d = %d\n", 3, 4, sum(3, 4));
}