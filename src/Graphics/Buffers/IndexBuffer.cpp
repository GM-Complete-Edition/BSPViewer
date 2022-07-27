#include <utility>

#include <glad/glad.h>

#include "BSPViewer/Graphics/Buffers/IndexBuffer.hpp"

IndexBuffer::IndexBuffer(std::vector<uint32_t> indices) {
	_indicesCount = indices.size();
	_indices = std::move(indices);

	bind();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * _indices.size(), _indices.data(), GL_STATIC_DRAW);
}


IndexBuffer::IndexBuffer(IndexBuffer&& other) {
	_bufferId = std::exchange(other._bufferId, 0);
	_indicesCount = std::exchange(other._indicesCount, 0);
	other._isMoved = true;
}

IndexBuffer& IndexBuffer::operator =(IndexBuffer&& other) {
	_bufferId = std::exchange(other._bufferId, 0);
	_indicesCount = std::exchange(other._indicesCount, 0);
	other._isMoved = true;
	
	return *this;
}


void IndexBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
}
