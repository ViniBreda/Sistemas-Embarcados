#ifndef SHEET__CPP
#define SHEET__CPP

#include <iostream>
#include <array>
#include <stdlib.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
// #include <Python.h>
#include <algorithm>

std::vector<std::string> exec_int(const char* cmd);
std::vector<std::string> get_sheet(std::string sheet_id, std::string range);

#endif