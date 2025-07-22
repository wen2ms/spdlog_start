#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

int main() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto console_logger = std::make_shared<spdlog::logger>("console_logger", console_sink);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("file_multilogger.txt");
    auto file_logger = std::make_shared<spdlog::logger>("file_logger", file_sink);

    spdlog::sinks_init_list sinks = {console_sink, file_sink};
    auto multilogger = std::make_shared<spdlog::logger>("multilogger", sinks.begin(), sinks.end());

    spdlog::set_default_logger(multilogger);

    spdlog::set_level(spdlog::level::debug);

    spdlog::info("Hello, info!");
    spdlog::error("An error!");

    spdlog::debug("Debugging");
    spdlog::info("Info message");
    spdlog::warn("warning");

    spdlog::drop_all();

    return 0;
}