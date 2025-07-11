//
// shh - C++ WebServer
// author: mladicstefan
// repo: https://github.com/mladicstefan/shhh
// LISCENSE: MIT
//

#pragma once
#include "buffer.hpp"
#include <vector>
#ifndef request_h
#define request_h

#include<string>
#include <unordered_map>

namespace shh{

class HttpRequest{
private:
    bool parse_requestline(std::string& line);
    bool parse_headers(std::string& line);
    bool parse_body(std::string& line);
    void parse_path(std::vector<std::string> files);

public:
    enum PARSE_STATE{
        REQUEST_LINE,
        HEADERS,
        BODY,
        FINISH,
    };
    HttpRequest();
    ~HttpRequest() = default;

    bool parse(shh::Buffer &Buffer); //this needs to take in buffer later
private:
    std::string method_, path_, version_, body_;
    std::unordered_map<std::string, std::string> headers_;
    PARSE_STATE state_;
};
}

#endif /*request_h*/
