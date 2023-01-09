#pragma once
#ifndef EXTRAX_INIT_OPENGL_GLFW_H
#define EXTRAX_INIT_OPENGL_GLFW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ExtraX/Graphics/Graphics.h>
#include <ExtraX/Graphics/Window/WindowGLFW.h>
#include <ExtraX/Graphics/Context/ContextOpenGLGLFW.h>
#include <ExtraX/Graphics/Shader/ShaderOpenGL.h>
#include <ExtraX/Graphics/Mesh/MeshOpenGL.h>

namespace ExtraX::Graphics
{
	template<>
	void InitGraphics<"OpenGL", "GLFW">()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		_CreateWindow = Base::Window<"GLFW">::Create;
		_CreateContext = Base::Context<"OpenGL", "GLFW">::Create;
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


#endif // !EXTRAX_INIT_OPENGL_GLFW_H

