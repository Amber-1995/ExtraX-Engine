#pragma once
#ifndef EXTRAX_OPENGL_SHADER_H
#define EXTRAX_OPENGL_SHADER_H

#include <ExtraX/Graphics/Shader/ShaderBase.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class ShaderResourceManager<"OpenGL"> : public ResourceManager<unsigned int>
	{
	protected:
		void Release(unsigned int resource) override;
	};

	template<>
	class Shader<"OpenGL"> : public Graphics::Shader
	{
	private:
		unsigned int _shader_program;
	public:
		Shader(const char* vertex_shader_path, const char* fragment_shader_path, const char* tess_control_shader_path, const char* tess_evaluation_shader_path, const char* geometry_shader_path);

		void Bind(uint32_t = 0) override;

		void Unbind(uint32_t = 0) override;

		static Graphics::Shader* Create(Graphics::Context*, const char* vertex_shader_path, const char* fragment_shader_path, const char* tess_control_shader_path = nullptr, const char* tess_evaluation_shader_path = nullptr, const char* geometry_shader_path = nullptr);
	};
}

#endif // !EXTRAX_OPENGL_SHADER_H
