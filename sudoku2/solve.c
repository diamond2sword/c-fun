int solve(char* puzzle) {
	printf("Am I solving %s?\n", puzzle);
	run();
	return 1;
}

int run() {
	UNUSED[9*9*9];
	createUnusedArray();
	return 1;
}

int say(const char* stpr) {
	char* fmt = "\e[0;93m";
	char* varFmt = "\e[1;96m";
	char* noc = "\e[m";
	int isFirst = 1;
	printf("%s", fmt);
	for (int i=0; i<strlen(str); i++) {
		if (str[i] != '\'') {
			printf("%c", str[i]);
			continue;
		}
		if (isFirst) {
			printf("%c%s%s", str[i], noc, varFmt);
			isFirst = !isFirst;
			continue;
		}
		if (!isFirst) {
			printf("%s%s%c", noc, fmt, str[i]);
			isFirst = !isFirst;
			continue;
		}
	}
	printf("%s\n", noc);
	return 1;
}

#include <string.h>
