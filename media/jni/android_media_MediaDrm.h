/*
 * Copyright 2013, The Android Open Source Project
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

#ifndef _ANDROID_MEDIA_DRM_H_
#define _ANDROID_MEDIA_DRM_H_

#include "jni.h"

#include <media/stagefright/foundation/ABase.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>

namespace android {

struct IDrm;

struct JDrm : public RefBase {
    static bool IsCryptoSchemeSupported(const uint8_t uuid[16]);

    JDrm(JNIEnv *env, jobject thiz, const uint8_t uuid[16]);

    status_t initCheck() const;

    sp<IDrm> getDrm() { return mDrm; }

protected:
    virtual ~JDrm();

private:
    jweak mObject;
    sp<IDrm> mDrm;

    static sp<IDrm> MakeDrm();
    static sp<IDrm> MakeDrm(const uint8_t uuid[16]);

    DISALLOW_EVIL_CONSTRUCTORS(JDrm);
};

}  // namespace android

#endif  // _ANDROID_MEDIA_DRM_H_
