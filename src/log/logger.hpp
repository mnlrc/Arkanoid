/**
 * @file logger.hpp
 * @author Manuel Rocca
 * @brief Header file for the Logger class
 * @date 2025
 *
 * @details This file contains the definition of the Logger class, which is a
 * Singleton that saves all the logs in a file arkanoid.log
 */

#pragma once

#ifndef LOGGER_HPP
#define LOGGER_HPP

// #### C++ Includes ####
#include <fstream>
#include <memory>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

class Logger
{
public:
  /**
   * @brief Get the instance of the Logger
   *
   * @return Logger& The instance of the Logger
   */
  static Logger &get_instance(const std::string &filename = "");

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
  static void log(const std::string &message);

  // Delete the copy constructor and assignment operator
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

private:
  /**
   * @brief Construct a new Logger object
   *
   */
  Logger();

  static std::unique_ptr<Logger> instance_;
  static std::ofstream log_file_;
};

#endif // LOGGER_HPP
