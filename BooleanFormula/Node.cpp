#include "Node.h"


bool NodeVar::Calculate(bool* arr) {
	return arr[index];
}
bool NodeConj::Calculate(bool* arr) {
	return (((left != nullptr) ? left->Calculate(arr) : 1) && ((right != nullptr) ? right->Calculate(arr) : 1));
}
bool NodeDisj::Calculate(bool* arr) {
	return (((left != nullptr) ? left->Calculate(arr) : 0) || ((right != nullptr) ? right->Calculate(arr) : 0));
}