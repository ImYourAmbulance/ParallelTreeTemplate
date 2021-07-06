#include "functions.h"

void ProcessBinaryStrings(bool* arr_bool, int cur_ind, int size, Node* root, std::ofstream& result) {
	if (cur_ind == size) {
		root->Calculate(arr_bool) ? result << "Satisfiable" : result << "Not Satisfaible";
		result << std::endl;
	}
	else {
		arr_bool[cur_ind] = 0;
		ProcessBinaryStrings(arr_bool, cur_ind + 1, size, root, result);
		arr_bool[cur_ind] = 1;
		ProcessBinaryStrings(arr_bool, cur_ind + 1, size, root, result);
	}
}


Node* MakeBinaryTree(std::string str, int& var_cnt) {
	std::vector<Node*> stack;
	std::stringstream s(str);
	std::string tmp_str;
	
	var_cnt = 0;

	while (s >> tmp_str) {
		if ((tmp_str == "+") || (tmp_str == "*")) {
			NodeDisj* node_binary = new NodeDisj();
			node_binary->left = stack.back();
			stack.pop_back();
			node_binary->right = stack.back();
			stack.pop_back();
			
			stack.push_back(node_binary);
		}
		else if (tmp_str == "!") {
			s >> tmp_str;
			NodeVar* node_var = new NodeVar();
			node_var->negation = 1;
			node_var->index = std::stoi(tmp_str) - 1;
			stack.push_back(node_var);
			++var_cnt;
			
		} 
		else {
			NodeVar* node_var = new NodeVar();
			node_var->negation = 0;
			node_var->index = var_cnt;
			stack.push_back(node_var);
			++var_cnt;
		}
	} 
	return stack[0];
}


