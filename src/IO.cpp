#include <fstream>
#include <iterator>

#include "BSPViewer/IO.hpp"

std::string readFileToString(const std::filesystem::path& filePath) {
	std::ifstream file(filePath);

	std::string fileSource;

	file.seekg(0, std::ios::end);
	fileSource.reserve(file.tellg());
	file.seekg(0, std::ios::beg);
	fileSource.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	return fileSource;
}
