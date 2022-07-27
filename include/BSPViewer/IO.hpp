#pragma once

#include <filesystem>
#include <string>

[[nodiscard]] std::string readFileToString(const std::filesystem::path& filePath);
