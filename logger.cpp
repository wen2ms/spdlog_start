#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <iostream>

int main() {
    // color multi-threaded logger
    std::shared_ptr<spdlog::logger> console_logger = spdlog::stdout_color_mt("console_logger");
    std::shared_ptr<spdlog::logger> file_logger = spdlog::basic_logger_mt("file_logger", "file_logger.txt");

    console_logger->set_level(spdlog::level::debug);
    file_logger->set_level(spdlog::level::info);

    console_logger->debug("Debug");
    console_logger->info("Welcome to info");
    console_logger->error("Error {}", 1);

    file_logger->debug("Debug");
    file_logger->info("Welcome to info");
    file_logger->error("Error {}", 2);

    return 0;
}