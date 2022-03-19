#include <iostream>
#include <string>
#include <vector>

class objParser {
public:
	struct Vertex {
private:
		double x, y, z, w;
public:
		// Constructor
		Vertex();
		Vertex(double x, double y, double z, double w);

		// Print
		friend std::ostream& operator<<(std::ostream& os, const Vertex& p);
		
		// Set funciton
		void set(double x, double y, double z, double w);
	};

	struct Face {};

	objParser(std::string path);
	~objParser();

	void printVertexes();

	// vertexes
	std::vector<Vertex> vertexes;

private:
	// Vertex parser
	Vertex parseVertex(std::string input);

	// Parser handler
	void parseObjFile(std::string path);
	
};