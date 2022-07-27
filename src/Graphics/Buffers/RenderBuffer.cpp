#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/RenderBuffer.hpp"

RenderBuffer::RenderBuffer() {
	glGenRenderbuffers(1, &_renderBufferId);
}

RenderBuffer::~RenderBuffer() {
	glDeleteRenderbuffers(1, &_renderBufferId);
}

void RenderBuffer::bind() {
	glBindRenderbuffer(GL_RENDERBUFFER, _renderBufferId);
}
