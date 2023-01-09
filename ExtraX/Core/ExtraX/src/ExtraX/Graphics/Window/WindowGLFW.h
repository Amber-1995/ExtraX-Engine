#pragma once
#ifndef EXTRAX_GLFW_WINDOW_H
#define EXTRAX_GLFW_WINDOW_H

#include <ExtraX/Graphics/Window/WindowBase.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Window<"GLFW"> : public Graphics::Window
	{
	private:
		GLFWwindow* _window;
	public:
		Window(int width, int height, const char* title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);

		virtual ~Window();

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

		static Graphics::Window* Create(int width, int height, const char* title);

	};
}




#endif // !EXTRAX_GLFW_WINDOW_H
