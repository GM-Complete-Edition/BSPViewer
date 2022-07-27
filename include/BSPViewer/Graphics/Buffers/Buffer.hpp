#pragma once

#include <cstdint>

class Buffer {
protected:
	uint32_t _bufferId;

	bool _isMoved = false;
public:
	Buffer();

	~Buffer();

	virtual void bind() = 0;
};
