/*
 * Copyright 2010 The Native Client Authors. All rights reserved.
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

#ifndef NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_SEL_QUALIFY_H_
#define NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_SEL_QUALIFY_H_

/*
 * We have several different ways of starting Native Client, but all of them
 * need to run minimal checks during sel_ldr startup to ensure that the
 * environment can't subvert our security.  This header provides a high-level
 * interface to the Platform Qualification tests for this very purpose.
 */

#include "src/main/nacl_base.h"

EXTERN_C_BEGIN

/*
 * Runs the Platform Qualification tests required for safe sel startup.  This
 * may be a subset of the full set of PQ tests: it includes the tests that are
 * important enough to check at every startup, and tests that check aspects of
 * the system that may be subject to change.
 * d'b: abort zvm if failed
 */
void NaClRunSelQualificationTests();

EXTERN_C_END

#endif  /* NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_SEL_QUALIFY_H_ */
