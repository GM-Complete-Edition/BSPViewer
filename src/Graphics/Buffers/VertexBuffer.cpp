#include <utility>

#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/VertexBuffer.hpp"

VertexBuffer::VertexBuffer(std::vector<bsp::Vector3> vertices, const VertexBufferLayout& layout) {
	_verticesCount = vertices.size();
	_vertices = std::move(vertices);

	bind();

	glBufferData(GL_ARRAY_BUFFER, sizeof(bsp::Vector3) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);

	size_t offset = 0;

	for (size_t i = 0; i < layout.getElements().size(); i++) {
		const auto& element = layout.getElements()[i];

		glVertexAttribPointer(
			i, 
			element.getCount(), 
			element.getRawType(), 
			element.isNormalized(), 
			layout.getStride(), 
			reinterpret_cast<void*>(offset)
		);
		glEnableVertexAttribArray(i);

		offset += element.getSize();
	}
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) {
	_bufferId = std::exchange(other._bufferId, 0);
	_verticesCount = std::exchange(other._verticesCount, 0);
	other._isMoved = true;
}

VertexBuffer& VertexBuffer::operator =(VertexBuffer&& other) {
	_bufferId = std::exchange(other._bufferId, 0);
	_verticesCount = std::exchange(other._verticesCount, 0);
	other._isMoved = true;

	return *this;
}

void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
}
