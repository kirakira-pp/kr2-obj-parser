#include <iostream>
#include <string>
#include <vector>

using namespace std;

class objParser {
public:
	struct DDD_point {
		double x, y, z;

		friend ostream& operator<<(ostream& os, const DDD_point& p);
	};

	struct Face {};

	objParser(string path);
	~objParser();

	void printVertexes();

private:
	void loadfile(string path);
	
	vector<DDD_point> vertexes;
	// void render();
};