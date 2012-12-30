/*
 * Copyright 2008 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */
/*
 * Copyright (c) 2012, LiteStack, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * NaCl Simple/secure ELF loader (NaCl SEL).
 */

#ifndef __SEL_ADDRSPACE_H__
#define __SEL_ADDRSPACE_H__ 1

struct NaClApp; /* fwd */

void NaClAllocAddrSpace(struct NaClApp *nap);

/*
 * Apply memory protection to memory regions.
 */
void NaClMemoryProtection(struct NaClApp *nap);

/*
 * Platform-specific routine to allocate memory space for the NaCl
 * module.  mem is an out argument; addrsp_size is the requested
 * address space size, currently always ((size_t) 1) <<
 * nap->addr_bits.  On x86-64, there's a further requirement that this
 * is 4G.
 *
 * The actual amount of memory allocated is larger than requested on
 * x86-64 and on the ARM, since guard pages are also allocated to be
 * contiguous with the allocated address space.
 *
 * If successful, the guard pages are not yet memory protected.  The
 * function NaClMprotectGuards must be called for the guard pages to
 * be active.
 *
 * update: abort zvm if failed
 */
void NaClAllocateSpace(void **mem, size_t addrsp_size);

/* protect bumpers (guarding space) */
void NaClMprotectGuards(struct NaClApp *nap);
#endif
