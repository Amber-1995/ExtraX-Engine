#include "XXPch.h"
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include "MeshOpenGL.h"



namespace ExtraX::Graphics::Base
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return GL_FLOAT;
		case ShaderDataType::Float2:   return GL_FLOAT;
		case ShaderDataType::Float3:   return GL_FLOAT;
		case ShaderDataType::Float4:   return GL_FLOAT;
		case ShaderDataType::Mat3:     return GL_FLOAT;
		case ShaderDataType::Mat4:     return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Int2:     return GL_INT;
		case ShaderDataType::Int3:     return GL_INT;
		case ShaderDataType::Int4:     return GL_INT;
		case ShaderDataType::Uint:     return GL_UNSIGNED_INT;
		case ShaderDataType::Uint2:    return GL_UNSIGNED_INT;
		case ShaderDataType::Uint3:    return GL_UNSIGNED_INT;
		case ShaderDataType::Uint4:    return GL_UNSIGNED_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}

		XX_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	VertexLayout<"OpenGL">::VertexLayout(std::initializer_list<VertexElement> elements):
		Graphics::VertexLayout(elements)
	{

	}

	void VertexLayout<"OpenGL">::Bind(uint32_t)
	{
		uint32_t index = 0;
		for ( auto& element : _elements)
		{
			glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.type), element.normalized, _stride, (const void*)element.offset);
			glEnableVertexAttribArray(index);
		}
	}

	Graphics::VertexLayout* VertexLayout<"OpenGL">::Create(Graphics::Context*, std::initializer_list<VertexElement> elements)
	{
		return new VertexLayout<"OpenGL">(elements);
	}

}