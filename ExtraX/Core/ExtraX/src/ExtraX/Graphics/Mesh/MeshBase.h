#pragma once
#ifndef EXTRAX_MESH_BASE_H
#define EXTRAX_MESH_BASE_H

#include <ExtraX/StringLiteral.h>
#include <ExtraX/Graphics/Context/ContextOpenGL.h>

namespace ExtraX::Graphics
{

	enum class ShaderDataType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Uint, Uint2, Uint3, Uint4,
		Bool,
	};

	uint32_t ShaderDataTypeSize(ShaderDataType type);

	struct VertexElement
	{
		std::string name;
		ShaderDataType type;
		uint32_t size;
		size_t offset;
		bool normalized;

		VertexElement(const char* name ,ShaderDataType type, bool normalized = false);

		uint32_t GetComponentCount() const;
	};

	class  VertexLayout
	{
	protected:
		std::vector<VertexElement> _elements;
		uint32_t _stride = 0;
	public:
		VertexLayout(std::initializer_list<VertexElement> elements);

		uint32_t GetStride() const;

		const std::vector<VertexElement>& GetElements() const;

		virtual void Bind(uint32_t = 0) = 0;
	};


	class StaticMesh
	{
	public:
		virtual void Draw() = 0;
	};

}

namespace ExtraX::Graphics::Base
{
	template<StringLiteral>
	class VertexLayout;

	template<StringLiteral, typename Vertex, typename Index>
	class StaticMesh;
}

#endif // !EXTRAX_MESH_BASE_H

