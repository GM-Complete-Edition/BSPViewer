#pragma once

#include <cstdint>
#include <vector>

#include "BSPViewer/Graphics/Buffers/Buffer.hpp"

class IndexBuffer : public Buffer {
private:
	std::vector<uint32_t> _indices;
	size_t _indicesCount = 0;
public:
	IndexBuffer(std::vector<uint32_t> indices);
	IndexBuffer(const IndexBuffer& other) = delete;
	IndexBuffer(IndexBuffer&& other);

	~IndexBuffer() = default;

	IndexBuffer& operator =(const IndexBuffer& other) = delete;
	IndexBuffer& operator =(IndexBuffer&& other);

	[[nodiscard]] inline size_t getIndicesCount() const {
		return _indicesCount;
	}

	void bind() override;
};
