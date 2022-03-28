/*
** EPITECH PROJECT, 2021
** Save
** File description:
** hpp
*/

#ifndef CHECKFILES_HPP_
#define CHECKFILES_HPP_

#include <raylib.h>
#include <string.h>
#include <iostream>
#include <fstream>

class CheckFiles {
    public:
        CheckFiles();
        ~CheckFiles();
        int Check(std::string sources[], int nb_files);

    protected:
    private:

};

#endif /* !CHECKFILES_HPP_ */
