#pragma once
#if !defined(EXTRAX_GLFW_WINDOW_H) && !defined(EXTRAX_DISABLE_GLFW)
#define EXTRAX_GLFW_WINDOW_H


#include <ExtraX/Graphics/Window/WindowBase.h>
#include <ExtraX/Events/EventManager.h>
#include <GLFW/glfw3.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Window<WINDOW_LIB::GLFW> : public WindowBase
	{
	private:
		GLFWwindow* _window;
	public:
		Window(int width = WINDOW_WIDTH,int height = WINDOW_HEIGHT,const char* title = DEFAULT_TITLE, GLFWmonitor * monitor = NULL, GLFWwindow* share = NULL)
		{
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
			
			_window = glfwCreateWindow(width, height, title, monitor, share);

			XX_CORE_ASSERT(_window, "Failed to create GLFW window");

			const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(_window, (mode->width - WINDOW_WIDTH) / 2, (mode->height - WINDOW_HEIGHT) / 2);

			auto key_callback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				auto convert_key_to_extrax = [](int key)
				{
					if (key == KeyCode::Space || (key >= KeyCode::Num0 && key <= KeyCode::Num9) || (key >= KeyCode::A && key <= KeyCode::Z ))
					{
						return key;
					}

					if (key >= GLFW_KEY_F1 && key <= GLFW_KEY_F25)
					{
						return key - GLFW_KEY_F1 + KeyCode::F1;
					}

					if (key >= GLFW_KEY_KP_0 && key <= GLFW_KEY_KP_9)
					{
						return key - GLFW_KEY_KP_0 + KeyCode::NumericKeypad0;
					}

					switch (key)
					{
					case GLFW_KEY_APOSTROPHE:
						return KeyCode::SingleQuote_DoubleQuote;
					case GLFW_KEY_COMMA:
						return KeyCode::Comma;
					case GLFW_KEY_MINUS:
						return KeyCode::Minus;
					case GLFW_KEY_PERIOD:
						return KeyCode::Period;
					case GLFW_KEY_SLASH:
						return KeyCode::Slash_QuestionMark;
					case GLFW_KEY_SEMICOLON:
						return KeyCode::Semicolon;
					case GLFW_KEY_EQUAL:
						return KeyCode::PlusSign;
					case GLFW_KEY_LEFT_BRACKET:
						return KeyCode::LeftBracket;
					case GLFW_KEY_BACKSLASH:
						return KeyCode::Backslash_VerticalBar;
					case GLFW_KEY_RIGHT_BRACKET:
						return KeyCode::RightBracket;
					case GLFW_KEY_GRAVE_ACCENT:
						return KeyCode::GraveAccent_Tilde;
					case GLFW_KEY_ESCAPE:
						return KeyCode::Esc;
					case GLFW_KEY_ENTER:
						return KeyCode::Enter;
					case GLFW_KEY_TAB:
						return KeyCode::Tab;
					case GLFW_KEY_BACKSPACE:
						return KeyCode::Backspace;
					case GLFW_KEY_INSERT:
						return KeyCode::Insert;
					case GLFW_KEY_DELETE:
						return KeyCode::Delete;
					case GLFW_KEY_RIGHT:
						return KeyCode::RightArrow;
					case GLFW_KEY_LEFT:
						return KeyCode::LeftArrow;
					case GLFW_KEY_DOWN:
						return KeyCode::DownArrow;
					case GLFW_KEY_UP:
						return KeyCode::UpArrow;
					case GLFW_KEY_PAGE_UP:
						return KeyCode::PageUp;
					case GLFW_KEY_PAGE_DOWN:
						return KeyCode::PageDown;
					case GLFW_KEY_HOME:
						return KeyCode::Home;
					case GLFW_KEY_END:
						return KeyCode::End;
					case GLFW_KEY_CAPS_LOCK:
						return KeyCode::CapsLock;
					case GLFW_KEY_SCROLL_LOCK:
						return KeyCode::ScrollLock;
					case GLFW_KEY_NUM_LOCK:
						return KeyCode::NumLock;
					case GLFW_KEY_PRINT_SCREEN:
						return KeyCode::PrintScreen;
					case GLFW_KEY_PAUSE:
						return KeyCode::Pause;
					case GLFW_KEY_KP_DECIMAL:
						return KeyCode::Decimal;
					case GLFW_KEY_KP_DIVIDE:
						return KeyCode::Divide;
					case GLFW_KEY_KP_MULTIPLY:
						return KeyCode::Multiply;
					case GLFW_KEY_KP_SUBTRACT:
						return KeyCode::Subract;
					case GLFW_KEY_KP_ADD:
						return KeyCode::Add;
					case GLFW_KEY_KP_ENTER:
						return KeyCode::Enter;
					case GLFW_KEY_KP_EQUAL:
						return KeyCode::PlusSign;
					case GLFW_KEY_LEFT_SHIFT:
						return KeyCode::LetfShift;
					case GLFW_KEY_LEFT_CONTROL:
						return KeyCode::LeftCtrl;
					case GLFW_KEY_LEFT_ALT:
						return KeyCode::LeftAlt;
					case GLFW_KEY_LEFT_SUPER:
						return KeyCode::LeftWindows;
					case GLFW_KEY_RIGHT_SHIFT:
						return KeyCode::RightShift;
					case GLFW_KEY_RIGHT_CONTROL:
						return KeyCode::RightCtrl; 
					case GLFW_KEY_RIGHT_ALT:
						return KeyCode::RightAlt;
					case GLFW_KEY_RIGHT_SUPER:
						return KeyCode::RightWindows;
					}

					return 0;
				};

				switch (action)
				{
				case GLFW_PRESS:
					{
					Event<EVENT_TYPE::KeyDown> event_keydown(convert_key_to_extrax(key));
					EventManager::OnEvent(event_keydown);
					}
					break;
				case GLFW_RELEASE:
					{
					Event<EVENT_TYPE::KeyUp> event_keyup(convert_key_to_extrax(key));
					EventManager::OnEvent(event_keyup);
					}
					break;
				}
			};
			glfwSetKeyCallback(_window, key_callback);

			auto muose_button_callback = [](GLFWwindow* window, int button, int action, int mods)
			{

				auto convert_button_to_extrax = [](int button)
				{
					switch (button)
					{
					case GLFW_MOUSE_BUTTON_1:
						return KeyCode::LeftMouseButton;
					case GLFW_MOUSE_BUTTON_2:
						return KeyCode::RightMouseButton;
					case GLFW_MOUSE_BUTTON_3:
						return KeyCode::MiddleMouseButton;
					case GLFW_MOUSE_BUTTON_4:
						return KeyCode::X1MouseButton;
					case GLFW_MOUSE_BUTTON_5:
						return KeyCode::X2MouseButton;
					}
					return 0;
				};
				switch (action)
				{
				case GLFW_PRESS:
				{
					Event<EVENT_TYPE::KeyDown> event_keydown(convert_button_to_extrax(button));
					EventManager::OnEvent(event_keydown);
				}
				break;
				case GLFW_RELEASE:
				{
					Event<EVENT_TYPE::KeyUp> event_keyup(convert_button_to_extrax(button));
					EventManager::OnEvent(event_keyup);
				}
				break;
				}
			};
			glfwSetMouseButtonCallback(_window, muose_button_callback);

			auto cursor_position_callback = [](GLFWwindow* window, double xpos, double ypos)
			{
				Event<EVENT_TYPE::MouseMoved> event_mouse_moved((int)xpos, (int)ypos);
				EventManager::OnEvent(event_mouse_moved);
			};
			glfwSetCursorPosCallback(_window, cursor_position_callback);

			auto scroll_callback = [](GLFWwindow* window, double xoffset, double yoffset)
			{
				Event<EVENT_TYPE::MouseScrolled> event_mouse_scrolled(yoffset > 0 ? 1 : -1);
				EventManager::OnEvent(event_mouse_scrolled);
			};
			glfwSetScrollCallback(_window, scroll_callback);
		}

		virtual ~Window()
		{
			glfwDestroyWindow(_window);
			glfwTerminate();
		}

		GLFWwindow* GetWindow()
		{
			return _window;
		}

		bool ShouldClose() override
		{
			return glfwWindowShouldClose(_window);

		}

		void FrameBegin() override
		{
			glfwPollEvents();
			Event<EVENT_TYPE::FrameBegin> event_frame_begin;
			EventManager::OnEvent(event_frame_begin);
		}

		void FrameEnd() override
		{
			Event<EVENT_TYPE::FrameEnd> event_frame_end;
			EventManager::OnEvent(event_frame_end);
		}

		int GetWidth()
		{
			int w, h;
			glfwGetWindowSize(_window, &w, &h);
			return w;
		}

		int GetHeight()
		{
			int w, h;
			glfwGetWindowSize(_window, &w, &h);
			return h;
		}

		int GetPositionX()
		{
			int x, y;
			glfwGetWindowPos(_window, &x, &y);
			return x;
		}

		int GetPositionY()
		{
			int x, y;
			glfwGetWindowPos(_window, &x, &y);
			return y;
		}
		
		void SetTitle(const char* title)
		{
			glfwSetWindowTitle(_window, title);
		}

		void SetSize(int width, int height)
		{
			glfwSetWindowSize(_window, width, height);
			const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwSetWindowPos(_window, (mode->width - width) / 2, (mode->height - height) / 2);
		}

		void SetPosition(int x, int y)
		{
			glfwSetWindowPos(_window, x, y);
		}

	};
}




#endif // !EXTRAX_GLFW_WINDOW_H
