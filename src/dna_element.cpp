////////////////////////////////////////////////////////////////////////////////
// Module Name:  dna_repairer.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "dna_element.h"
#include <climits>

// TODO: implement
DNAElement::DNAElement()
{

}

DNAElement::DNAElement(const std::string &description)
{
    readFromString(description);
}

void DNAElement::readFromString(const std::string &description)
{
    if (description[0] >= 'a' and description[0] <= 'z')
        id = description[0];
    else
        throw std::invalid_argument("readFS");
    if (std::stoi(description.substr(1, description.size() - 3)) > 0)
    {
        try
        {
            number = std::stoi(description.substr(1, description.size() - 3));
        }
        catch (std::out_of_range e)
        {
            throw std::invalid_argument("kostil");
        }
    } else
        throw std::invalid_argument("readFS");
    char buff = description[description.size() - 1];
    if (buff == 'A' || buff == 'C' || buff == 'G' || buff == 'T')
        base = buff;
    else
        throw std::invalid_argument("readFS");

}
