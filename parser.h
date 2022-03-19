#include <iostream>
#include <string>
#include <vector>

class objParser {
public:
	struct DDD_point {
		double x, y, z;

		friend std::ostream& operator<<(std::ostream& os, const DDD_point& p);
	};

	struct Face {};

	objParser(std::string path);
	~objParser();

	void printVertexes();

private:
	void loadfile(std::string path);
	
	std::vector<DDD_point> vertexes;
	// void render();
};