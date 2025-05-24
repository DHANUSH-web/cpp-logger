/*
 * Use this file to demo or practive Logger usage and implementation.
 * Please contribute to this project by raising pull request at
 * https://github.com/DHANUSH-web/cpp-logger.git/pulls
 *
 * Developer  - Dhanush H V <dhanushhv75@gmail.com>
 * Website    - https://dhanushhv.vercel.app
 */

#include "logger.h"
#include <filesystem> // For std::filesystem::path and std::filesystem::current_path()
#include <stdexcept>  // For std::runtime_error
#include <iostream>   // For std::cerr and std::endl

// Handle file system for specific platform (getcwd is no longer used)
// #ifdef _WIN32
// #include <direct.h>
// #else
// #include <unistd.h>
// #endif

int main() {
    const std::string name     = "main";
    // Use std::filesystem for robust path construction
    const std::string root_dir = (std::filesystem::current_path() / "cache").string();
    const std::string log_file = "test_logger.log";    // Insert log file name
    const bool debug           = true;

    try {
        // Initiated logger instance
        auto logger = Logger(name, root_dir, log_file, debug);

        // add some logs
        logger.log("Debug log!",    LOGGER::LEVEL::DEBUG);
        logger.log("Info log!",     LOGGER::LEVEL::INFO);
        logger.log("Warning log!",  LOGGER::LEVEL::WARNING);
        logger.log("Error log!",    LOGGER::LEVEL::ERROR);
        logger.log("Fatal log!",    LOGGER::LEVEL::FATAL);
        // logger.log("Unknown log!",  LOGGER::LEVEL::UNKNOWN); // This level is valid
        logger.log("Message log!",  LOGGER::LEVEL::MESSAGE);

        // Example of logging an invalid level to test error handling in logger.log()
        // Note: This will throw std::runtime_error due to recent changes in Logger::log()
        // logger.log("This is an invalid level!", "INVALID_LEVEL");


        // The destructor of logger will call exit_logger() automatically.
        // Explicitly calling logger.exit_logger(); is no longer strictly necessary
        // if logger is the last thing to be used in this scope.
        // However, if you need to ensure logs are flushed before further operations
        // not shown here, or before a crash might prevent destructor from running,
        // calling it explicitly can still be useful.
        // For this example, we'll rely on the destructor.
        // logger.exit_logger();

    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
        return 1; // Indicate failure
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
        return 1; // Indicate failure
    }

    return 0; // Indicate success
}
