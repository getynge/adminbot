//
// Created by getynge on 12/16/17.
//


#include "../discordapi.hpp"
#include <sstream>

discord_api::error_type::error_type(std::string error, std::string command, unsigned int code) noexcept
        : error(std::move(error)), command(std::move(command)), code(code) {}

std::string discord_api::error_type::full_message() const {
    std::stringstream buf;
    buf<<"Encountered error while attempting to run command "<<command<<" got code "<<code<<" with description "<<error<<std::endl;
    return buf.str();
}