#include "parser.h"
#include <fstream> 

std::ostream& operator<<(std::ostream& os, const objParser::DDD_point& p) {
	os << p.x << " " << p.y << " " << p.z << "\n";
	return os;
}

objParser::objParser(std::string path) {
	loadfile(path);
}

void objParser::loadfile(std::string path) {
	std::ifstream fin(path);
	std::cout << "Open file: " << path << "\n";
	if(!fin) {
		std::cout << "Cannot open file filaed: " << path << "\n";
	}


	while(!fin.eof()) {
		std::string tmp;

		fin >> tmp;

		if(tmp[0] == 'v') {
			DDD_point tmp_point;
			fin >> tmp_point.x >> tmp_point.y >> tmp_point.z;
			vertexes.emplace_back(tmp_point);
		}
	}
}

void objParser::printVertexes() {
	for(DDD_point vertex : vertexes) {
		std::cout << vertex;
	}
}
