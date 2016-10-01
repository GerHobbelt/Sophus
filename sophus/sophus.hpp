// This file is part of Sophus.
//
// Copyright 2013 Hauke Strasdat
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights  to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef SOPHUS_HPP
#define SOPHUS_HPP

#include <stdexcept>

#include <cmath>
#include <Eigen/Core>

#include "ensure.hpp"

// Make sure this compiles with older versions of Eigen which do not have
// EIGEN_DEVICE_FUNC defined.
#ifndef EIGEN_DEVICE_FUNC
#define EIGEN_DEVICE_FUNC
#endif

namespace Sophus {

template <typename Scalar>
struct SophusConstants {
  EIGEN_DEVICE_FUNC EIGEN_ALWAYS_INLINE static Scalar epsilon() {
    return static_cast<Scalar>(1e-10);
  }

  EIGEN_DEVICE_FUNC EIGEN_ALWAYS_INLINE static Scalar pi() {
    return static_cast<Scalar>(M_PI);
  }
};

template <>
struct SophusConstants<float> {
  EIGEN_DEVICE_FUNC EIGEN_ALWAYS_INLINE static float epsilon() {
    return static_cast<float>(1e-5);
  }

  EIGEN_DEVICE_FUNC EIGEN_ALWAYS_INLINE static float pi() {
    return static_cast<float>(M_PI);
  }
};
}

#endif
