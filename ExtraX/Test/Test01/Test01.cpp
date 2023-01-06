#include "ExtraX/ExtraX.h"
#include "ExtraX/Log.h"


using namespace ExtraX;
using namespace ExtraX::Graphics;



int main()
{
	Init<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>();

	Window* window = XXCreateWindow(800,600,"ExtraX");
	Context* context =XXCreateContext(window);
	
	while (!window->ShouldClose())
	{
		window->FrameBegin();
		context->Clear();
		context->ClearColor(0.1f, 0.2f, 0.3f, 1.0f);

		if (Input::GetKeyDown(KeyCode::A))
		{
			XX_INFO("2333");
		}


		context->SwapBuffers();
		window->FrameEnd();
	}
}