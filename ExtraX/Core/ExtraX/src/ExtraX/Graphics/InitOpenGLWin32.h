#pragma once
#ifndef EXTRAX_INIT_OPENGL_WIN32_H
#define EXTRAX_INIT_OPENGL_WIN32_H

#include <glad/glad.h>
#include <Windows.h>
#include <Windowsx.h>
#undef CreateWindow
#include <ExtraX/Graphics/Graphics.h>
#include <ExtraX/Graphics/Window/WindowWin32.h>
#include <ExtraX/Graphics/Context/ContextOpenGLWin32.h>
#include <ExtraX/Graphics/Shader/ShaderOpenGL.h>
#include <ExtraX/Graphics/Mesh/MeshOpenGL.h>

namespace ExtraX::Graphics
{
	template<>
	void InitGraphics<"OpenGL", "Win32">()
	{
		_CreateWindow = Base::Window<"Win32">::Create;
		_CreateContext = Base::Context<"OpenGL", "Win32">::Create;
		_CreateShader = Base::Shader<"OpenGL">::Create;
		_CreateVertexLayout = Base::VertexLayout<"OpenGL">::Create;
		_CreateStaticMesh<float, uint32_t> = Base::StaticMesh<"OpenGL", float, uint32_t>::Create;
	}

	template<typename Vertex, typename Index>
	void AddVertexAndIndexType()
	{
		_CreateStaticMesh<Vertex, Index> = Base::StaticMesh<"OpenGL", Vertex, Index>::Create;
	}
}


#endif // !EXTRAX_INIT_OPENGL_WIN32_H
