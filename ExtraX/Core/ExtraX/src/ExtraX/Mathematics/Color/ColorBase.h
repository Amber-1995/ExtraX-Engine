#pragma once
#ifndef EXTRAX_COLOR_BASE_H
#define EXTRAX_COLOR_BASE_H

#include <ExtraX/Common.h>
#include <ExtraX/Mathematics/Swizzle.h>
namespace ExtraX::Mathematics::Base
{
	template<MATHEMATICS_LIB>
	class Math;

	template<typename SCALAR, typename COLOR_TYPE = SCALAR[4]> requires(sizeof(COLOR_TYPE) == sizeof(SCALAR) * 4)
	class ColorBase
	{
	protected:
		union
		{
			COLOR_TYPE _color;
			struct
			{
				SCALAR r;
				SCALAR g;
				SCALAR b;
				SCALAR a;
			};
			Swizzle< SCALAR, 4, 0, 0 > rr;
			Swizzle< SCALAR, 4, 0, 1 > rg;
			Swizzle< SCALAR, 4, 0, 2 > rb;
			Swizzle< SCALAR, 4, 0, 3 > ra;
			Swizzle< SCALAR, 4, 1, 0 > gr;
			Swizzle< SCALAR, 4, 1, 1 > gg;
			Swizzle< SCALAR, 4, 1, 2 > gb;
			Swizzle< SCALAR, 4, 1, 3 > ga;
			Swizzle< SCALAR, 4, 2, 0 > br;
			Swizzle< SCALAR, 4, 2, 1 > bg;
			Swizzle< SCALAR, 4, 2, 2 > bb;
			Swizzle< SCALAR, 4, 2, 3 > ba;
			Swizzle< SCALAR, 4, 3, 0 > ar;
			Swizzle< SCALAR, 4, 3, 1 > ag;
			Swizzle< SCALAR, 4, 3, 2 > ab;
			Swizzle< SCALAR, 4, 3, 3 > aa;

			Swizzle< SCALAR, 4, 0, 0, 0 > rrr;
			Swizzle< SCALAR, 4, 0, 0, 1 > rrg;
			Swizzle< SCALAR, 4, 0, 0, 2 > rrb;
			Swizzle< SCALAR, 4, 0, 0, 3 > rra;
			Swizzle< SCALAR, 4, 0, 1, 0 > rgr;
			Swizzle< SCALAR, 4, 0, 1, 1 > rgg;
			Swizzle< SCALAR, 4, 0, 1, 2 > rgb;
			Swizzle< SCALAR, 4, 0, 1, 3 > rga;
			Swizzle< SCALAR, 4, 0, 2, 0 > rbr;
			Swizzle< SCALAR, 4, 0, 2, 1 > rbg;
			Swizzle< SCALAR, 4, 0, 2, 2 > rbb;
			Swizzle< SCALAR, 4, 0, 2, 3 > rba;
			Swizzle< SCALAR, 4, 0, 3, 0 > rar;
			Swizzle< SCALAR, 4, 0, 3, 1 > rag;
			Swizzle< SCALAR, 4, 0, 3, 2 > rab;
			Swizzle< SCALAR, 4, 0, 3, 3 > raa;
			Swizzle< SCALAR, 4, 1, 0, 0 > grr;
			Swizzle< SCALAR, 4, 1, 0, 1 > grg;
			Swizzle< SCALAR, 4, 1, 0, 2 > grb;
			Swizzle< SCALAR, 4, 1, 0, 3 > gra;
			Swizzle< SCALAR, 4, 1, 1, 0 > ggr;
			Swizzle< SCALAR, 4, 1, 1, 1 > ggg;
			Swizzle< SCALAR, 4, 1, 1, 2 > ggb;
			Swizzle< SCALAR, 4, 1, 1, 3 > gga;
			Swizzle< SCALAR, 4, 1, 2, 0 > gbr;
			Swizzle< SCALAR, 4, 1, 2, 1 > gbg;
			Swizzle< SCALAR, 4, 1, 2, 2 > gbb;
			Swizzle< SCALAR, 4, 1, 2, 3 > gba;
			Swizzle< SCALAR, 4, 1, 3, 0 > gar;
			Swizzle< SCALAR, 4, 1, 3, 1 > gag;
			Swizzle< SCALAR, 4, 1, 3, 2 > gab;
			Swizzle< SCALAR, 4, 1, 3, 3 > gaa;
			Swizzle< SCALAR, 4, 2, 0, 0 > brr;
			Swizzle< SCALAR, 4, 2, 0, 1 > brg;
			Swizzle< SCALAR, 4, 2, 0, 2 > brb;
			Swizzle< SCALAR, 4, 2, 0, 3 > bra;
			Swizzle< SCALAR, 4, 2, 1, 0 > bgr;
			Swizzle< SCALAR, 4, 2, 1, 1 > bgg;
			Swizzle< SCALAR, 4, 2, 1, 2 > bgb;
			Swizzle< SCALAR, 4, 2, 1, 3 > bga;
			Swizzle< SCALAR, 4, 2, 2, 0 > bbr;
			Swizzle< SCALAR, 4, 2, 2, 1 > bbg;
			Swizzle< SCALAR, 4, 2, 2, 2 > bbb;
			Swizzle< SCALAR, 4, 2, 2, 3 > bba;
			Swizzle< SCALAR, 4, 2, 3, 0 > bar;
			Swizzle< SCALAR, 4, 2, 3, 1 > bag;
			Swizzle< SCALAR, 4, 2, 3, 2 > bab;
			Swizzle< SCALAR, 4, 2, 3, 3 > baa;
			Swizzle< SCALAR, 4, 3, 0, 0 > arr;
			Swizzle< SCALAR, 4, 3, 0, 1 > arg;
			Swizzle< SCALAR, 4, 3, 0, 2 > arb;
			Swizzle< SCALAR, 4, 3, 0, 3 > ara;
			Swizzle< SCALAR, 4, 3, 1, 0 > agr;
			Swizzle< SCALAR, 4, 3, 1, 1 > agg;
			Swizzle< SCALAR, 4, 3, 1, 2 > agb;
			Swizzle< SCALAR, 4, 3, 1, 3 > aga;
			Swizzle< SCALAR, 4, 3, 2, 0 > abr;
			Swizzle< SCALAR, 4, 3, 2, 1 > abg;
			Swizzle< SCALAR, 4, 3, 2, 2 > abb;
			Swizzle< SCALAR, 4, 3, 2, 3 > aba;
			Swizzle< SCALAR, 4, 3, 3, 0 > aar;
			Swizzle< SCALAR, 4, 3, 3, 1 > aag;
			Swizzle< SCALAR, 4, 3, 3, 2 > aab;
			Swizzle< SCALAR, 4, 3, 3, 3 > aaa;

