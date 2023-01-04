#pragma once
#ifndef EXTRAX_GLM_MATHEMATICS_BASE_H
#define EXTRAX_GLM_MATHEMATICS_BASE_H


#include <ExtraX/Mathematics/Color/ColorBase.h>
#include <ExtraX/Mathematics/Matrix/MatrixGLM.h>
#include <ExtraX/Mathematics/Quaternion/QuternionGLM.h>
#include <ExtraX/Mathematics/Vector/VectorGLM.h>


namespace ExtraX::Mathematics::Base
{
	template<typename SCALAR>
	class Math<MATHEMATICS_LIB::GLM, SCALAR>
	{
		template<int M, int N> using Matrix = Base::Matrix<MATHEMATICS_LIB::GLM, SCALAR, M, N>;
		using Quaternion = Base::Quaternion<MATHEMATICS_LIB::GLM, SCALAR>;
		template<int Size> using Vector = Base::Vector<MATHEMATICS_LIB::GLM, SCALAR, Size>;

	public:
		Math() = delete;
	};


}





#endif // !EXTRAX_GLM_MATHEMATICS_BASE_H
