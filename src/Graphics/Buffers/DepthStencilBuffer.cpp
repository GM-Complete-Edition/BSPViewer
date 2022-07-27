#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/DepthStencilBuffer.hpp"

DepthStencilBuffer::DepthStencilBuffer(uint32_t width, uint32_t height) : RenderBuffer() {
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
}
