#include <gtest/gtest.h>

#include <regex>

#include "shirose/log_formatter.hpp"
#include "shirose/log_level.hpp"
#include "shirose/logger.hpp"

using namespace shirose;

TEST(LogLevelTest, LogNameTest) {
  EXPECT_EQ(getLogLevelName(LogLevel::off), std::string("OFF"));
  EXPECT_EQ(getLogLevelName(LogLevel::fatal), std::string("FATAL"));
  EXPECT_EQ(getLogLevelName(LogLevel::error), std::string("ERROR"));
  EXPECT_EQ(getLogLevelName(LogLevel::warn), std::string("WARN"));
  EXPECT_EQ(getLogLevelName(LogLevel::info), std::string("INFO"));
  EXPECT_EQ(getLogLevelName(LogLevel::debug), std::string("DEBUG"));
  EXPECT_EQ(getLogLevelName(LogLevel::trace), std::string("TRACE"));
}

TEST(LogFormatterTest, DefaultLogFormatterTest) {
  DefaultLogFormatter formatter;
  const auto logMessage = formatter.formatLog(LogLevel::error, "TEST", "");
  std::cout << logMessage << std::endl;

  /*
  std::regex re(
      "^\\[ERROR\\] 2020-08-10 .*"
      //"[0-9]*:[0-9]*:[0-9]* TEST \\[[0-9]*\\] "
      //"This is a unit test\\."
  );

  std::smatch match;
  EXPECT_TRUE(std::regex_match(logMessage, match, re));

  std::cout << "str = " << match.str() << ", pos = " << match.position()
            << std::endl;
  */
}

TEST(LoggerTest, ConsoleLoggerTest) {
  ConsoleLogger logger(LogLevel::info, std::make_unique<DefaultLogFormatter>());

  EXPECT_EQ(logger.getLogLevel(), LogLevel::info);

  logger.setLogLevel(LogLevel::warn);
  EXPECT_EQ(logger.getLogLevel(), LogLevel::warn);

  // Redirect std::cout's output stream to local string stream.
  std::stringstream ss;
  auto* coutbuf = std::cout.rdbuf(ss.rdbuf());
  logger.log(LogLevel::warn, "TEST", "ConsoleLoggerTest 1");

  // Reset buf
  std::cout.rdbuf(coutbuf);
  std::cout << ss.str();

  logger.log(LogLevel::info, "TEST", "ConsoleLoggerTest 2");
  logger.flush();
}

TEST(LoggingTest, FunctionTest) {
  auto* systemLogger = getLogger();
  ASSERT_NE(systemLogger, nullptr);

  EXPECT_EQ(systemLogger->getLogLevel(), LogLevel::error);

  systemLogger->setLogLevel(LogLevel::off);
  EXPECT_EQ(systemLogger->getLogLevel(), LogLevel::off);

  systemLogger->log(LogLevel::fatal, "TEST", "ConsoleLoggerTest 3");
  systemLogger->flush();
}