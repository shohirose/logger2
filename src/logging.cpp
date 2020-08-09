#include "shirose/logging.hpp"

namespace shirose {

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
