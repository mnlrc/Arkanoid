/**
 * @file logger.hpp
 * @author Manuel Rocca
 * @brief Header file for the Logger class.
 * @date 2025
 *
 * @details This file contains the definition of the Logger class, which is a
 * Singleton that saves all the logs in a file arkanoid.log.
 */

#pragma once

#ifndef LOGGER_HPP
#define LOGGER_HPP

// #### C++ Includes ####
// STD
#include <fstream>
#include <memory>
#include <string>

using namespace std;

class Logger {
public:
  /**
   * @brief Get the instance of the Logger
   *
   * @return Logger& The instance of the Logger
   */
  static Logger &getInstance(const string &filename = "");

  /**
   * @brief Destroy the Logger object
   *
   */
  ~Logger();

  /**
   * @brief Log a message to the log file
   *
   * @param message The message to log
   */
  static void log(const string &message);

  // Delete the copy constructor and assignment operator
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

private:
  /**
   * @brief Construct a new Logger object
   *
   */
  Logger();

  static unique_ptr<Logger> instance_;
  static ofstream logFile_;
};

#endif // LOGGER_HPP
