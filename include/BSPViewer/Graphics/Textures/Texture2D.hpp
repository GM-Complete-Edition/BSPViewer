#pragma once

#include "BSPViewer/Graphics/Textures/Texture.hpp"
#include "BSPViewer/Graphics/Textures/TextureFilter.hpp"
#include "BSPViewer/Graphics/Textures/TextureWrap.hpp"

class Texture2D : public Texture {
public:
	Texture2D(
		uint32_t width, 
		uint32_t height, 
		TextureFilter magnifyingFilter, 
		TextureFilter minifyingFilter, 
		TextureWrap wrapS, 
		TextureWrap wrapT
	);
	Texture2D(const Texture2D& other) = delete;
	Texture2D(Texture2D&& other) noexcept;

	Texture2D& operator =(const Texture2D& other) = delete;
	Texture2D& operator =(Texture2D&& other) noexcept;
};
