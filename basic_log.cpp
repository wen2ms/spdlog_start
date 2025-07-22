#include <spdlog/spdlog.h>

int main() {
    spdlog::set_level(spdlog::level::debug);

    spdlog::trace("Trace");
    spdlog::debug("Debug");
    spdlog::info("Info");
    spdlog::warn("Warn");
    spdlog::error("Error");
    spdlog::critical("Critical");

    return 0;
}