#pragma once

#include "agl/standard/all.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace eng {

struct ShaderCompiler {
    std::string root = "./";
    std::string log_folder;

    auto read_file(const std::string& filepath) const {
        auto fullpath = root + filepath;
        return agl::standard::string(std::filesystem::path(fullpath));
    }

    std::string process_include_directives(const std::string& source) const {
        auto content = source;
        auto result = std::string();

        auto match = std::smatch();
        auto regex = std::regex(R"?(#include\W*"([.\\\w\.\/]*)")?");

        while(std::regex_search(content, match, regex)) {
            result += match.prefix();
            result += process_include_directives(read_file(match.str(1)));
            content = match.suffix();
        }

        result += std::move(content);
        
        return result;
    }

    auto operator()(const std::string& filepath, agl::ShaderType st) const {
        auto source = process_include_directives(read_file(filepath));

        auto shader = create(st);
        agl::source(shader, source);
        compile(shader);

        auto fp = filepath;
        for(auto& c : fp) {
            if(c == '/') {
                c = '_';
            }
        }
        auto log_file = std::ofstream(
            log_folder + "log_" + fp,
            std::ios::out | std::ios::trunc);
        if(log_file.is_open()) {
            log_file << source << std::flush;
            if(!compile_status(shader)) {
                auto il = info_log(shader);
                std::cerr << il << std::endl;
                log_file << "/*\n" << il << "*/" << std::endl;
                throw std::runtime_error("Failed to compile shader.");
            }
        } else {
            throw std::runtime_error("Failed to create: " + log_folder + "log_" + filepath);
        }

        return shader;
    }
};

}
