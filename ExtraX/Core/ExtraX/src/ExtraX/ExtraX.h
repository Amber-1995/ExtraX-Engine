#pragma once
#ifndef EXTRAX_H
#define EXTRAX_H


#include <ExtraX/Input.h>
#include <ExtraX/Graphics/Window/WindowBase.h>
#include <ExtraX/Graphics/Context/ContextBase.h>
#include <ExtraX/Graphics/Shader/ShaderBase.h>

namespace ExtraX::Graphics
{

	Window* XXCreateWindow(int width, int height, const char* title);

	Context* XXCreateContext(Window* window);

	template<typename ...ARGS>
	Shader* XXCreateShader(Context* context, ARGS ...args);



}

namespace ExtraX
{
	template<GRAPHICS_LIB,WINDOW_LIB>
	void Init();

	
}


#endif // !EXTRAX_H
