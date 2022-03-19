#include "parser.h"

objParser::Vertex::Vertex(double x, double y, double z, double w) 
						  : x(x), y(y), z(z), w(w) {}

std::ostream& operator<<(std::ostream& os, const objParser::Vertex& p) {
	os << p.x << " " << p.y << " " << p.z << " " << p.w << "\n";
	return os;
}