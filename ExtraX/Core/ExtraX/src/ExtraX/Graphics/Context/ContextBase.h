#pragma once
#ifndef EXTRAX_CONTEXT_BASE_H
#define EXTRAX_CONTEXT_BASE_H

#include <ExtraX/StringLiteral.h>
#include <ExtraX/Graphics/Window/WindowBase.h>


namespace ExtraX::Graphics
{
	class Context
	{
	public:
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
		virtual void Clear() = 0;
		virtual void SwapBuffers() = 0;
		virtual ~Context() = default;
	};


}

namespace ExtraX::Graphics::Base
{
	template<StringLiteral, StringLiteral>
	class Context;
}


#endif // !EXTRAX_CONTEXT_H
