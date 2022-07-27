#pragma once

#include <cstdint>

class Texture {
protected:
	uint32_t _textureId;
	bool _moved = false;
public:
	Texture();

	~Texture();

	[[nodiscard]] inline uint32_t getId() const {
		return _textureId;
	}
};
