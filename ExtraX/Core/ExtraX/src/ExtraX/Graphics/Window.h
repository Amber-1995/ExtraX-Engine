#pragma once
#pragma once
#ifndef EXTRAX_WINDOW_H
#define EXTRAX_WINDOW_H

#include <ExtraX/Graphics/Window/GLFWWindow.h>
#include <ExtraX/Graphics/Window/Win32Window.h>


namespace ExtraX::Graphics
{
	using Window = Base::Window<DEFAULT_WINDOW_LIB>;
}

#endif // !EXTRAX_WINDOW_H

