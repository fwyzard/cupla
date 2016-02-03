/**
 * Copyright 2016 Rene Widera
 *
 * This file is part of cupla.
 *
 * cupla is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cupla is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with cupla.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */


#pragma once

#include <alpaka/alpaka.hpp>

#include "cupla/kernel.hpp"

#include "cupla/datatypes/Array.hpp"
#include "cupla/datatypes/dim3.hpp"
#include "cupla/datatypes/uint.hpp"

#include "cupla/types.hpp"
#include "cupla_driver_types.hpp"





cuplaError_t
cuplaSetDevice( int idx);

cuplaError_t
cuplaGetDevice( int * deviceId );

cuplaError_t
cuplaEventCreate(
    cuplaEvent_t * event,
    unsigned int flags = 0
);

cuplaError_t
cuplaEventDestroy( cuplaEvent_t event );

cuplaError_t
cuplaEventRecord(
    cuplaEvent_t event,
    cuplaStream_t stream = 0
);

cuplaError_t
cuplaEventElapsedTime(
    float * ms,
    cuplaEvent_t start,
    cuplaEvent_t end
);

cuplaError_t
cuplaEventSynchronize(
    cuplaEvent_t event
);

cuplaError_t
cuplaMalloc(
    void **ptrptr,
    size_t size
);

cuplaError_t
cuplaFree(void *ptr);

const char *
cuplaGetErrorString(cuplaError_t);

cuplaError_t
cuplaMemcpy(
    void *dst,
    const void *src,
    size_t count,
    enum cuplaMemcpyKind kind
);
