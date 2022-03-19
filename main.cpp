#include "parser.h"

int main() {
	objParser *op = new objParser("./bunny.obj");

	op -> printVertexes();

	return 0;
}