#ifndef SHIROSE_LOGGER_HPP
#define SHIROSE_LOGGER_HPP

#include <fstream>
#include <memory>
#include <string>
#include <mutex>

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

/// @brief A logger which outputs log messages to the standard output.
///
/// Log messages are formatted by a given log formatter.
class ConsoleLogger : public LoggerInterface {
 public:
  using Base = LoggerInterface;

  /// @param[in] logLevel Log level
  /// @param[in] logFormatter Log formatter
  ConsoleLogger(LogLevel logLevel,
                std::unique_ptr<LogFormatterInterface> logFormatter);

  ~ConsoleLogger() override = default;

  LogLevel getLogLevel() const override { return m_logLevel; }

  void setLogLevel(LogLevel logLevel) override { m_logLevel = logLevel; }

  /// @brief Outputs a message with a log level and a tag.
  /// @param[in] logLevel Log level
  /// @param[in] tag Tag
  /// @param[in] message Message
  void log(LogLevel logLevel, const char* tag,
           const std::string& message) override;

  /// @brief Flush the standard output (Call std::cout.flush()).
  void flush() override;

 private:
  LogLevel m_logLevel;
  std::unique_ptr<LogFormatterInterface> m_logFormatter;
  std::mutex m_coutMutex;
};

/// @brief A logger which outputs log messages to a file.
///
/// Log messages are formatted by a given log formatter.
class FileLogger : public LoggerInterface {
 public:
  using Base = LoggerInterface;

  /// @param[in] logLevel Log level
  /// @param[in] logFormatter Log formatter
  /// @param[in] fileName Log file name
  FileLogger(LogLevel logLevel,
             std::unique_ptr<LogFormatterInterface> logFormatter,
             const std::string& fileName);

  ~FileLogger() override = default;

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
  std::ofstream m_logFile;
};

/// @brief Get a pointer to the library logger
///
/// The default logger is ConsoleLogger with LogLevel::error and
/// DefaultLogFormatter. The library logger can be reset through setLogger()
/// function.
LoggerInterface* getLogger();

/// @brief Set a new logger to the library logger.
/// @param[in] logger Logger
void setLogger(const std::shared_ptr<LoggerInterface>& logger);

}  // namespace shirose

#endif  // SHIROSE_LOGGER_HPP