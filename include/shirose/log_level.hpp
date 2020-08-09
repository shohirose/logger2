#ifndef SHIROSE_LOG_LEVEL_HPP
#define SHIROSE_LOG_LEVEL_HPP

#include <string>

namespace shirose {

enum class LogLevel {
  off = 0,
  fatal,
  error,
  warn,
  info,
  debug,
  trace,
};

std::string getLogLevelName(LogLevel logLevel);

}  // namespace shirose

#endif  // SHIROSE_LOG_LEVEL_HPP