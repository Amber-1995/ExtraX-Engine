#pragma once
#ifndef EXTRAX_LOG_H
#define EXTRAX_LOG_H

#include <ExtraX/Log/LogSpdLog.h>
#include <ExtraX/Singleton.h>

namespace ExtraX
{
	class CoreLog : public Log<LOG_LIB::SpdLog>
	{
	public:
		CoreLog() :
			Log<LOG_LIB::SpdLog>("ExtraX")
		{

		}
	};

	class ClientLog : public Log<LOG_LIB::SpdLog>
	{
	public:
		ClientLog() :
			Log<LOG_LIB::SpdLog>("APP")
		{

		}
	};
}

#ifndef EXTRAX_DISABLE_LOG
	// Core log macros
	#define XX_CORE_TRACE(...)    ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Trace(__VA_ARGS__)
	#define XX_CORE_INFO(...)     ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Info(__VA_ARGS__)
	#define XX_CORE_WARN(...)     ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Warn(__VA_ARGS__)
	#define XX_CORE_ERROR(...)    ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Error(__VA_ARGS__)
	#define XX_CORE_CRITICAL(...) ::ExtraX::GetSingleton<::ExtraX::CoreLog>()->Critical(__VA_ARGS__)
	
	// Client log macros
	#define XX_TRACE(...)         ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Trace(__VA_ARGS__)
	#define XX_INFO(...)          ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Info(__VA_ARGS__)
	#define XX_WARN(...)          ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Warn(__VA_ARGS__)
	#define XX_ERROR(...)         ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Error(__VA_ARGS__)
	#define XX_CRITICAL(...)      ::ExtraX::GetSingleton<::ExtraX::ClientLog>()->Critical(__VA_ARGS__)
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

