#pragma once
#ifndef EXTRAX_GRAPHICS_H
#define EXTRAX_GRAPHICS_H


#include <ExtraX/Input.h>
#include <ExtraX/Graphics/Window/WindowBase.h>
#include <ExtraX/Graphics/Context/ContextBase.h>
#include <ExtraX/Graphics/Shader/ShaderBase.h>
#include <ExtraX/Graphics/Mesh/MeshBase.h>

namespace ExtraX::Graphics
{
	inline Window* (*_CreateWindow)(int, int, const char*) = nullptr;

	inline Context* (*_CreateContext)(Window*) = nullptr;

	inline Shader* (*_CreateShader)(Context*, const char*, const char*, const char*, const char*, const char*) = nullptr;

	VertexLayout* (*_CreateVertexLayout)(Context*, std::initializer_list<VertexElement>) = nullptr;

	template<typename Vertex, typename Index>
	StaticMesh* (*_CreateStaticMesh)(Context*, VertexLayout*, Vertex*, uint32_t, Index*, uint32_t) = nullptr;


	Window* CreateWindow(int width, int height, const char* title)
	{
		return _CreateWindow(width, height, title);
	}

	Context* CreateContext(Window* window)
	{
		return _CreateContext(window);
	}

	Shader* CreateShader(Context* context, const char* str1, const char* str2, const char* str3 = nullptr, const char* str4 = nullptr, const char* str5 = nullptr)
	{
		return _CreateShader(context, str1, str2, str3, str4, str5);
	}

	VertexLayout* CreateVertexLayout(Context* context, std::initializer_list<VertexElement> elements)
	{
		return _CreateVertexLayout(context, elements);
	}

	template<typename Vertex, typename Index>
	StaticMesh* CreateStaticMesh(Context* context, VertexLayout* vertex_layout, Vertex* vertices, uint32_t vertices_size, Index* indices, uint32_t indices_size)
	{
		return _CreateStaticMesh<Vertex, Index>(context,vertex_layout, vertices, vertices_size, indices, indices_size);
	}

	template<StringLiteral,StringLiteral>
	void InitGraphics();

	template<typename Vertex, typename Index>
	void AddVertexAndIndexType();
}




#endif // !EXTRAX_GRAPHICS_H
