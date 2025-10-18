/**************************************************************************/
/*  math_defs.h                                                           */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "core/typedefs.h"

#include <limits>

namespace Math {
inline constexpr double SQRT2 = 1.4142135623730950488016887242;
inline constexpr double SQRT3 = 1.7320508075688772935274463415059;
inline constexpr double SQRT12 = 0.7071067811865475244008443621048490;
inline constexpr double SQRT13 = 0.57735026918962576450914878050196;
inline constexpr double LN2 = 0.6931471805599453094172321215;
inline constexpr double TAU = 6.2831853071795864769252867666;
inline constexpr double PI = 3.1415926535897932384626433833;
inline constexpr double E = 2.7182818284590452353602874714;
inline constexpr double INF = std::numeric_limits<double>::infinity();
inline constexpr double NaN = std::numeric_limits<double>::quiet_NaN();
} // namespace Math

#define CMP_EPSILON 0.00001
#define CMP_EPSILON2 (CMP_EPSILON * CMP_EPSILON)

#define CMP_NORMALIZE_TOLERANCE 0.000001
#define CMP_POINT_IN_PLANE_EPSILON 0.00001

#ifdef DEBUG_ENABLED
#define MATH_CHECKS
#endif

//this epsilon is for values related to a unit size (scalar or vector len)
#ifdef PRECISE_MATH_CHECKS
#define UNIT_EPSILON 0.00001
#else
//tolerate some more floating point error normally
#define UNIT_EPSILON 0.001
#endif

#define USEC_TO_SEC(m_usec) ((m_usec) / 1000000.0)

enum ClockDirection {
	CLOCKWISE,
	COUNTERCLOCKWISE
};

enum Orientation {
	HORIZONTAL,
	VERTICAL
};

enum HorizontalAlignment {
	HORIZONTAL_ALIGNMENT_LEFT,
	HORIZONTAL_ALIGNMENT_CENTER,
	HORIZONTAL_ALIGNMENT_RIGHT,
	HORIZONTAL_ALIGNMENT_FILL,
};

enum VerticalAlignment {
	VERTICAL_ALIGNMENT_TOP,
	VERTICAL_ALIGNMENT_CENTER,
	VERTICAL_ALIGNMENT_BOTTOM,
	VERTICAL_ALIGNMENT_FILL,
};

enum InlineAlignment {
	// Image alignment points.
	INLINE_ALIGNMENT_TOP_TO = 0b0000,
	INLINE_ALIGNMENT_CENTER_TO = 0b0001,
	INLINE_ALIGNMENT_BASELINE_TO = 0b0011,
	INLINE_ALIGNMENT_BOTTOM_TO = 0b0010,
	INLINE_ALIGNMENT_IMAGE_MASK = 0b0011,

	// Text alignment points.
	INLINE_ALIGNMENT_TO_TOP = 0b0000,
	INLINE_ALIGNMENT_TO_CENTER = 0b0100,
	INLINE_ALIGNMENT_TO_BASELINE = 0b1000,
	INLINE_ALIGNMENT_TO_BOTTOM = 0b1100,
	INLINE_ALIGNMENT_TEXT_MASK = 0b1100,

	// Presets.
	INLINE_ALIGNMENT_TOP = INLINE_ALIGNMENT_TOP_TO | INLINE_ALIGNMENT_TO_TOP,
	INLINE_ALIGNMENT_CENTER = INLINE_ALIGNMENT_CENTER_TO | INLINE_ALIGNMENT_TO_CENTER,
	INLINE_ALIGNMENT_BOTTOM = INLINE_ALIGNMENT_BOTTOM_TO | INLINE_ALIGNMENT_TO_BOTTOM
};

enum Side {
	SIDE_LEFT,
	SIDE_TOP,
	SIDE_RIGHT,
	SIDE_BOTTOM
};

enum Corner {
	CORNER_TOP_LEFT,
	CORNER_TOP_RIGHT,
	CORNER_BOTTOM_RIGHT,
	CORNER_BOTTOM_LEFT
};

enum class EulerOrder {
	XYZ,
	XZY,
	YXZ,
	YZX,
	ZXY,
	ZYX
};

/**
 * The "Real" type is an abstract type used for real numbers, such as 1.5,
 * in contrast to integer numbers. Precision can be controlled with the
 * presence or absence of the REAL_T_IS_DOUBLE define.
 */