			Swizzle< SCALAR, 4, 0, 0, 0, 0 > rrrr;
			Swizzle< SCALAR, 4, 0, 0, 0, 1 > rrrg;
			Swizzle< SCALAR, 4, 0, 0, 0, 2 > rrrb;
			Swizzle< SCALAR, 4, 0, 0, 0, 3 > rrra;
			Swizzle< SCALAR, 4, 0, 0, 1, 0 > rrgr;
			Swizzle< SCALAR, 4, 0, 0, 1, 1 > rrgg;
			Swizzle< SCALAR, 4, 0, 0, 1, 2 > rrgb;
			Swizzle< SCALAR, 4, 0, 0, 1, 3 > rrga;
			Swizzle< SCALAR, 4, 0, 0, 2, 0 > rrbr;
			Swizzle< SCALAR, 4, 0, 0, 2, 1 > rrbg;
			Swizzle< SCALAR, 4, 0, 0, 2, 2 > rrbb;
			Swizzle< SCALAR, 4, 0, 0, 2, 3 > rrba;
			Swizzle< SCALAR, 4, 0, 0, 3, 0 > rrar;
			Swizzle< SCALAR, 4, 0, 0, 3, 1 > rrag;
			Swizzle< SCALAR, 4, 0, 0, 3, 2 > rrab;
			Swizzle< SCALAR, 4, 0, 0, 3, 3 > rraa;
			Swizzle< SCALAR, 4, 0, 1, 0, 0 > rgrr;
			Swizzle< SCALAR, 4, 0, 1, 0, 1 > rgrg;
			Swizzle< SCALAR, 4, 0, 1, 0, 2 > rgrb;
			Swizzle< SCALAR, 4, 0, 1, 0, 3 > rgra;
			Swizzle< SCALAR, 4, 0, 1, 1, 0 > rggr;
			Swizzle< SCALAR, 4, 0, 1, 1, 1 > rggg;
			Swizzle< SCALAR, 4, 0, 1, 1, 2 > rggb;
			Swizzle< SCALAR, 4, 0, 1, 1, 3 > rgga;
			Swizzle< SCALAR, 4, 0, 1, 2, 0 > rgbr;
			Swizzle< SCALAR, 4, 0, 1, 2, 1 > rgbg;
			Swizzle< SCALAR, 4, 0, 1, 2, 2 > rgbb;
			Swizzle< SCALAR, 4, 0, 1, 2, 3 > rgba;
			Swizzle< SCALAR, 4, 0, 1, 3, 0 > rgar;
			Swizzle< SCALAR, 4, 0, 1, 3, 1 > rgag;
			Swizzle< SCALAR, 4, 0, 1, 3, 2 > rgab;
			Swizzle< SCALAR, 4, 0, 1, 3, 3 > rgaa;
			Swizzle< SCALAR, 4, 0, 2, 0, 0 > rbrr;
			Swizzle< SCALAR, 4, 0, 2, 0, 1 > rbrg;
			Swizzle< SCALAR, 4, 0, 2, 0, 2 > rbrb;
			Swizzle< SCALAR, 4, 0, 2, 0, 3 > rbra;
			Swizzle< SCALAR, 4, 0, 2, 1, 0 > rbgr;
			Swizzle< SCALAR, 4, 0, 2, 1, 1 > rbgg;
			Swizzle< SCALAR, 4, 0, 2, 1, 2 > rbgb;
			Swizzle< SCALAR, 4, 0, 2, 1, 3 > rbga;
			Swizzle< SCALAR, 4, 0, 2, 2, 0 > rbbr;
			Swizzle< SCALAR, 4, 0, 2, 2, 1 > rbbg;
			Swizzle< SCALAR, 4, 0, 2, 2, 2 > rbbb;
			Swizzle< SCALAR, 4, 0, 2, 2, 3 > rbba;
			Swizzle< SCALAR, 4, 0, 2, 3, 0 > rbar;
			Swizzle< SCALAR, 4, 0, 2, 3, 1 > rbag;
			Swizzle< SCALAR, 4, 0, 2, 3, 2 > rbab;
			Swizzle< SCALAR, 4, 0, 2, 3, 3 > rbaa;
			Swizzle< SCALAR, 4, 0, 3, 0, 0 > rarr;
			Swizzle< SCALAR, 4, 0, 3, 0, 1 > rarg;
			Swizzle< SCALAR, 4, 0, 3, 0, 2 > rarb;
			Swizzle< SCALAR, 4, 0, 3, 0, 3 > rara;
			Swizzle< SCALAR, 4, 0, 3, 1, 0 > ragr;
			Swizzle< SCALAR, 4, 0, 3, 1, 1 > ragg;
			Swizzle< SCALAR, 4, 0, 3, 1, 2 > ragb;
			Swizzle< SCALAR, 4, 0, 3, 1, 3 > raga;
			Swizzle< SCALAR, 4, 0, 3, 2, 0 > rabr;
			Swizzle< SCALAR, 4, 0, 3, 2, 1 > rabg;
			Swizzle< SCALAR, 4, 0, 3, 2, 2 > rabb;
			Swizzle< SCALAR, 4, 0, 3, 2, 3 > raba;
			Swizzle< SCALAR, 4, 0, 3, 3, 0 > raar;
			Swizzle< SCALAR, 4, 0, 3, 3, 1 > raag;
			Swizzle< SCALAR, 4, 0, 3, 3, 2 > raab;
			Swizzle< SCALAR, 4, 0, 3, 3, 3 > raaa;
			Swizzle< SCALAR, 4, 1, 0, 0, 0 > grrr;
			Swizzle< SCALAR, 4, 1, 0, 0, 1 > grrg;
			Swizzle< SCALAR, 4, 1, 0, 0, 2 > grrb;
			Swizzle< SCALAR, 4, 1, 0, 0, 3 > grra;
			Swizzle< SCALAR, 4, 1, 0, 1, 0 > grgr;
			Swizzle< SCALAR, 4, 1, 0, 1, 1 > grgg;
			Swizzle< SCALAR, 4, 1, 0, 1, 2 > grgb;
			Swizzle< SCALAR, 4, 1, 0, 1, 3 > grga;
			Swizzle< SCALAR, 4, 1, 0, 2, 0 > grbr;
			Swizzle< SCALAR, 4, 1, 0, 2, 1 > grbg;
			Swizzle< SCALAR, 4, 1, 0, 2, 2 > grbb;
			Swizzle< SCALAR, 4, 1, 0, 2, 3 > grba;
			Swizzle< SCALAR, 4, 1, 0, 3, 0 > grar;
			Swizzle< SCALAR, 4, 1, 0, 3, 1 > grag;
			Swizzle< SCALAR, 4, 1, 0, 3, 2 > grab;
			Swizzle< SCALAR, 4, 1, 0, 3, 3 > graa;
			Swizzle< SCALAR, 4, 1, 1, 0, 0 > ggrr;
			Swizzle< SCALAR, 4, 1, 1, 0, 1 > ggrg;
			Swizzle< SCALAR, 4, 1, 1, 0, 2 > ggrb;
			Swizzle< SCALAR, 4, 1, 1, 0, 3 > ggra;
			Swizzle< SCALAR, 4, 1, 1, 1, 0 > gggr;
			Swizzle< SCALAR, 4, 1, 1, 1, 1 > gggg;
			Swizzle< SCALAR, 4, 1, 1, 1, 2 > gggb;
			Swizzle< SCALAR, 4, 1, 1, 1, 3 > ggga;
			Swizzle< SCALAR, 4, 1, 1, 2, 0 > ggbr;
			Swizzle< SCALAR, 4, 1, 1, 2, 1 > ggbg;
			Swizzle< SCALAR, 4, 1, 1, 2, 2 > ggbb;
			Swizzle< SCALAR, 4, 1, 1, 2, 3 > ggba;
			Swizzle< SCALAR, 4, 1, 1, 3, 0 > ggar;
			Swizzle< SCALAR, 4, 1, 1, 3, 1 > ggag;
			Swizzle< SCALAR, 4, 1, 1, 3, 2 > ggab;
			Swizzle< SCALAR, 4, 1, 1, 3, 3 > ggaa;
			Swizzle< SCALAR, 4, 1, 2, 0, 0 > gbrr;
			Swizzle< SCALAR, 4, 1, 2, 0, 1 > gbrg;
			Swizzle< SCALAR, 4, 1, 2, 0, 2 > gbrb;
			Swizzle< SCALAR, 4, 1, 2, 0, 3 > gbra;
			Swizzle< SCALAR, 4, 1, 2, 1, 0 > gbgr;
			Swizzle< SCALAR, 4, 1, 2, 1, 1 > gbgg;
			Swizzle< SCALAR, 4, 1, 2, 1, 2 > gbgb;
			Swizzle< SCALAR, 4, 1, 2, 1, 3 > gbga;
			Swizzle< SCALAR, 4, 1, 2, 2, 0 > gbbr;
			Swizzle< SCALAR, 4, 1, 2, 2, 1 > gbbg;
			Swizzle< SCALAR, 4, 1, 2, 2, 2 > gbbb;
			Swizzle< SCALAR, 4, 1, 2, 2, 3 > gbba;
			Swizzle< SCALAR, 4, 1, 2, 3, 0 > gbar;
			Swizzle< SCALAR, 4, 1, 2, 3, 1 > gbag;
			Swizzle< SCALAR, 4, 1, 2, 3, 2 > gbab;
			Swizzle< SCALAR, 4, 1, 2, 3, 3 > gbaa;
			Swizzle< SCALAR, 4, 1, 3, 0, 0 > garr;
			Swizzle< SCALAR, 4, 1, 3, 0, 1 > garg;
			Swizzle< SCALAR, 4, 1, 3, 0, 2 > garb;
			Swizzle< SCALAR, 4, 1, 3, 0, 3 > gara;
			Swizzle< SCALAR, 4, 1, 3, 1, 0 > gagr;
			Swizzle< SCALAR, 4, 1, 3, 1, 1 > gagg;
			Swizzle< SCALAR, 4, 1, 3, 1, 2 > gagb;
			Swizzle< SCALAR, 4, 1, 3, 1, 3 > gaga;
			Swizzle< SCALAR, 4, 1, 3, 2, 0 > gabr;
			Swizzle< SCALAR, 4, 1, 3, 2, 1 > gabg;
			Swizzle< SCALAR, 4, 1, 3, 2, 2 > gabb;
			Swizzle< SCALAR, 4, 1, 3, 2, 3 > gaba;
			Swizzle< SCALAR, 4, 1, 3, 3, 0 > gaar;
			Swizzle< SCALAR, 4, 1, 3, 3, 1 > gaag;
			Swizzle< SCALAR, 4, 1, 3, 3, 2 > gaab;
			Swizzle< SCALAR, 4, 1, 3, 3, 3 > gaaa;
			Swizzle< SCALAR, 4, 2, 0, 0, 0 > brrr;
			Swizzle< SCALAR, 4, 2, 0, 0, 1 > brrg;
			Swizzle< SCALAR, 4, 2, 0, 0, 2 > brrb;
			Swizzle< SCALAR, 4, 2, 0, 0, 3 > brra;
			Swizzle< SCALAR, 4, 2, 0, 1, 0 > brgr;
			Swizzle< SCALAR, 4, 2, 0, 1, 1 > brgg;
			Swizzle< SCALAR, 4, 2, 0, 1, 2 > brgb;
			Swizzle< SCALAR, 4, 2, 0, 1, 3 > brga;
			Swizzle< SCALAR, 4, 2, 0, 2, 0 > brbr;
			Swizzle< SCALAR, 4, 2, 0, 2, 1 > brbg;
			Swizzle< SCALAR, 4, 2, 0, 2, 2 > brbb;
			Swizzle< SCALAR, 4, 2, 0, 2, 3 > brba;
			Swizzle< SCALAR, 4, 2, 0, 3, 0 > brar;
			Swizzle< SCALAR, 4, 2, 0, 3, 1 > brag;
			Swizzle< SCALAR, 4, 2, 0, 3, 2 > brab;
			Swizzle< SCALAR, 4, 2, 0, 3, 3 > braa;
			Swizzle< SCALAR, 4, 2, 1, 0, 0 > bgrr;
			Swizzle< SCALAR, 4, 2, 1, 0, 1 > bgrg;
			Swizzle< SCALAR, 4, 2, 1, 0, 2 > bgrb;
			Swizzle< SCALAR, 4, 2, 1, 0, 3 > bgra;
			Swizzle< SCALAR, 4, 2, 1, 1, 0 > bggr;
			Swizzle< SCALAR, 4, 2, 1, 1, 1 > bggg;
			Swizzle< SCALAR, 4, 2, 1, 1, 2 > bggb;
			Swizzle< SCALAR, 4, 2, 1, 1, 3 > bgga;
			Swizzle< SCALAR, 4, 2, 1, 2, 0 > bgbr;
			Swizzle< SCALAR, 4, 2, 1, 2, 1 > bgbg;
			Swizzle< SCALAR, 4, 2, 1, 2, 2 > bgbb;
			Swizzle< SCALAR, 4, 2, 1, 2, 3 > bgba;
			Swizzle< SCALAR, 4, 2, 1, 3, 0 > bgar;
			Swizzle< SCALAR, 4, 2, 1, 3, 1 > bgag;
			Swizzle< SCALAR, 4, 2, 1, 3, 2 > bgab;
			Swizzle< SCALAR, 4, 2, 1, 3, 3 > bgaa;
			Swizzle< SCALAR, 4, 2, 2, 0, 0 > bbrr;
			Swizzle< SCALAR, 4, 2, 2, 0, 1 > bbrg;
			Swizzle< SCALAR, 4, 2, 2, 0, 2 > bbrb;
			Swizzle< SCALAR, 4, 2, 2, 0, 3 > bbra;
			Swizzle< SCALAR, 4, 2, 2, 1, 0 > bbgr;
			Swizzle< SCALAR, 4, 2, 2, 1, 1 > bbgg;
			Swizzle< SCALAR, 4, 2, 2, 1, 2 > bbgb;
			Swizzle< SCALAR, 4, 2, 2, 1, 3 > bbga;
			Swizzle< SCALAR, 4, 2, 2, 2, 0 > bbbr;
			Swizzle< SCALAR, 4, 2, 2, 2, 1 > bbbg;
			Swizzle< SCALAR, 4, 2, 2, 2, 2 > bbbb;
			Swizzle< SCALAR, 4, 2, 2, 2, 3 > bbba;
			Swizzle< SCALAR, 4, 2, 2, 3, 0 > bbar;
			Swizzle< SCALAR, 4, 2, 2, 3, 1 > bbag;
			Swizzle< SCALAR, 4, 2, 2, 3, 2 > bbab;
			Swizzle< SCALAR, 4, 2, 2, 3, 3 > bbaa;
			Swizzle< SCALAR, 4, 2, 3, 0, 0 > barr;
			Swizzle< SCALAR, 4, 2, 3, 0, 1 > barg;
			Swizzle< SCALAR, 4, 2, 3, 0, 2 > barb;
			Swizzle< SCALAR, 4, 2, 3, 0, 3 > bara;
			Swizzle< SCALAR, 4, 2, 3, 1, 0 > bagr;
			Swizzle< SCALAR, 4, 2, 3, 1, 1 > bagg;
			Swizzle< SCALAR, 4, 2, 3, 1, 2 > bagb;
			Swizzle< SCALAR, 4, 2, 3, 1, 3 > baga;
			Swizzle< SCALAR, 4, 2, 3, 2, 0 > babr;
			Swizzle< SCALAR, 4, 2, 3, 2, 1 > babg;
			Swizzle< SCALAR, 4, 2, 3, 2, 2 > babb;
			Swizzle< SCALAR, 4, 2, 3, 2, 3 > baba;
			Swizzle< SCALAR, 4, 2, 3, 3, 0 > baar;
			Swizzle< SCALAR, 4, 2, 3, 3, 1 > baag;
			Swizzle< SCALAR, 4, 2, 3, 3, 2 > baab;
			Swizzle< SCALAR, 4, 2, 3, 3, 3 > baaa;
			Swizzle< SCALAR, 4, 3, 0, 0, 0 > arrr;
			Swizzle< SCALAR, 4, 3, 0, 0, 1 > arrg;
			Swizzle< SCALAR, 4, 3, 0, 0, 2 > arrb;
			Swizzle< SCALAR, 4, 3, 0, 0, 3 > arra;
			Swizzle< SCALAR, 4, 3, 0, 1, 0 > argr;
			Swizzle< SCALAR, 4, 3, 0, 1, 1 > argg;
			Swizzle< SCALAR, 4, 3, 0, 1, 2 > argb;
			Swizzle< SCALAR, 4, 3, 0, 1, 3 > arga;
			Swizzle< SCALAR, 4, 3, 0, 2, 0 > arbr;
			Swizzle< SCALAR, 4, 3, 0, 2, 1 > arbg;
			Swizzle< SCALAR, 4, 3, 0, 2, 2 > arbb;
			Swizzle< SCALAR, 4, 3, 0, 2, 3 > arba;
			Swizzle< SCALAR, 4, 3, 0, 3, 0 > arar;
			Swizzle< SCALAR, 4, 3, 0, 3, 1 > arag;
			Swizzle< SCALAR, 4, 3, 0, 3, 2 > arab;
			Swizzle< SCALAR, 4, 3, 0, 3, 3 > araa;
			Swizzle< SCALAR, 4, 3, 1, 0, 0 > agrr;
			Swizzle< SCALAR, 4, 3, 1, 0, 1 > agrg;
			Swizzle< SCALAR, 4, 3, 1, 0, 2 > agrb;
			Swizzle< SCALAR, 4, 3, 1, 0, 3 > agra;
			Swizzle< SCALAR, 4, 3, 1, 1, 0 > aggr;
			Swizzle< SCALAR, 4, 3, 1, 1, 1 > aggg;
			Swizzle< SCALAR, 4, 3, 1, 1, 2 > aggb;
			Swizzle< SCALAR, 4, 3, 1, 1, 3 > agga;
			Swizzle< SCALAR, 4, 3, 1, 2, 0 > agbr;
			Swizzle< SCALAR, 4, 3, 1, 2, 1 > agbg;
			Swizzle< SCALAR, 4, 3, 1, 2, 2 > agbb;
			Swizzle< SCALAR, 4, 3, 1, 2, 3 > agba;
			Swizzle< SCALAR, 4, 3, 1, 3, 0 > agar;
			Swizzle< SCALAR, 4, 3, 1, 3, 1 > agag;
			Swizzle< SCALAR, 4, 3, 1, 3, 2 > agab;
			Swizzle< SCALAR, 4, 3, 1, 3, 3 > agaa;
			Swizzle< SCALAR, 4, 3, 2, 0, 0 > abrr;
			Swizzle< SCALAR, 4, 3, 2, 0, 1 > abrg;
			Swizzle< SCALAR, 4, 3, 2, 0, 2 > abrb;
			Swizzle< SCALAR, 4, 3, 2, 0, 3 > abra;
			Swizzle< SCALAR, 4, 3, 2, 1, 0 > abgr;
			Swizzle< SCALAR, 4, 3, 2, 1, 1 > abgg;
			Swizzle< SCALAR, 4, 3, 2, 1, 2 > abgb;
			Swizzle< SCALAR, 4, 3, 2, 1, 3 > abga;
			Swizzle< SCALAR, 4, 3, 2, 2, 0 > abbr;
			Swizzle< SCALAR, 4, 3, 2, 2, 1 > abbg;
			Swizzle< SCALAR, 4, 3, 2, 2, 2 > abbb;
			Swizzle< SCALAR, 4, 3, 2, 2, 3 > abba;
			Swizzle< SCALAR, 4, 3, 2, 3, 0 > abar;
			Swizzle< SCALAR, 4, 3, 2, 3, 1 > abag;
			Swizzle< SCALAR, 4, 3, 2, 3, 2 > abab;
			Swizzle< SCALAR, 4, 3, 2, 3, 3 > abaa;
			Swizzle< SCALAR, 4, 3, 3, 0, 0 > aarr;
			Swizzle< SCALAR, 4, 3, 3, 0, 1 > aarg;
			Swizzle< SCALAR, 4, 3, 3, 0, 2 > aarb;
			Swizzle< SCALAR, 4, 3, 3, 0, 3 > aara;
			Swizzle< SCALAR, 4, 3, 3, 1, 0 > aagr;
			Swizzle< SCALAR, 4, 3, 3, 1, 1 > aagg;
			Swizzle< SCALAR, 4, 3, 3, 1, 2 > aagb;
			Swizzle< SCALAR, 4, 3, 3, 1, 3 > aaga;
			Swizzle< SCALAR, 4, 3, 3, 2, 0 > aabr;
			Swizzle< SCALAR, 4, 3, 3, 2, 1 > aabg;
			Swizzle< SCALAR, 4, 3, 3, 2, 2 > aabb;
			Swizzle< SCALAR, 4, 3, 3, 2, 3 > aaba;
			Swizzle< SCALAR, 4, 3, 3, 3, 0 > aaar;
			Swizzle< SCALAR, 4, 3, 3, 3, 1 > aaag;
			Swizzle< SCALAR, 4, 3, 3, 3, 2 > aaab;
			Swizzle< SCALAR, 4, 3, 3, 3, 3 > aaaa;
		};

