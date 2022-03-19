#include "parser.h"
#include <fstream> 

objParser::objParser(string path) {
	cout << "HI" << endl;
	loadfile(path);
}

ostream& operator<<(ostream& os, const objParser::DDD_point& p) {
	os << p.x << " " << p.y << " " << p.z << "\n";
	return os;
}

void objParser::loadfile(string path) {
	ifstream fin(path);

	if(!fin) {
		cout << "Cannot open file: " << path << "\n";
	}


	while(!fin.eof()) {
		string tmp;

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
		cout << vertex;
	}
}
