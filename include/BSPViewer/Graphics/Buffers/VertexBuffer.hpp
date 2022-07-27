#pragma once

#include <cstdint>
#include <vector>

#include <libbsp/Primitives/Vector3.hpp>

#include "BSPViewer/Graphics/Buffers/Buffer.hpp"
#include "BSPViewer/Graphics/Buffers/VertexBufferLayout.hpp"

class VertexBuffer : public Buffer {
private:
	std::vector<bsp::Vector3> _vertices;
	size_t _verticesCount = 0;
public:
	VertexBuffer(std::vector<bsp::Vector3> vertices, const VertexBufferLayout& layout);
	VertexBuffer(const VertexBuffer& other) = delete;
	VertexBuffer(VertexBuffer&& other);

	~VertexBuffer() = default;

    VertexBuffer& operator =(const VertexBuffer& other) = delete;
    VertexBuffer& operator =(VertexBuffer&& other);

    [[nodiscard]] inline size_t getVerticesCount() const {
		return _verticesCount;
	}

	void bind() override;
};