		ColorBase() :
			_color{0.0f,0.0f,0.0f,0.0f}
		{
		}

		ColorBase(SCALAR r, SCALAR g, SCALAR b,SCALAR a) :
			_color{r,g,b,a }
		{
		}
	};

	template<MATHEMATICS_LIB, typename SCALAR>
	class Color : public ColorBase<SCALAR>
	{
	private:
		using BaseType = ColorBase<SCALAR>;
	public:
		using BaseType::r;
		using BaseType::g;
		using BaseType::b;
		using BaseType::a;
		using BaseType::rr;
		using BaseType::rg;
		using BaseType::rb;
		using BaseType::ra;
		using BaseType::gr;
		using BaseType::gg;
		using BaseType::gb;
		using BaseType::ga;
		using BaseType::br;
		using BaseType::bg;
		using BaseType::bb;
		using BaseType::ba;
		using BaseType::ar;
		using BaseType::ag;
		using BaseType::ab;
		using BaseType::aa;

		using BaseType::rrr;
		using BaseType::rrg;
		using BaseType::rrb;
		using BaseType::rra;
		using BaseType::rgr;
		using BaseType::rgg;
		using BaseType::rgb;
		using BaseType::rga;
		using BaseType::rbr;
		using BaseType::rbg;
		using BaseType::rbb;
		using BaseType::rba;
		using BaseType::rar;
		using BaseType::rag;
		using BaseType::rab;
		using BaseType::raa;
		using BaseType::grr;
		using BaseType::grg;
		using BaseType::grb;
		using BaseType::gra;
		using BaseType::ggr;
		using BaseType::ggg;
		using BaseType::ggb;
		using BaseType::gga;
		using BaseType::gbr;
		using BaseType::gbg;
		using BaseType::gbb;
		using BaseType::gba;
		using BaseType::gar;
		using BaseType::gag;
		using BaseType::gab;
		using BaseType::gaa;
		using BaseType::brr;
		using BaseType::brg;
		using BaseType::brb;
		using BaseType::bra;
		using BaseType::bgr;
		using BaseType::bgg;
		using BaseType::bgb;
		using BaseType::bga;
		using BaseType::bbr;
		using BaseType::bbg;
		using BaseType::bbb;
		using BaseType::bba;
		using BaseType::bar;
		using BaseType::bag;
		using BaseType::bab;
		using BaseType::baa;
		using BaseType::arr;
		using BaseType::arg;
		using BaseType::arb;
		using BaseType::ara;
		using BaseType::agr;
		using BaseType::agg;
		using BaseType::agb;
		using BaseType::aga;
		using BaseType::abr;
		using BaseType::abg;
		using BaseType::abb;
		using BaseType::aba;
		using BaseType::aar;
		using BaseType::aag;
		using BaseType::aab;
		using BaseType::aaa;

