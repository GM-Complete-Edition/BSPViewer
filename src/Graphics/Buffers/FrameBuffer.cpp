#include <stdexcept>
#include <utility>

#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/FrameBuffer.hpp"

FrameBuffer::FrameBuffer(Texture2D colorAttachment, DepthStencilBuffer depthStencilAttachment) : _colorAttachment(std::move(colorAttachment)), _depthStencilAttachment(std::move(depthStencilAttachment)) {
	glGenFramebuffers(1, &_frameBufferId);

	glBindFramebuffer(GL_FRAMEBUFFER, _frameBufferId);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorAttachment.getId(), 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthStencilAttachment.getId());

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		throw std::runtime_error("Failed to create a frame buffer");
	}
}

FrameBuffer::~FrameBuffer() {
	glDeleteFramebuffers(1, &_frameBufferId);
}

void FrameBuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, _frameBufferId);
}

Texture2D& FrameBuffer::getColorAttachment() {
	return _colorAttachment;
}

DepthStencilBuffer& FrameBuffer::getDepthStencilAttachment() {
	return _depthStencilAttachment;
}
