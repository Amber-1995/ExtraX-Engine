#pragma once
#ifndef EXTRAX_GLFW_WINDOW_H
#define EXTRAX_GLFW_WINDOW_H

#include <GLFW/glfw3.h>

#include <ExtraX/Graphics/Window/WindowBase.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Window<WINDOW_LIB::GLFW> : public WindowBase
	{
	private:
		GLFWwindow* _window;
	public:
		Window<WINDOW_LIB::GLFW>(int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT, const char* title = DEFAULT_TITLE, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);

		virtual ~Window<WINDOW_LIB::GLFW>();

		GLFWwindow* GetHandle();

		bool ShouldClose() override;

		void FrameBegin() override;

		void FrameEnd() override;

		int GetWidth() override;

		int GetHeight() override;

		int GetPositionX() override;

		int GetPositionY() override;
		
		void SetTitle(const char* title) override;

		void SetSize(int width, int height) override;

		void SetPosition(int x, int y) override;

	};
}




#endif // !EXTRAX_GLFW_WINDOW_H
