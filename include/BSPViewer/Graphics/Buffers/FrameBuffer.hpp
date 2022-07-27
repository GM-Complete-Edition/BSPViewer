#pragma once

#include <cstdint>

#include "BSPViewer/Graphics/Buffers/DepthStencilBuffer.hpp"
#include "BSPViewer/Graphics/Textures/Texture2D.hpp"

class FrameBuffer {
private:
	uint32_t _frameBufferId;

	Texture2D _colorAttachment;
	DepthStencilBuffer _depthStencilAttachment;
public:
	FrameBuffer(Texture2D colorAttachment, DepthStencilBuffer depthStencilAttachment);

	FrameBuffer(const FrameBuffer& other) = delete;

	~FrameBuffer();

    FrameBuffer& operator =(const FrameBuffer& other) = delete;

	void bind();

	[[nodiscard]] Texture2D& getColorAttachment();

	[[nodiscard]] DepthStencilBuffer& getDepthStencilAttachment();
};
