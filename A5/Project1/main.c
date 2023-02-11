#include <stdio.h>

int sharper(char* command) {
	int ball = 1;
	while (*command) {
		if ((*command == 'A') && (ball == 1)) ball = 2;
		else if ((*command == 'A') && (ball == 2)) ball = 1;
		else if ((*command == 'B') && (ball == 2)) ball = 3;
		else if ((*command == 'B') && (ball == 3)) ball = 2;
		else if ((*command == 'C') && (ball == 1)) ball = 3;
		else if ((*command == 'C') && (ball == 3)) ball = 1;
		command++;
	}
	return ball;
}

int main() {
	char* command = "ABCC";
	printf("%d", sharper(command));
	return 0;
}