#pragma once
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
void ProcessBinaryStrings(bool* arr_bool, int cur_ind, int size, Node* root, std::ofstream& result);

Node* MakeBinaryTree(std::string str, int& var_cnt);