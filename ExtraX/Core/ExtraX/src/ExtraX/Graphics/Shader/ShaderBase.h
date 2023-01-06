#pragma once
#ifndef EXTRAX_SHADER_BASE_H
#define EXTRAX_SHADER_BASE_H

#include <ExtraX/Common.h>
#include <ExtraX/ResourceManager.h>
#include <ExtraX/Graphics/Context/ContextBase.h>

namespace ExtraX::Graphics
{
	class Shader
	{
	public:
		virtual void Bind(uint32_t = 0) = 0;
		virtual void Unbind(uint32_t = 0) = 0;

		template<GRAPHICS_LIB,typename ...ARGS>
		static Shader* Create(Context* context, ARGS ...args);
	};
}

namespace ExtraX::Graphics::Base
{


	template<GRAPHICS_LIB> 
	class ShaderResourceManager;

	template<GRAPHICS_LIB>
	class Shader;
}
#endif // !EXTRAX_SHADER_BASE_H
