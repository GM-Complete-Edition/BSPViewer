#pragma once

#include <cstdint>
#include <unordered_map>

#include "BSPViewer/Graphics/Shaders/FragmentShaderStage.hpp"
#include "BSPViewer/Graphics/Shaders/VertexShaderStage.hpp"

class Shader {
private:
	uint32_t _shaderId;

	std::unordered_map<std::string, int32_t> _uniformLocations;
public:
	Shader(const VertexShaderStage& vertexShaderStage, const FragmentShaderStage& fragmentShaderStage);
	Shader(const Shader& other) = delete;

	~Shader();

	Shader& operator =(const Shader& other) = delete;

	template<typename T>
	void set(const std::string& name, T value);

	void bind();
};
