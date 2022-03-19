#include "parser.h"
#include <fstream>
#include <sstream>

#define STR_LENG 256

objParser::objParser(std::string path) {
	parseObjFile(path);
}

objParser::Vertex objParser::parseVertex(std::string input) {
	// parse vertex (x, y, z [,w])
	double x, y, z, w = 1.0;
	std::stringstream ss(input);
	ss >> x >> y >> z >> w;

	objParser::Vertex tmp_point(x, y, z, w);

	return tmp_point;
}

void objParser::parseObjFile(std::string path) {
	std::ifstream fin(path);

#ifdef VERBOSE
	std::cout << "Open file: " << path << "\n";
#endif

	if(!fin) {
		std::cout << "Cannot open file filaed: " << path << "\n";
		return ;
	}

	while(!fin.eof()) {
		std::string tmp;
		fin >> tmp;

		if(tmp[0] == 'v') {
			char tmp[256];
			fin.getline(tmp, 256);
			vertexes.emplace_back(parseVertex(tmp));
		}
	}
}

void objParser::printVertexes() {
	int cnt = 0;
	for(Vertex vertex : vertexes) {
		std::cout << cnt++ << " " << vertex;
	}
}
