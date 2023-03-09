#ifndef SENTRY_H
#define SENTRY_H

#include <sentry.h>

#include "parameters.h"
#include "version.h"

static void initializeSentry() {
  sentry_options_t* options = sentry_options_new();
  sentry_options_set_symbolize_stacktraces(options, true);
  sentry_options_set_dsn(options, parameters::sentry_dsn);
  sentry_options_set_database_path(options, ".sentry-native");
  sentry_options_set_release(options, version::getVersionString());
  sentry_options_set_traces_sample_rate(options, 0.2);
  sentry_init(options);
}

#endif  // SENTRY_H
