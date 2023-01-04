#pragma once
#ifndef EXTRAX_CONTEXT_BASE_H
#define EXTRAX_CONTEXT_BASE_H

#include <ExtraX/Common.h>
#include <ExtraX/Singleton.h>

namespace ExtraX::Graphics::Base
{
	class ContextBase
	{
	public:
		virtual ~ContextBase() = default;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void ClearColor(float r,float g, float b, float a) = 0;
		virtual void Clear() = 0;
	};

	template<GRAPHICS_LIB,WINDOW_LIB>
	class Context;
}


#endif // !EXTRAX_CONTEXT_H
