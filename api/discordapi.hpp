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

    enum class polling_flags;
}

struct discord_api::error_type {
    const std::string error;
    const std::string command;
    const unsigned int code;

    error_type(std::string error, std::string command, unsigned int code) noexcept;
    std::string full_message() const;
};


enum class discord_api::polling_flags {
    USERNAME_CHANGED,
    USER_AVATAR_CHANGED,
    USER_MENTIONED,
    USER_JOINED, //Tripped when user joins server, does not trip USER_ONLINE
    USER_ONLINE,
    USER_OFFLINE,
    USER_LEFT,
    USER_ROLE_CHANGED,

    BOT_JOINED, //Tripped when bot joins server, does not trip BOT_ONLINE
    BOT_LEFT,
    BOT_ONLINE,
    BOT_OFFLINE,
    BOT_MENTIONED,
    BOT_MESSAGE_SENT, //does not trigger MESSAGE_SENT

    CHANNEL_LEFT,
    CHANNEL_ENTERED,
    CHANNEL_CREATED,
    CHANNEL_DELETED,
    CHANNEL_PERMISSIONS_CHANGED,

    MESSAGE_SENT,
    MESSAGE_DELETED,
    MESSAGE_PINNED,
    MESSAGE_UNPINNED

};
#endif //ADMINBOT_DISCORDAPI_HPP
