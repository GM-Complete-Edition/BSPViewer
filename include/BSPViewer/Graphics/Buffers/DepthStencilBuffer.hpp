#pragma once

#include <cstdint>

#include "BSPViewer/Graphics/Buffers/RenderBuffer.hpp"

class DepthStencilBuffer : public RenderBuffer {
public:
	DepthStencilBuffer(uint32_t width, uint32_t height);
};
