#include <stdexcept>

#include <glad/glad.h>

#include "BSPViewer/Graphics/Shaders/Shader.hpp"

Shader::Shader(const VertexShaderStage& vertexShaderStage, const FragmentShaderStage& fragmentShaderStage) {
	_shaderId = glCreateProgram();

	glAttachShader(_shaderId, vertexShaderStage.getId());
	glAttachShader(_shaderId, fragmentShaderStage.getId());

	glLinkProgram(_shaderId);

	int32_t shaderLinkageResult = 0;
	glGetProgramiv(_shaderId, GL_LINK_STATUS, &shaderLinkageResult);

	if (!shaderLinkageResult) {
		constexpr size_t SIZE = 512;

		char buffer[SIZE];
		glGetProgramInfoLog(_shaderId, SIZE, nullptr, buffer);

		throw std::runtime_error("Failed to link the shader");
	}

	glDetachShader(_shaderId, vertexShaderStage.getId());
	glDetachShader(_shaderId, fragmentShaderStage.getId());
}

Shader::~Shader() {
	glDeleteProgram(_shaderId);
}

void Shader::bind() {
	glUseProgram(_shaderId);
}
