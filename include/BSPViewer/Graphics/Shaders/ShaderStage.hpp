#pragma once

#include <cstdint>
#include <string>

#include "BSPViewer/Graphics/Shaders/ShaderStageType.hpp"

class ShaderStage {
private:
	uint32_t _shaderStageId;
public:
	ShaderStage(const std::string& source, ShaderStageType shaderStageType);

	~ShaderStage();

	[[nodiscard]] inline uint32_t getId() const {
		return _shaderStageId;
	}
};
