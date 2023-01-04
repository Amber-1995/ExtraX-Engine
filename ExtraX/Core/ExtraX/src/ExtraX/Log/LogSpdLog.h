#pragma once
#ifndef EXTRAX_LOG_SPDLOG_H
#define EXTRAX_LOG_SPDLOG_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#include <ExtraX/Log/LogBase.h>


namespace ExtraX
{
	template<>
	class Log<LOG_LIB::SpdLog> : LogBase< Log<LOG_LIB::SpdLog>>
	{
	private:
		std::shared_ptr<spdlog::logger> _logger;
	public:
		Log<LOG_LIB::SpdLog>(const char* name)
		{
			spdlog::set_pattern("%^[%T]%n: %v%$");

			_logger = spdlog::stdout_color_mt(name);
			_logger->set_level(spdlog::level::trace);
		}

		template<typename ...ARGS>
		void Trace(const char* format, ARGS ...args)
		{
			_logger->trace(format, args...);
		}

		template<typename ...ARGS>
		void Info(const char* format, ARGS ...args)
		{
			_logger->info(format, args...);
		}

		template<typename ...ARGS>
		void Warn(const char* format, ARGS ...args)
		{
			_logger->warn(format, args...);
		}

		template<typename ...ARGS>
		void Error(const char* format, ARGS ...args)
		{
			_logger->error(format, args...);
		}

		template<typename ...ARGS>
		void Critical(const char* format, ARGS ...args)
		{
			_logger->critical(format, args...);
		}

	};
}

#endif // !EXTRAX_LOG_SPDLOG_H
