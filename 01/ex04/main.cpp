/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:27:31 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/17 17:27:41 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "FtString.hpp"

#define MSG_ARG_ERROR "Arguments error [Usage : <executable> filename dest src]"
#define MSG_FILE_OPEN_ERROR "Fail to open file"
#define MSG_FILE_CREATE_ERROR "Fail to create file"
#define MSG_READLINE_ERROR "Fail to read line"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << MSG_ARG_ERROR << std::endl;
        return 1;
    }
    const std::string inputFileName = argv[1];
    const std::string outputFileName = inputFileName.substr(0).append(".replace");
    const std::string destString = argv[2];
    const std::string srcString = argv[3];

    std::ifstream fin;
    std::ofstream fout;
    std::string readline;
    FtString writeline;

    fin.open(inputFileName);
    if (fin.fail()) {
        std::cout << MSG_FILE_OPEN_ERROR << std::endl;
        return 1;
    }

    fout.open(outputFileName);
    if (fout.fail()) {
        std::cout << MSG_FILE_CREATE_ERROR << std::endl;
        return 1;
    }

    while (!fin.eof()) {
        getline(fin, readline);
        if (fin.fail() && !fin.eof()) {
            std::cout << MSG_READLINE_ERROR << std::endl;
            remove(outputFileName.c_str());
            system("leaks ReplaceString");
            return 1;
        }
        writeline.assign(readline);
        writeline.replace(destString, srcString);
        fout << writeline.value();
        if (!fin.eof())
            fout << '\n';
        readline.clear();
    }
    system("leaks ReplaceString");
    return 0;
}
