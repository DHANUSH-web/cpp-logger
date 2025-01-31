/*
 * Use this file to demo or practive Logger usage and implementation.
 * Please contribute to this project by raising pull request at
 * https://github.com/DHANUSH-web/cpp-logger.git/pulls
 *
 * Developer  - Dhanush H V <dhanushhv75@gmail.com>
 * Website    - https://dhanushhv.vercel.app
 */

#include <logger.h>

int main() {
    const std::string root_dir = "";    // Insert absolute path of log file root
    const std::string log_file = "";    // Insert log file name

    // Initiated logger instance
    auto logger = Logger(root_dir, log_file);

    // add some logs
    logger.log("Debug log!",    LOGGER::LEVEL::DEBUG);
    logger.log("Info log!",     LOGGER::LEVEL::INFO);
    logger.log("Warning log!",  LOGGER::LEVEL::WARNING);
    logger.log("Error log!",    LOGGER::LEVEL::ERROR);
    logger.log("Fatal log!",    LOGGER::LEVEL::FATAL);
    logger.log("Unknown log!",  LOGGER::LEVEL::UNKNOWN);
    logger.log("Message log!",  LOGGER::LEVEL::MESSAGE);

    // close logger
    logger.exit_logger();
    return 0;
}
