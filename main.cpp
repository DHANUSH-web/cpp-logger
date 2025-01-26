#include <logger.h>

int main() {
    const std::string root_dir = "cache";
    const std::string log_file = "test_logger.log";

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