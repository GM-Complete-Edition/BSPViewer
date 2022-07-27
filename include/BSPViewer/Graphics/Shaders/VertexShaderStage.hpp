#pragma once

#include "BSPViewer/Graphics/Shaders/ShaderStage.hpp"
#include "BSPViewer/Graphics/Shaders/ShaderStageType.hpp"

class VertexShaderStage : public ShaderStage {
public:
	VertexShaderStage(const std::string& source) : ShaderStage(source, ShaderStageType::Vertex) {}

	VertexShaderStage(const VertexShaderStage& other) = delete;

    VertexShaderStage& operator =(const VertexShaderStage& other) = delete;
};
