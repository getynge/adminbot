//
// Created by getynge on 12/16/17.
//

#ifndef ADMINBOT_DISCORDAPI_HPP
#define ADMINBOT_DISCORDAPI_HPP

#include <variant>
#include <string>

namespace discord_api{
    struct error_type;

    template <typename T>
    using result<T> = std::variant<T, error_type>;
}

struct discord_api::error_type {
    const std::string error;
    const std::string command;
    const unsigned int code;

    error_type(std::string error, std::string command, unsigned int code) noexcept;
    std::string full_message() const;
};

#endif //ADMINBOT_DISCORDAPI_HPP
