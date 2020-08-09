#ifndef SHIROSE_LOGGING_HPP
#define SHIROSE_LOGGING_HPP

#include <memory>

#include "shirose/logger.hpp"

namespace shirose
{

/// @brief Initialize a logger
/// @param[in] logger Logger
void initializeLogger(const std::shared_ptr<LoggerInterface>& logger);

/// @brief Finalize a logger
void finalizeLogger();

/// @brief Get a logger
LoggerInterface* getLogger();

/// @brief Push a logger
void pushLogger(const std::shared_ptr<LoggerInterface>& logger);

/// @brief Pop a logger
void popLogger();
    
} // namespace shirose

#endif // SHIROSE_LOGGING_HPP
