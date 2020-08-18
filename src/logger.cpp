#include "shirose/logger.hpp"

#include <iostream>
#include <string>

namespace shirose {

ConsoleLogger::ConsoleLogger(
    LogLevel logLevel, std::unique_ptr<LogFormatterInterface> logFormatter)
    : Base{},
      m_logLevel{logLevel},
      m_logFormatter{std::move(logFormatter)},
      m_coutMutex{} {}

void ConsoleLogger::log(LogLevel logLevel, const char* tag,
                        const std::string& message) {
  std::lock_guard<std::mutex> lock(m_coutMutex);
  std::cout << m_logFormatter->formatLog(logLevel, tag, message);
}

void ConsoleLogger::flush() { std::cout.flush(); }

FileLogger::FileLogger(LogLevel logLevel,
                       std::unique_ptr<LogFormatterInterface> logFormatter,
                       const std::string& fileName)
    : Base{},
      m_logLevel{logLevel},
      m_logFormatter{std::move(logFormatter)},
      m_logFile{fileName} {}

void FileLogger::log(LogLevel logLevel, const char* tag,
                     const std::string& message) {
  m_logFile << m_logFormatter->formatLog(logLevel, tag, message);
}

void FileLogger::flush() { m_logFile.flush(); }

namespace {

std::shared_ptr<LoggerInterface>& getLibraryLogger() {
  static thread_local std::shared_ptr<LoggerInterface> logger =
      std::make_shared<ConsoleLogger>(LogLevel::error,
                                      std::make_unique<DefaultLogFormatter>());
  return logger;
}

}  // anonymous namespace

LoggerInterface* getLogger() { return getLibraryLogger().get(); }

void setLogger(const std::shared_ptr<LoggerInterface>& logger) {
  getLibraryLogger() = logger;
}

}  // namespace shirose
