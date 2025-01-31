/*
 *  ************************************************************************
 *  Copyright (c) 2025, Dhanush H V. All rights reserved.
 *  Licensed under the MIT License. See the LICENSE file for more details
 *  *************************************************************************
 */

#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <chrono>
#include <manager.h>
#include <map>

// Logger namespace with utilities
namespace LOGGER {
    // Define logger colors
    namespace COLOR {
        const std::string RED       = "\x1B[31m";
        const std::string GREEN     = "\x1B[32m";
        const std::string YELLOW    = "\x1B[33m";
        const std::string ORANGE    = "\x1B[33m";
        const std::string BLUE      = "\x1B[34m";
        const std::string MAGENTA   = "\x1B[35m";
        const std::string CYAN      = "\x1B[36m";
        const std::string WHITE     = "\x1B[37m";
        const std::string RESET     = "\x1B[0m";
    }

    // Different text styles
    namespace TEXT {
        const std::string BOLD      = "\x1B[1m";
        const std::string UNDERLINE = "\x1B[4m";
        const std::string BLINK     = "\x1B[5m";
        const std::string REVERSE   = "\x1B[7m";
    }

    // Define the different types of log levels
    namespace LEVEL {
        const std::string DEBUG     = "DEBUG";
        const std::string INFO      = "INFO";
        const std::string WARNING   = "WARNING";
        const std::string ERROR     = "ERROR";
        const std::string FATAL     = "FATAL";
        const std::string MESSAGE   = "MESSAGE";
        const std::string UNKNOWN   = "UNKNOWN";
    }
}

// Logger level handler
class LevelHandler {
public:
    std::string level;
    std::string color;
    int count;

    LevelHandler(
        const std::string &level,
        const std::string &color,
        const int count = 0
    ) {
        this->level = level;
        this->color = color;
        this->count = count;
    }
};

class Logger {
protected:
    std::string root_dir;
    std::string file_name;
    std::ofstream log_file;
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;
    std::map<std::string, LevelHandler> handler;
    bool debug;
    int log_count;

public:
    Logger(const std::string &root_dir, const std::string &file_name, const bool debug = false) {
        this->root_dir      = root_dir;
        this->file_name     = file_name;
        this->debug         = debug;
        this->start_time    = std::chrono::system_clock::now();
        this->end_time      = std::chrono::system_clock::now();
        this->log_count     = 0;

        // Set the default levels
        this->handler.insert(std::pair(LOGGER::LEVEL::DEBUG,    LevelHandler(LOGGER::LEVEL::DEBUG,      LOGGER::COLOR::GREEN,   0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::INFO,     LevelHandler(LOGGER::LEVEL::INFO,       LOGGER::COLOR::CYAN,    0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::WARNING,  LevelHandler(LOGGER::LEVEL::WARNING,    LOGGER::COLOR::YELLOW,  0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::ERROR,    LevelHandler(LOGGER::LEVEL::ERROR,      LOGGER::COLOR::ORANGE,  0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::FATAL,    LevelHandler(LOGGER::LEVEL::FATAL,      LOGGER::COLOR::RED,     0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::MESSAGE,  LevelHandler(LOGGER::LEVEL::MESSAGE,    LOGGER::COLOR::BLUE,    0)));
        this->handler.insert(std::pair(LOGGER::LEVEL::UNKNOWN,  LevelHandler(LOGGER::LEVEL::UNKNOWN,    LOGGER::COLOR::WHITE,   0)));

        // Create the logger folder
        mkdir(root_dir.c_str(), 0777);

        // Create the logger log file
        if (this->root_dir[this->root_dir.size() - 1] == '/' ||
            this->root_dir[this->root_dir.size() - 1] == '\\'
        ) {
            this->log_file.open(this->root_dir + file_name);
        } else {
            this->log_file.open(this->root_dir + "/" + file_name);
        }

        // update the status of logger
        this->log_file << ">>> Logger initiated at " << std::chrono::system_clock::now() << " <<<\n";
        std::cout << LOGGER::COLOR::CYAN << ">>> Logger initiated at " << std::chrono::system_clock::now() << " <<<" << LOGGER::COLOR::RESET << "\n";

        // Register the logger to manager buffer
        BUF_MANAGER<Logger>::register_buf(this);
    }

    // Check if the logger is active or running
    bool is_active() const {
        return this->log_file.is_open();
    }

    // Get the root dir of the logger
    std::string get_root_dir() const {
        return this->root_dir;
    }

    // Get the file name of logger
    std::string get_file_name() const {
        return this->file_name;
    }

    // Get the time of when logger started
    std::chrono::system_clock::time_point get_start_time() const {
        return this->start_time;
    }

    // Get the time of when logger did exit
    std::chrono::system_clock::time_point get_end_time() const {
        return this->end_time;
    }

    // Get the total log count
    int get_log_count() const {
        return this->log_count;
    }

    // Get the log count of specific log level
    int get_log_level_count(const std::string &level) const {
        if (this->handler.contains(level)) {
            return this->handler.at(level).count;
        }

        throw std::invalid_argument("[ERROR]: Invalid logger level: " + level);
    }

    // Get the logger handler
    std::map<std::string, LevelHandler> get_handler() const {
        return this->handler;
    }

    // Add the main log method
    void log(const std::string &message, const std::string &level = LOGGER::LEVEL::INFO, const bool debug_once = false) {
        if (!is_active()) {
            std::cerr << "[ERROR]: Logger not active\n";
            exit(EXIT_FAILURE);
        }

        if (this->debug || debug_once) {
            print_log(message, level);
        }

        this->log_file << std::chrono::system_clock::now() << " " << level << " " << message << "\n";
        this->handler.at(level).count++;
        this->log_count++;
    }

    // Exit logger if any active logger are running
    void exit_logger() {
        if (!this->is_active()) {
            std::cerr << "NO ACTIVE LOGGER EXIST\n";
            return;
        }

        this->end_time = std::chrono::system_clock::now();
        this->log_file << ">>> Logger exited at " << this->end_time << " <<<\n";
        this->log_file.close();
        BUF_MANAGER<Logger>::unregister_buf(this);       // Unregister the logger from buffer manager
        std::cout << LOGGER::COLOR::CYAN << ">>> Exited Logger at " << this->end_time << " <<<" << LOGGER::COLOR::RESET << "\n";
    }

    // Display all the log levels for better DevEx

    // Print the log in a colored format
    static void print_log(const std::string &message, const std::string& level) {
        std::string color;

            if (level == LOGGER::LEVEL::INFO)
                color = LOGGER::COLOR::CYAN;
            else if (level == LOGGER::LEVEL::WARNING)
                color = LOGGER::COLOR::YELLOW;
            else if (level == LOGGER::LEVEL::ERROR)
                color = LOGGER::COLOR::ORANGE;
            else if (level == LOGGER::LEVEL::FATAL)
                color = LOGGER::COLOR::RED;
            else if (level == LOGGER::LEVEL::MESSAGE)
                color = LOGGER::COLOR::BLUE;
            else if (level == LOGGER::LEVEL::DEBUG)
                color = LOGGER::COLOR::GREEN;
            else
                color = LOGGER::COLOR::WHITE;

        std::cout << color << std::chrono::system_clock::now() << " " << level << " " << message << LOGGER::COLOR::RESET << "\n";
    }
};

#endif //LOGGER_H
