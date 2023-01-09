#include <ExtraX/Input.h>
#include <ExtraX/Log.h>
#include <ExtraX/Graphics/InitOpenGLGLFW.h>


using namespace ExtraX;
using namespace ExtraX::Graphics;



int main()
{
	Input::Init();

	InitGraphics<"OpenGL", "GLFW">();
	
	Window* window = CreateWindow(800, 600, "ExtraX");

	Context* context = CreateContext(window);

	Shader* shader = CreateShader(context, "shader\\vertex.glsl", "shader\\fragment.glsl");

	VertexLayout* vertex_layout = CreateVertexLayout(context,{ {"233",ShaderDataType::Float3} });

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	uint32_t indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	StaticMesh* mesh = CreateStaticMesh(context,vertex_layout, vertices, 12, indices, 6);
	
	while (!window->ShouldClose())
	{
		window->FrameBegin();
		context->Clear();
		context->ClearColor(0.1f, 0.2f, 0.3f, 1.0f);

		if (Input::GetKeyDown(KeyCode::A))
		{
			XX_INFO("2333");
		}

		shader->Bind();
		mesh->Draw();


		context->SwapBuffers();
		window->FrameEnd();
	}
}