#include <stdexcept>

#include <glad/glad.h>

#include "BSPViewer/Graphics/Shaders/ShaderStage.hpp"

ShaderStage::ShaderStage(const std::string& source, ShaderStageType shaderStageType) {
	switch (shaderStageType) {
		case ShaderStageType::Fragment:
			_shaderStageId = glCreateShader(GL_FRAGMENT_SHADER);
			
			break;
		case ShaderStageType::Vertex:
			_shaderStageId = glCreateShader(GL_VERTEX_SHADER);

			break;
	}

	const char* sourceCString = source.c_str();
	auto sourceSize = static_cast<int>(source.size());

	glShaderSource(_shaderStageId, 1, &sourceCString, &sourceSize);
	glCompileShader(_shaderStageId);

	int32_t shaderStageResult = 0;
	glGetShaderiv(_shaderStageId, GL_COMPILE_STATUS, &shaderStageResult);

	if (!shaderStageResult) {
		constexpr size_t SIZE = 512;

		char buffer[SIZE];
		glGetShaderInfoLog(_shaderStageId, SIZE, nullptr, buffer);

		throw std::runtime_error("Failed to compile the shader stage");
	}
}

ShaderStage::~ShaderStage() {
	glDeleteShader(_shaderStageId);
}
