#include <XXPch.h>
#include <ExtraX/Assert.h>
#include "MeshBase.h"


namespace ExtraX::Graphics
{
	uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return 4;
		case ShaderDataType::Float2:   return 4 * 2;
		case ShaderDataType::Float3:   return 4 * 3;
		case ShaderDataType::Float4:   return 4 * 4;
		case ShaderDataType::Mat3:     return 4 * 3 * 3;
		case ShaderDataType::Mat4:     return 4 * 4 * 4;
		case ShaderDataType::Int:      return 4;
		case ShaderDataType::Int2:     return 4 * 2;
		case ShaderDataType::Int3:     return 4 * 3;
		case ShaderDataType::Int4:     return 4 * 4;
		case ShaderDataType::Uint:     return 4;
		case ShaderDataType::Uint2:    return 4 * 2;
		case ShaderDataType::Uint3:    return 4 * 3;
		case ShaderDataType::Uint4:    return 4 * 4;
		case ShaderDataType::Bool:     return 1;
		}

		XX_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}


	VertexElement::VertexElement(const char* name,ShaderDataType type, bool normalized)
		: name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized)
	{
	}

	uint32_t VertexElement::GetComponentCount() const
	{
		switch (type)
		{
		case ShaderDataType::Float:   return 1;
		case ShaderDataType::Float2:  return 2;
		case ShaderDataType::Float3:  return 3;
		case ShaderDataType::Float4:  return 4;
		case ShaderDataType::Mat3:    return 3; // 3* float3
		case ShaderDataType::Mat4:    return 4; // 4* float4
		case ShaderDataType::Int:     return 1;
		case ShaderDataType::Int2:    return 2;
		case ShaderDataType::Int3:    return 3;
		case ShaderDataType::Int4:    return 4;
		case ShaderDataType::Uint:    return 1;
		case ShaderDataType::Uint2:   return 2;
		case ShaderDataType::Uint3:   return 3;
		case ShaderDataType::Uint4:   return 4;
		case ShaderDataType::Bool:    return 1;
		}

		XX_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	VertexLayout::VertexLayout(std::initializer_list<VertexElement> elements)
		: _elements(elements)
	{
		size_t offset = 0;
		_stride = 0;
		for (auto& element : _elements)
		{
			element.offset = offset;
			offset += element.size;
			_stride += element.size;
		}
	}

	uint32_t VertexLayout::GetStride() const 
	{
		return _stride; 
	}

	const std::vector<VertexElement>& VertexLayout::GetElements() const 
	{ 
		return _elements; 
	}
}
