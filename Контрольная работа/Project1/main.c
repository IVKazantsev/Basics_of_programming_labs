#include <stdio.h>

int Calc(char* exp) {

	int equals = 0, number = 0, onlyxleft = 0, hard = 0, onlynumberleft = 0, sign = 0;

	for (int i = 0; i < 5; i++) {

		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '%' || exp[i] == '*') sign = 1;

		if (exp[i] == '=') {

			equals = 1;

			if ((equals == 1) && (number == 1) && (sign == 0)) onlynumberleft = 1;

			else if (equals == 1 && number == 0) onlyxleft = 1;

			else if (equals == 1 && number == 1) hard = 1;

		}

		else if ((exp[i] >= '0') && (exp[i] <= '9')) {

			number++;

			if ((number == 2 && equals == 0) || (onlyxleft == 1 && number == 2)) {

				if (exp[i - 1] == '+') return ((int)exp[i - 2] - '0') + ((int)exp[i] - '0');

				else if (exp[i - 1] == '-') return ((int)exp[i - 2] - '0') - ((int)exp[i] - '0');

				else if (exp[i - 1] == '*') return ((int)exp[i - 2] - '0') * ((int)exp[i] - '0');

				else if (exp[i - 1] == '/') return ((int)exp[i - 2] - '0') / ((int)exp[i] - '0');

				else if (exp[i - 1] == '%') return ((int)exp[i - 2] - '0') % ((int)exp[i] - '0');

			}

			else if ((number == 2) && (hard == 1) && (exp[2] == 'x')) {

				if (exp[1] == '+') return ((int)exp[i] - '0') - ((int)exp[0] - '0');

				else if (exp[1] == '-') return ((int)exp[0] - '0') - ((int)exp[i] - '0');

				else if (exp[1] == '*') return ((int)exp[i] - '0') / ((int)exp[0] - '0');

				else if (exp[1] == '/') return ((int)exp[0] - '0') / ((int)exp[i] - '0');

				else if (exp[1] == '%') return ((int)exp[0] - '0') - ((int)exp[4] - '0');

			}

			else if ((number == 2) && (hard == 1) && (exp[0] == 'x')) {

				if (exp[1] == '+') return ((int)exp[i] - '0') - ((int)exp[2] - '0');

				else if (exp[1] == '-') return ((int)exp[i] - '0') + ((int)exp[2] - '0');

				else if (exp[1] == '*') return ((int)exp[i] - '0') / ((int)exp[2] - '0');

				else if (exp[1] == '/') return ((int)exp[i] - '0') * ((int)exp[2] - '0');

			}

			else if ((number == 2) && (onlynumberleft == 1) && (exp[4] == 'x')) {

				if (exp[3] == '+') return ((int)exp[0] - '0') - ((int)exp[2] - '0');

				else if (exp[3] == '-') return ((int)exp[2] - '0') - ((int)exp[0] - '0');

				else if (exp[3] == '*') return ((int)exp[0] - '0') / ((int)exp[2] - '0');

				else if (exp[3] == '/') return ((int)exp[0] - '0') / ((int)exp[2] - '0');

				else if (exp[3] == '%') return ((int)exp[2] - '0') - ((int)exp[0] - '0');

			}

			else if ((number == 2) && (onlynumberleft == 1) && (exp[2] == 'x')) {

				if (exp[3] == '+') return ((int)exp[0] - '0') - ((int)exp[4] - '0');

				else if (exp[3] == '-') return ((int)exp[4] - '0') + ((int)exp[0] - '0');

				else if (exp[3] == '*') return ((int)exp[0] - '0') / ((int)exp[4] - '0');

				else if (exp[3] == '/') return ((int)exp[0] - '0') * ((int)exp[4] - '0');

			}

		}

	}

}

int main() {

	//

	char* expression[] = { "x=5*2", "x=8/3", "2+4=x", "9*9=x", "2+x=5", "5-x=2", "4*x=8", "8/x=4", "x+2=5", "x-5=2", "x*4=8","x/2=5", "6=x+2", "6=2+x", "2=6-x", "2=x-6", "6=2*x", "6=x*2","6=x/2", "6=6/x", "x=3%2", "3%2=x", "3%x=1", "1=3%x" };

	int len = sizeof(expression) / sizeof(char*);

	for (int i = 0; i < len; i++)

		printf("%s x=%d\n", expression[i], Calc(expression[i]));

	return 0;

}