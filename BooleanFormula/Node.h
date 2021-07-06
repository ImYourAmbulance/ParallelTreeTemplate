#pragma once
class Node {
public:
	Node* left;
	Node* right;
	virtual bool Calculate(bool* arr) = 0;
	Node(): left(nullptr), right(nullptr) {}
};

class NodeVar : public Node {
public:
	bool negation;
	int index;
	bool Calculate(bool* arr) override;

};

class NodeConj : public Node {
public:
	bool Calculate(bool* arr) override;
};

class NodeDisj : public Node {
public:
	bool Calculate(bool* arr) override;
};