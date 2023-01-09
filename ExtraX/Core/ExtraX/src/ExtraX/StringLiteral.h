#pragma once
#ifndef EXTRAX_STRING_LITERAL_H
#define EXTRAX_STRING_LITERAL_H

namespace ExtraX
{
	template<int n>
	class StringLiteral
	{
	public:
		char str[n];
		constexpr StringLiteral(const char(&str)[n])
		{
			std::copy_n(str, n, this->str);
		}
	};
}

#endif // !EXTRAX_STRING_LITERAL_H
