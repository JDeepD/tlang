#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

static void init(){
	Line = 1;
	Putback = '\n';
}

char *tokstr[] = { "+", "-", "*", "/", "Int Literal" };

static void scanfile() {
	struct token T;
	while(scan(&T)){
		printf("Token %s", tokstr[T.token]);
		if(T.token == T_INTLIT) printf(": value %d", T.intvalue);
		printf("\n");
	}
}

void main(int argc, char *argv[]){
	if(argc != 2) {
		fprintf(stderr, "Incorrect number of args");
		exit(1);
	}
	init();
	if((Infile = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Input file not found %s", argv[1]);
		exit(1);
	};
	scanfile();
	exit(0);
}
