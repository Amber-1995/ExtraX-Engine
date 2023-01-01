#include <ExtraX/Events/EventManager.h>
#include <ExtraX/Log.h>
#include <ExtraX/Graphics.h>
#include <ExtraX/Input.h>
#include <ExtraX/Init.h>

using namespace ExtraX;

using namespace ExtraX::Graphics;



int main()
{
	Init();
	
	Window* window = GetSingleton<Window>();
	Context* context = GetSingleton<Context>();


	while (!window->ShouldClose())
	{
		window->FrameBegin();
		context->ClearColor(0.2f, 0.3f, 0.4f, 1.0f);
		context->Clear(GL_COLOR_BUFFER_BIT);
		

		context->SwapBuffers();
		window->FrameEnd();
	}

	
}