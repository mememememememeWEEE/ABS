#pragma once
#include <iostream>
#include <vector>

#include "ASTNode.hpp"

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