		using BaseType::rrrr;
		using BaseType::rrrg;
		using BaseType::rrrb;
		using BaseType::rrra;
		using BaseType::rrgr;
		using BaseType::rrgg;
		using BaseType::rrgb;
		using BaseType::rrga;
		using BaseType::rrbr;
		using BaseType::rrbg;
		using BaseType::rrbb;
		using BaseType::rrba;
		using BaseType::rrar;
		using BaseType::rrag;
		using BaseType::rrab;
		using BaseType::rraa;
		using BaseType::rgrr;
		using BaseType::rgrg;
		using BaseType::rgrb;
		using BaseType::rgra;
		using BaseType::rggr;
		using BaseType::rggg;
		using BaseType::rggb;
		using BaseType::rgga;
		using BaseType::rgbr;
		using BaseType::rgbg;
		using BaseType::rgbb;
		using BaseType::rgba;
		using BaseType::rgar;
		using BaseType::rgag;
		using BaseType::rgab;
		using BaseType::rgaa;
		using BaseType::rbrr;
		using BaseType::rbrg;
		using BaseType::rbrb;
		using BaseType::rbra;
		using BaseType::rbgr;
		using BaseType::rbgg;
		using BaseType::rbgb;
		using BaseType::rbga;
		using BaseType::rbbr;
		using BaseType::rbbg;
		using BaseType::rbbb;
		using BaseType::rbba;
		using BaseType::rbar;
		using BaseType::rbag;
		using BaseType::rbab;
		using BaseType::rbaa;
		using BaseType::rarr;
		using BaseType::rarg;
		using BaseType::rarb;
		using BaseType::rara;
		using BaseType::ragr;
		using BaseType::ragg;
		using BaseType::ragb;
		using BaseType::raga;
		using BaseType::rabr;
		using BaseType::rabg;
		using BaseType::rabb;
		using BaseType::raba;
		using BaseType::raar;
		using BaseType::raag;
		using BaseType::raab;
		using BaseType::raaa;
		using BaseType::grrr;
		using BaseType::grrg;
		using BaseType::grrb;
		using BaseType::grra;
		using BaseType::grgr;
		using BaseType::grgg;
		using BaseType::grgb;
		using BaseType::grga;
		using BaseType::grbr;
		using BaseType::grbg;
		using BaseType::grbb;
		using BaseType::grba;
		using BaseType::grar;
		using BaseType::grag;
		using BaseType::grab;
		using BaseType::graa;
		using BaseType::ggrr;
		using BaseType::ggrg;
		using BaseType::ggrb;
		using BaseType::ggra;
		using BaseType::gggr;
		using BaseType::gggg;
		using BaseType::gggb;
		using BaseType::ggga;
		using BaseType::ggbr;
		using BaseType::ggbg;
		using BaseType::ggbb;
		using BaseType::ggba;
		using BaseType::ggar;
		using BaseType::ggag;
		using BaseType::ggab;
		using BaseType::ggaa;
		using BaseType::gbrr;
		using BaseType::gbrg;
		using BaseType::gbrb;
		using BaseType::gbra;
		using BaseType::gbgr;
		using BaseType::gbgg;
		using BaseType::gbgb;
		using BaseType::gbga;
		using BaseType::gbbr;
		using BaseType::gbbg;
		using BaseType::gbbb;
		using BaseType::gbba;
		using BaseType::gbar;
		using BaseType::gbag;
		using BaseType::gbab;
		using BaseType::gbaa;
		using BaseType::garr;
		using BaseType::garg;
		using BaseType::garb;
		using BaseType::gara;
		using BaseType::gagr;
		using BaseType::gagg;
		using BaseType::gagb;
		using BaseType::gaga;
		using BaseType::gabr;
		using BaseType::gabg;
		using BaseType::gabb;
		using BaseType::gaba;
		using BaseType::gaar;
		using BaseType::gaag;
		using BaseType::gaab;
		using BaseType::gaaa;
		using BaseType::brrr;
		using BaseType::brrg;
		using BaseType::brrb;
		using BaseType::brra;
		using BaseType::brgr;
		using BaseType::brgg;
		using BaseType::brgb;
		using BaseType::brga;
		using BaseType::brbr;
		using BaseType::brbg;
		using BaseType::brbb;
		using BaseType::brba;
		using BaseType::brar;
		using BaseType::brag;
		using BaseType::brab;
		using BaseType::braa;
		using BaseType::bgrr;
		using BaseType::bgrg;
		using BaseType::bgrb;
		using BaseType::bgra;
		using BaseType::bggr;
		using BaseType::bggg;
		using BaseType::bggb;
		using BaseType::bgga;
		using BaseType::bgbr;
		using BaseType::bgbg;
		using BaseType::bgbb;
		using BaseType::bgba;
		using BaseType::bgar;
		using BaseType::bgag;
		using BaseType::bgab;
		using BaseType::bgaa;
		using BaseType::bbrr;
		using BaseType::bbrg;
		using BaseType::bbrb;
		using BaseType::bbra;
		using BaseType::bbgr;
		using BaseType::bbgg;
		using BaseType::bbgb;
		using BaseType::bbga;
		using BaseType::bbbr;
		using BaseType::bbbg;
		using BaseType::bbbb;
		using BaseType::bbba;
		using BaseType::bbar;
		using BaseType::bbag;
		using BaseType::bbab;
		using BaseType::bbaa;
		using BaseType::barr;
		using BaseType::barg;
		using BaseType::barb;
		using BaseType::bara;
		using BaseType::bagr;
		using BaseType::bagg;
		using BaseType::bagb;
		using BaseType::baga;
		using BaseType::babr;
		using BaseType::babg;
		using BaseType::babb;
		using BaseType::baba;
		using BaseType::baar;
		using BaseType::baag;
		using BaseType::baab;
		using BaseType::baaa;
		using BaseType::arrr;
		using BaseType::arrg;
		using BaseType::arrb;
		using BaseType::arra;
		using BaseType::argr;
		using BaseType::argg;
		using BaseType::argb;
		using BaseType::arga;
		using BaseType::arbr;
		using BaseType::arbg;
		using BaseType::arbb;
		using BaseType::arba;
		using BaseType::arar;
		using BaseType::arag;
		using BaseType::arab;
		using BaseType::araa;
		using BaseType::agrr;
		using BaseType::agrg;
		using BaseType::agrb;
		using BaseType::agra;
		using BaseType::aggr;
		using BaseType::aggg;
		using BaseType::aggb;
		using BaseType::agga;
		using BaseType::agbr;
		using BaseType::agbg;
		using BaseType::agbb;
		using BaseType::agba;
		using BaseType::agar;
		using BaseType::agag;
		using BaseType::agab;
		using BaseType::agaa;
		using BaseType::abrr;
		using BaseType::abrg;
		using BaseType::abrb;
		using BaseType::abra;
		using BaseType::abgr;
		using BaseType::abgg;
		using BaseType::abgb;
		using BaseType::abga;
		using BaseType::abbr;
		using BaseType::abbg;
		using BaseType::abbb;
		using BaseType::abba;
		using BaseType::abar;
		using BaseType::abag;
		using BaseType::abab;
		using BaseType::abaa;
		using BaseType::aarr;
		using BaseType::aarg;
		using BaseType::aarb;
		using BaseType::aara;
		using BaseType::aagr;
		using BaseType::aagg;
		using BaseType::aagb;
		using BaseType::aaga;
		using BaseType::aabr;
		using BaseType::aabg;
		using BaseType::aabb;
		using BaseType::aaba;
		using BaseType::aaar;
		using BaseType::aaag;
		using BaseType::aaab;
		using BaseType::aaaa;

		Color() :
			BaseType()
		{
		}

		Color(SCALAR r, SCALAR g, SCALAR b, SCALAR a) :
			BaseType(r, g, b, a)
		{
		}
	};
}

#endif // !EXTRAX_COLOR_BASE_H