#include <XXPch.h>
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include "ShaderOpenGL.h"


namespace ExtraX::Graphics
{
	template<>
	Shader* Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*>
	(
		Context* context,
		const char* vertex_shader_path,
		const char* fragment_shader_path
	)
	{
		return new Base::Shader<GRAPHICS_LIB::OpenGL>(vertex_shader_path, fragment_shader_path,nullptr,nullptr,nullptr);
	}
	template<>
	Shader* Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*>
	(
		Context* context,
		const char* vertex_shader_path,
		const char* fragment_shader_path,
		const char* tess_control_shader_path
	)
	{
		return new Base::Shader<GRAPHICS_LIB::OpenGL>(vertex_shader_path, fragment_shader_path, tess_control_shader_path, nullptr, nullptr);
	}

	template<>
	Shader* Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*>
	(
		Context* context,
		const char* vertex_shader_path,
		const char* fragment_shader_path,
		const char* tess_control_shader_path,
		const char* tess_evaluation_shader_path
	)
	{
		return new Base::Shader<GRAPHICS_LIB::OpenGL>(vertex_shader_path, fragment_shader_path, tess_control_shader_path, tess_evaluation_shader_path, nullptr);
	}

	template<>
	Shader* Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*, const char*>
	(
		Context* context, 
		const char* vertex_shader_path, 
		const char* fragment_shader_path, 
		const char* tess_control_shader_path, 
		const char* tess_evaluation_shader_path, 
		const char* geometry_shader_path
	)
	{
		return new Base::Shader<GRAPHICS_LIB::OpenGL>(vertex_shader_path, fragment_shader_path, tess_control_shader_path, tess_evaluation_shader_path, geometry_shader_path);
	}
}

namespace ExtraX::Graphics::Base
{
	void ShaderResourceManager<GRAPHICS_LIB::OpenGL>::Release(unsigned int resource)
	{
		glDeleteShader(resource);
	}

	Shader<GRAPHICS_LIB::OpenGL>::Shader
	(
		const char* vertex_shader_path,
		const char* fragment_shader_path,
		const char* tess_control_shader_path,
		const char* tess_evaluation_shader_path,
		const char* geometry_shader_path
	)
	{
		_shader_program = glCreateProgram();

		auto load_shader = [](const char* shader_path, GLenum shader_type, unsigned int& shader_program)
		{
			if (shader_path)
			{
				auto shader_resource_manager = GetSingleton<ShaderResourceManager<GRAPHICS_LIB::OpenGL>>();
				unsigned int shader;

				std::string absolute_path = std::filesystem::absolute(std::filesystem::path(shader_path)).string().c_str();
				const char* absolute_path_str = absolute_path.c_str();

				if (shader_resource_manager->IsExist(absolute_path_str))
				{
					shader = shader_resource_manager->Get(absolute_path_str);
					glAttachShader(shader_program, shader);
					return;
				}

				std::string shader_code;
				std::ifstream shader_file;
				std::stringstream shader_stream;
				shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

				try
				{
					shader_file.open(shader_path);
					shader_stream << shader_file.rdbuf();
					shader_file.close();
					shader_code = shader_stream.str();
				}
				catch (std::ifstream::failure e)
				{
					XX_CORE_ERROR("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
				}

				shader = glCreateShader(shader_type);
				const char* shader_code_str = shader_code.c_str();
				glShaderSource(shader, 1, &shader_code_str, NULL);
				glCompileShader(shader);
				glAttachShader(shader_program, shader);
				shader_resource_manager->Add(absolute_path_str, shader);
			}
		};

		load_shader(vertex_shader_path, GL_VERTEX_SHADER, _shader_program);
		load_shader(tess_control_shader_path, GL_TESS_CONTROL_SHADER, _shader_program);
		load_shader(tess_control_shader_path, GL_TESS_EVALUATION_SHADER, _shader_program);
		load_shader(geometry_shader_path, GL_GEOMETRY_SHADER, _shader_program);
		load_shader(fragment_shader_path, GL_FRAGMENT_SHADER, _shader_program);

		glLinkProgram(_shader_program);
	}

	void Shader<GRAPHICS_LIB::OpenGL>::Bind(uint32_t)
	{
		glUseProgram(_shader_program);
	}

	void Shader<GRAPHICS_LIB::OpenGL>::Unbind(uint32_t)
	{
		glUseProgram(0);
	}
}