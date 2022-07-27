#pragma once

#include <cstdint>

#include "BSPViewer/Graphics/Shaders/FragmentShaderStage.hpp"
#include "BSPViewer/Graphics/Shaders/VertexShaderStage.hpp"

class Shader {
private:
	uint32_t _shaderId;
public:
	Shader(const VertexShaderStage& vertexShaderStage, const FragmentShaderStage& fragmentShaderStage);
	Shader(const Shader& other) = delete;

	~Shader();

	Shader& operator =(const Shader& other) = delete;

	void bind();
};
