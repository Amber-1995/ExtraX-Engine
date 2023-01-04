#pragma once
#ifndef EXTRAX_OPENGL_SHADER_H
#define EXTRAX_OPENGL_SHADER_H

#include <ExtraX/Graphics/Shader/ShaderBase.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class ShaderResourceManager<GRAPHICS_LIB::OpenGL> : public ResourceManager<unsigned int>
	{
	protected:
		void Release(unsigned int resource) override;
	};

	template<>
	class Shader<GRAPHICS_LIB::OpenGL> : public ShaderBase
	{
	private:
		unsigned int _shader_program;
	public:
		Shader<GRAPHICS_LIB::OpenGL>(const char* vertex_shader_path, const char* fragment_shader_path, const char* tess_control_shader_path = nullptr, const char* tess_evaluation_shader_path = nullptr, const char* geometry_shader_path = nullptr);

		void Bind() override;
	};
}

#endif // !EXTRAX_OPENGL_SHADER_H
