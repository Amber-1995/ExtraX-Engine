#pragma once
#ifndef EXTRAX_LOG_H
#define EXTRAX_LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <ExtraX/Singleton.h>
#undef CreateWindow

namespace ExtraX
{
	class Log
	{
	private:
		std::shared_ptr<spdlog::logger> _logger;
	public:
		Log(const char* name);
		
		std::shared_ptr<spdlog::logger>& Get();
	};

	class CoreLog : public Log
	{
	public:
		CoreLog() :
			Log("ExtraX")
		{
		}
	};

	class ClientLog : public Log
	{
	public:
		ClientLog():
			Log("APP")
		{
		}
	};
}

#ifndef EXTRAX_DISABLE_LOG
	// Core log macros
	#define XX_CORE_TRACE(...)    ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Get()->trace(__VA_ARGS__)
	#define XX_CORE_INFO(...)     ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Get()->info(__VA_ARGS__)
	#define XX_CORE_WARN(...)     ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Get()->warn(__VA_ARGS__)
	#define XX_CORE_ERROR(...)    ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Get()->error(__VA_ARGS__)
	#define XX_CORE_CRITICAL(...) ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Get()->critical(__VA_ARGS__)
	
	// Client log macros
	#define XX_TRACE(...)         ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Get()->trace(__VA_ARGS__)
	#define XX_INFO(...)          ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Get()->info(__VA_ARGS__)
	#define XX_WARN(...)          ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Get()->warn(__VA_ARGS__)
	#define XX_ERROR(...)         ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Get()->error(__VA_ARGS__)
	#define XX_CRITICAL(...)      ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Get()->critical(__VA_ARGS__)
#else
	// Core log macros
	#define XX_CORE_TRACE(...)   
	#define XX_CORE_INFO(...)    
	#define XX_CORE_WARN(...)    
	#define XX_CORE_ERROR(...)   
	#define XX_CORE_CRITICAL(...)
	
	// Client log macros
	#define XX_TRACE(...)        
	#define XX_INFO(...)         
	#define XX_WARN(...)         
	#define XX_ERROR(...)        
	#define XX_CRITICAL(...)     
#endif // DEBUG



#endif // !EXTRAX_LOG_H

