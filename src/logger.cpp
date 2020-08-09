#include "shirose/logger.hpp"

#include <iostream>
#include <string>

namespace shirose {

ConsoleLogger::ConsoleLogger(
    LogLevel logLevel, std::unique_ptr<LogFormatterInterface> logFormatter)
    : m_logLevel{logLevel}, m_logFormatter{std::move(logFormatter)} {}

void ConsoleLogger::log(LogLevel logLevel, const char* tag,
                        const std::string& message) {
  std::cout << m_logFormatter->formatLog(logLevel, tag, message);
}

void ConsoleLogger::flush() { std::cout.flush(); }

}  // namespace shirose
