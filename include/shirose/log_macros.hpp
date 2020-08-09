#ifndef SHIROSE_LOG_MACROS_HPP
#define SHIROSE_LOG_MACROS_HPP

#include "shirose/logging.hpp"
#include "shirose/log_level.hpp"

namespace shirose {

#define SHIROSE_LOG(level, tag, str)             \
  {                                              \
    auto* logger = getLogger();                  \
    if (logger && logger->logLevel() >= level) { \
      logger->log(level, tag, str);              \
    }                                            \
  }

#define SHIROSE_LOG_FATAL(tag, str)                        \
  {                                                        \
    auto* logger = getLogger();                            \
    if (logger && logger->logLevel() >= LogLevel::fatal) { \
      logger->log(LogLevel::fatal, tag, str);              \
    }                                                      \
  }

#define SHIROSE_LOG_ERROR(tag, str)                        \
  {                                                        \
    auto* logger = getLogger();                            \
    if (logger && logger->logLevel() >= LogLevel::error) { \
      logger->log(LogLevel::error, tag, str);              \
    }                                                      \
  }

#define SHIROSE_LOG_WARN(tag, str)                        \
  {                                                       \
    auto* logger = getLogger();                           \
    if (logger && logger->logLevel() >= LogLevel::warn) { \
      logger->log(LogLevel::warn, tag, str);              \
    }                                                     \
  }

#define SHIROSE_LOG_INFO(tag, str)                        \
  {                                                       \
    auto* logger = getLogger();                           \
    if (logger && logger->logLevel() >= LogLevel::info) { \
      logger->log(LogLevel::info, tag, str);              \
    }                                                     \
  }

#define SHIROSE_LOG_DEBUG(tag, str)                        \
  {                                                        \
    auto* logger = getLogger();                            \
    if (logger && logger->logLevel() >= LogLevel::debug) { \
      logger->log(LogLevel::debug, tag, str);              \
    }                                                      \
  }

#define SHIROSE_LOG_TRACE(tag, str)                        \
  {                                                        \
    auto* logger = getLogger();                            \
    if (logger && logger->logLevel() >= LogLevel::trace) { \
      logger->log(LogLevel::trace, tag, str);              \
    }                                                      \
  }

}  // namespace shirose

#endif  // SHIROSE_LOG_MACROS_HPP