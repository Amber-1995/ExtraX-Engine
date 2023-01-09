#pragma once
#ifndef EXTRAX_SHADER_BASE_H
#define EXTRAX_SHADER_BASE_H

#include <ExtraX/StringLiteral.h>
#include <ExtraX/ResourceManager.h>
#include <ExtraX/Graphics/Context/ContextBase.h>

namespace ExtraX::Graphics
{
	class Shader
	{
	public:
		virtual void Bind(uint32_t = 0) = 0;
		virtual void Unbind(uint32_t = 0) = 0;
	};
}

namespace ExtraX::Graphics::Base
{

	template<StringLiteral>
	class ShaderResourceManager;

	template<StringLiteral>
	class Shader;
}
#endif // !EXTRAX_SHADER_BASE_H
