#include "parser.h"

int main(int argc, char* argv[]) {
	objParser *op = new objParser(argv[1]);

	op -> printVertexes();

	return 0;
}