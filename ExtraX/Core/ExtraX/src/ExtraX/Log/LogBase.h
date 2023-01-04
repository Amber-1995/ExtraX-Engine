#pragma once
#ifndef EXTRAX_LOG_BASE_H
#define EXTRAX_LOG_BASE_H

#include <ExtraX/Common.h>

namespace ExtraX
{
	template<typename CHILD>
	class LogBase
	{
	public:
		template<typename ...ARGS>
		void Trace(const char* format, ARGS ...args)
		{
			static_cast<CHILD*>(this)->Trace(format, args...);
		}

		template<typename ...ARGS>
		void Info(const char* format, ARGS ...args)
		{
			static_cast<CHILD*>(this)->Info(format, args...);
		}

		template<typename ...ARGS>
		void Warn(const char* format, ARGS ...args)
		{
			static_cast<CHILD*>(this)->Warn(format, args...);
		}

		template<typename ...ARGS>
		void Error(const char* format, ARGS ...args)
		{
			static_cast<CHILD*>(this)->Error(format, args...);
		}

		template<typename ...ARGS>
		void Critical(const char* format, ARGS ...args)
		{
			static_cast<CHILD*>(this)->Critical(format, args...);
		}

	};

	template<LOG_LIB>
	class Log;
}

#endif // !EXTRAX_LOG_BASE_H
