#pragma once
#ifndef EXTRAX_CONTEXT_OPENGL_H
#define EXTRAX_CONTEXT_OPENGL_H

#include <ExtraX/Graphics/Context/ContextBase.h>



namespace ExtraX::Graphics::Base
{

	class ContextOpenGL : public ContextBase
	{
	public:
		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		void ClearColor(float r, float g, float b, float a);

		void Clear();

		virtual void SwapBuffers() = 0;

		virtual ~ContextOpenGL() = default;

	};
}

#endif // !EXTRAX_CONTEXT_OPENGL_H
