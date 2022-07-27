#pragma once

#include <cstdint>

class RenderBuffer {
protected:
	uint32_t _renderBufferId;
public:
	RenderBuffer();

	~RenderBuffer();

	void bind();

	[[nodiscard]] inline uint32_t getId() {
		return _renderBufferId;
	}
};
