#include "ExtraX.h"


using namespace ExtraX;
using namespace ExtraX::Graphics;



int main()
{
	Initializer::Init();

	Window* window = GetSingleton<Window>();
	Context* context = GetSingleton<Context>();
	
	while (!window->ShouldClose())
	{
		window->FrameBegin();
		context->Clear();
		context->ClearColor(0.1f, 0.2f, 0.3f, 1.0f);

		if (Input::GetKeyDown(KeyCode::A))
		{
			XX_INFO("23333");
		}


		context->SwapBuffers();
		window->FrameEnd();
	}
}