#include <XXPch.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Log.h"

namespace ExtraX
{
	Log::Log(const char* name)
	{
		spdlog::set_pattern("%^[%T]%n: %v%$");

		_logger = spdlog::stdout_color_mt(name);
		_logger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::Get()
	{
		return _logger;
	}
}