#ifdef REAL_T_IS_DOUBLE
typedef double real_t;
#else
typedef float real_t;
#endif
// ----- Zeroth Float Semantics (Seidr) -------------------------------------
// Enable with: scons ... extra_cflags="-DSEIDR_ZEROTH_FLOATS"
#include <cmath>

namespace Zeroth {
	// Canonical symbolic values on top of IEEE storage:
	// Nav = +0, Nil = +1, Inf = -1, Nan = -0 (signed zero)
#ifdef REAL_T_IS_DOUBLE
	inline constexpr real_t Nav = real_t(+0.0);
	inline constexpr real_t Nil = real_t(+1.0);
	inline constexpr real_t Inf = real_t(-1.0);
	inline constexpr real_t Nan = real_t(-0.0);
#else
	inline constexpr real_t Nav = real_t(+0.0f);
	inline constexpr real_t Nil = real_t(+1.0f);
	inline constexpr real_t Inf = real_t(-1.0f);
	inline constexpr real_t Nan = real_t(-0.0f);
#endif

	// Epsilon tuned to Godot's defaults.
	inline constexpr real_t EPS = (real_t)CMP_EPSILON;

	// Predicates (work for float or double real_t)
	inline bool is_nav(real_t x) {
		// +0.0 only (not -0.0)
		return x == real_t(0) && !std::signbit((double)x);
	}
	inline bool is_nil(real_t x) {
		return std::fabs((double)(x - Nil)) <= (double)EPS;
	}
	inline bool is_inf(real_t x) {
		return std::fabs((double)(x - Inf)) <= (double)EPS;
	}
	inline bool is_nan(real_t x) {
		// Our canonical NaN is -0.0 (signed). Also fold true IEEE NaNs here.
		return (x == real_t(0) && std::signbit((double)x)) || std::isnan((double)x);
	}

	// Canonicalize any real_t into the fourfold Zeroth set when close enough.
	inline real_t canonicalize(real_t x) {
		// True IEEE NaN → our Nan (-0.0)
		if (std::isnan((double)x)) return Nan;

		// Snap near ±0.0 with sign preserved (distinguish Nav vs Nan)
		if (std::fabs((double)x) <= (double)EPS) {
			return std::signbit((double)x) ? Nan : Nav;
		}

		// Snap near Nil or Inf
		if (std::fabs((double)(x - Nil)) <= (double)EPS) return Nil;
		if (std::fabs((double)(x - Inf)) <= (double)EPS) return Inf;

		// Leave everything else unchanged (engine math still works).
		return x;
	}

	// Safe ops that keep values canonical.
	inline real_t add(real_t a, real_t b) {
		return canonicalize(a + b);
	}
	inline real_t sub(real_t a, real_t b) {
		return canonicalize(a - b);
	}
	inline real_t mul(real_t a, real_t b) {
		return canonicalize(a * b);
	}
	inline real_t div(real_t a, real_t b) {
		// Division by Nan(-0) → Nan, division by Nav(+0) → Nan as well
		if (is_nan(b) || is_nav(b)) return Nan;
		return canonicalize(a / b);
	}
}

// Optional global auto-canonicalization hooks.
// Define SEIDR_ZEROTH_FLOATS to transparently normalize at key boundaries.
// Keep this lightweight; we don't rewrite all engine math—just hot IO points.
#ifdef SEIDR_ZEROTH_FLOATS
	// Wrap common literals/macros if they’re used in calculations.
	#undef CMP_EPSILON
	#define CMP_EPSILON (Zeroth::EPS)

	// Macros to explicitly normalize where you care:
	#define Z_CANON(x) (Zeroth::canonicalize((x)))
	#define Z_IS_NAV(x) (Zeroth::is_nav((x)))
	#define Z_IS_NIL(x) (Zeroth::is_nil((x)))
	#define Z_IS_INF(x) (Zeroth::is_inf((x)))
	#define Z_IS_NAN(x) (Zeroth::is_nan((x)))
#else
	#define Z_CANON(x) (x)
	#define Z_IS_NAV(x) (false)
	#define Z_IS_NIL(x) (false)
	#define Z_IS_INF(x) (false)
	#define Z_IS_NAN(x) (false)
#endif
// -------------------------------------------------------------------------
