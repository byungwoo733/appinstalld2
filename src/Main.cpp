// Copyright (c) 2013-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>

#include "base/Logging.h"
#include "settings/Settings.h"
#include "AppImpl.h"

int main(int argc, char **argv)
{
    if (!MainApp::instance().create())
    {
        LOG_ERROR(MSGID_SRVC_INIT_FAIL,0,"Service failed to initialize");
        return -1;
    }

    return MainApp::instance().run();
}
