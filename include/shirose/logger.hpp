#ifndef SHIROSE_LOGGER_HPP
#define SHIROSE_LOGGER_HPP

#include <memory>
#include <string>

#include "shirose/log_formatter.hpp"
#include "shirose/log_level.hpp"

namespace shirose {

class LoggerInterface {
 public:
  virtual ~LoggerInterface() = default;

  virtual LogLevel getLogLevel() const = 0;

  virtual void setLogLevel(LogLevel logLevel) = 0;

  /// @brief Writes a message with a log level and a tag.
  /// @param[in] logLevel Log level
  /// @param[in] tag Tag
  /// @param[in] message Message
  virtual void log(LogLevel logLevel, const char* tag,
                   const std::string& message) = 0;

  virtual void flush() = 0;
};

class ConsoleLogger : public LoggerInterface {
 public:
  /// @brief Constructs a logger which outputs log messages to the standard
  /// output or std::cout.
  /// @param[in] logLevel Log level
  /// @param[in] logFormatter Log formatter
  ///
  /// The log messages are formatted by a given log formatter.
  ConsoleLogger(LogLevel logLevel,
                std::unique_ptr<LogFormatterInterface> logFormatter);

  ~ConsoleLogger() override = default;

  LogLevel getLogLevel() const override { return m_logLevel; }

  void setLogLevel(LogLevel logLevel) override { m_logLevel = logLevel; }

  /// @brief Outputs a message with a log level and a tag to the standard output
  /// (std::cout).
  /// @param[in] logLevel Log level
  /// @param[in] tag Tag
  /// @param[in] message Message
  ///
  /// Log messages are formatted by a given log formatter.
  void log(LogLevel logLevel, const char* tag,
           const std::string& message) override;

  /// @brief Flush the standard output (Call std::cout.flush()).
  void flush() override;

 private:
  LogLevel m_logLevel;
  std::unique_ptr<LogFormatterInterface> m_logFormatter;
};

/// @brief Get a pointer to the library logger
///
/// The default logger is ConsoleLogger with LogLevel::error and
/// DefaultLogFormatter. The library logger can be reset through setLogger() function.
LoggerInterface* getLogger();

/// @brief Set a new logger to the library logger.
/// @param[in] logger Logger
void setLogger(const std::shared_ptr<LoggerInterface>& logger);

}  // namespace shirose

#endif  // SHIROSE_LOGGER_HPP