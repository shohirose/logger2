#ifndef SHIROSE_LOGGING_HPP
#define SHIROSE_LOGGING_HPP

#include <memory>

#include "shirose/logger.hpp"

namespace shirose {

/// @brief Get a pointer to the logger
///
/// The default logger is ConsoleLogger with LogLevel::error and
/// DefaultLogFormatter. The logger can be reset through setLogger() function.
LoggerInterface* getLogger();

/// @brief Set a logger.
/// @param[in] logger Logger
void setLogger(const std::shared_ptr<LoggerInterface>& logger);

}  // namespace shirose

#endif  // SHIROSE_LOGGING_HPP
