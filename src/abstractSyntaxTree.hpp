#pragma once
#include <type_traits>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

#include "basicCommonIntegralTypes.hpp"

class ASTNode {
protected:
	ASTNode* parent;
	std::vector<ASTNode*> children;

public:
	std::string name;
	friend class AST;

	ASTNode() {this->children={};};
	virtual std::string getName() {return this->name;};
};

template<typename T>
concept _bcit = requires(T a) {
	{std::is_base_of_v<basicCommonIntegralType, T>};
};
template<_bcit elementType, basicIntegralBinaryOperations OperationType>
class basicIntegralBinaryExpression : public ASTNode {
protected:
	basicIntegralBinaryOperations type;	
	elementType left_value;
	elementType right_value;
public:
	basicIntegralBinaryExpression() {
		this->name = "BASIC_INTEGRAL_BINARY_OPERATION";
	};

//doesn't override
	std::string getName() override {
		return this->name + " " + nameOfBasicIntegralBinaryOperations(OperationType);
	}
};

class AST final {
protected:
	std::vector<ASTNode> nodes;
	
	static void printNode(ASTNode& node, const unsigned int& indent) {
		if (node.children.size() == 0) {
			std::cout << "|->|";
			for (unsigned int i = 0; i < indent; i++) std::cout << "->";
			std::cout << node.getName() << '\n';
		}
	}

	void _printSummary(ASTNode& node, unsigned int indent) const {
		if (node.children.size() == 0) {
			printNode(node, indent);
			return;
		} else {
			for (const auto& child : node.children) {
				_printSummary(*child, indent+1);
			}
		}
	}

public:
	const char* name; 

	AST(std::vector<ASTNode> nodes) {
		this->nodes = nodes;
	}

	void printSummary() {
		std::cout << "[AST-" << this->name << "]:\n";
		for (auto& node : this->nodes) {
			_printSummary(node, 0);
		}
	}
};
