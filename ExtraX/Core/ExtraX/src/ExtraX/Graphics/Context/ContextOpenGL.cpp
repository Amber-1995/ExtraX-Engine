#include <XXPch.h>
#include <glad/glad.h>
#include "ContextOpenGL.h"


namespace ExtraX::Graphics::Base
{
	void ContextOpenGL::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void ContextOpenGL::ClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void ContextOpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}