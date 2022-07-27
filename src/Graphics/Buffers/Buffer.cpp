#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/Buffer.hpp"

Buffer::Buffer() {
	glGenBuffers(1, &_bufferId);
}

Buffer::~Buffer() {
	if (!_isMoved) {
		glDeleteBuffers(1, &_bufferId);
	}
}
