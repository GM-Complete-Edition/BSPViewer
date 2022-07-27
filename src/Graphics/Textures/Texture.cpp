#include <glad/glad.h>

#include "BSPViewer/Graphics/Textures/Texture.hpp"

Texture::Texture() {
	glGenTextures(1, &_textureId);
}

Texture::~Texture() {
	if (!_moved) {
		glDeleteTextures(1, &_textureId);
	}
}
