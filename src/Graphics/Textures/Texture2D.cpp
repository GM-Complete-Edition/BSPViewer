#include <glad/glad.h>

#include "BSPViewer/Graphics/Textures/Texture2D.hpp"

Texture2D::Texture2D(
	uint32_t width, 
	uint32_t height, 
	TextureFilter magnifyingFilter, 
	TextureFilter minifyingFilter, 
	TextureWrap wrapS, 
	TextureWrap wrapT
) : Texture() {
	glBindTexture(GL_TEXTURE_2D, _textureId);

	switch (magnifyingFilter) {
		case TextureFilter::Linear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			break;
	}

	switch (minifyingFilter) {
		case TextureFilter::Linear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			break;
	}

	switch (wrapS) {
		case TextureWrap::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

			break;
	}

	switch (wrapT) {
		case TextureWrap::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			break;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::Texture2D(Texture2D&& other) noexcept {
	_textureId = other._textureId;
	other._moved = true;
}

Texture2D& Texture2D::operator =(Texture2D&& other) noexcept {
	_textureId = other._textureId;
	other._moved = true;

	return *this;
}
