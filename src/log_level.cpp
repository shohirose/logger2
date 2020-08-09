#include "shirose/log_level.hpp"

#include <cassert>

namespace shirose {

std::string getLogLevelName(LogLevel logLevel) {
  switch (logLevel) {
    case LogLevel::off:
      return "OFF";
    case LogLevel::fatal:
      return "FATAL";
    case LogLevel::error:
      return "ERROR";
    case LogLevel::warn:
      return "WARN";
    case LogLevel::info:
      return "INFO";
    case LogLevel::debug:
      return "DEBUG";
    case LogLevel::trace:
      return "TRACE";
    default:
      return "UNKNOWN";
  }
}

}  // namespace shirose
