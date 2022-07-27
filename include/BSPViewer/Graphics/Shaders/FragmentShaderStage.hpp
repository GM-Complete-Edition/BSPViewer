#pragma once

#include "BSPViewer/Graphics/Shaders/ShaderStage.hpp"
#include "BSPViewer/Graphics/Shaders/ShaderStageType.hpp"

class FragmentShaderStage : public ShaderStage {
public:
	FragmentShaderStage(const std::string& source) : ShaderStage(source, ShaderStageType::Fragment) {}

	FragmentShaderStage(const FragmentShaderStage& other) = delete;

    FragmentShaderStage& operator =(const FragmentShaderStage& other) = delete;
};
