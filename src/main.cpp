////////////////////////////////////////////////////////////////////////////////
// Module Name: main.cpp
// Authors: Leonid Dworzanski, Sergey Shershakov
// Version: 0.2.0
// Date: 06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures"
// provided by the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "dna_element.h"
#include "linked_list.h"

using namespace std;
using namespace xi;
//static const char* INP_FILENAME = "../../res/test5.in";

int main (int argc, char* argv[])
{
    LinkedList<int> list;
    int inserted_element = 2;
    int a = 3;
    list.addElementToEnd(inserted_element);
    list.addElementToEnd(a);
    cout <<list[1]<<endl;


    return 0;
}