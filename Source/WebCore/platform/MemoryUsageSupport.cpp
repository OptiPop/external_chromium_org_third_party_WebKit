/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "MemoryUsageSupport.h"

namespace WebCore {

int MemoryUsageSupport::memoryUsageMB()
{
    return 0;
}

int MemoryUsageSupport::actualMemoryUsageMB()
{
    return 0;
}

int MemoryUsageSupport::lowMemoryUsageMB()
{
    return 0;
}

int MemoryUsageSupport::highMemoryUsageMB()
{
    return 0;
}

int MemoryUsageSupport::highUsageDeltaMB()
{
    return 0;
}
    
bool MemoryUsageSupport::processMemorySizesInBytes(size_t*, size_t*)
{
    return false;
}

void MemoryUsageSupport::requestProcessMemorySizes(PassOwnPtr<WebCore::MemoryUsageSupport::ProcessMemorySizesCallback>)
{
}

void MemoryUsageSupport::memoryUsageByComponents(Vector<ComponentInfo>&)
{
}

} // namespace WebCore