#ifndef SHIROSE_LOG_FORMATTER_HPP
#define SHIROSE_LOG_FORMATTER_HPP

#include <string>

#include "shirose/log_level.hpp"

namespace shirose {

class LogFormatterInterface {
 public:
  virtual ~LogFormatterInterface() = default;

  virtual std::string formatLog(LogLevel logLevel, const char* tag,
                                const std::string& message) = 0;
};

/// @brief Default log fomatter.
///
/// Formats log messages into:
/// [LogLevel] YY-MM-DD hh:mm:ss [tag] [thread-id] message
class DefaultLogFormatter : public LogFormatterInterface {
 public:
  ~DefaultLogFormatter() override = default;

  /// @brief Returns a formatted log message.
  /// @param[in] logLevel Log level
  /// @param[in] tag Tag
  /// @param[in] message Message
  std::string formatLog(LogLevel logLevel, const char* tag,
                        const std::string& message) override;
};

}  // namespace shirose

#endif  // SHIROSE_LOG_FORMATTER_HPP