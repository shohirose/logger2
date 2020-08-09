#include "shirose/logging.hpp"

namespace shirose {

namespace {

std::shared_ptr<LoggerInterface>& getLibLogger() {
  static thread_local std::shared_ptr<LoggerInterface> logger;
  return logger;
}

}  // anonymous namespace

void initializeLogger(const std::shared_ptr<LoggerInterface>& logger) {
  getLibLogger() = logger;
}

void finalizeLogger() { getLibLogger() = nullptr; }

LoggerInterface* getLogger() { return getLibLogger().get(); }

void pushLogger(const std::shared_ptr<LoggerInterface>& logger) {
  getLibLogger() = logger;
}

void popLogger() { getLibLogger() = nullptr; }

}  // namespace shirose
