#include <stdexcept>

#include <glad/glad.h>
#include <glm/mat4x4.hpp>

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

template<> 
void Shader::set(const std::string& name, glm::mat4 value) {
	if (_uniformLocations.contains(name)) {
		const int32_t& uniformLocation = _uniformLocations.at(name);

		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&value));
	} else {
		int32_t uniformLocation = glGetUniformLocation(_shaderId, name.c_str());

		_uniformLocations[name] = uniformLocation;

		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&value));
	}
}

void Shader::bind() {
	glUseProgram(_shaderId);
}
