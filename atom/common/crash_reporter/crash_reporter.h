// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_CRASH_REPORTER_CRASH_REPORTER_H_
#define ATOM_COMMON_CRASH_REPORTER_CRASH_REPORTER_H_

#include <map>
#include <string>

#include "base/basictypes.h"

namespace crash_reporter {

class CrashReporter {
 public:
  typedef std::map<std::string, std::string> StringMap;

  static CrashReporter* GetInstance();

  void Start(const std::string& product_name,
             const std::string& company_name,
             const std::string& submit_url,
             bool auto_submit,
             bool skip_system_crash_handler,
             const StringMap& extra_parameters);

 protected:
  CrashReporter();
  virtual ~CrashReporter();

  virtual void InitBreakpad(const std::string& product_name,
                            const std::string& version,
                            const std::string& company_name,
                            const std::string& submit_url,
                            bool auto_submit,
                            bool skip_system_crash_handler) = 0;
  virtual void SetUploadParameters() = 0;

  StringMap upload_parameters_;
  bool is_browser_;

 private:
  void SetUploadParameters(const StringMap& parameters);

  DISALLOW_COPY_AND_ASSIGN(CrashReporter);
};

}  // namespace crash_reporter

#endif  // ATOM_COMMON_CRASH_REPORTER_CRASH_REPORTER_H_
