#pragma once

#ifndef PARSER_H__
# define PARSER_H__

# include <vector>
# include <string>
# include <sstream>
# include <iostream>
# include <stdexcept>

struct Parser {
    static void parse(std::vector<int>& dest, int argc, char *argv[]);
};

#endif
