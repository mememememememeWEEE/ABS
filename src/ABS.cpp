#include <stdio.h>
#include <vector>																	
#include <type_traits>

#include "basicCommonIntegralTypes.h"

enum basicIntegralBinaryOperations {
	ADDITION,
	SUBTRACTION,
	MULTIPLACATION,
	DIVISION,
	REMAINDER,
};

class ASTNode {
protected:
	ASTNode* parent;
	std::vector<ASTNode*> children;

public:
	const char* name;
	friend class AST;
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
	basicIntegralBinaryExpression() {};
};

class AST final {
protected:
	std::vector<ASTNode> nodes;
	
	static void printNode(const ASTNode& node, const unsigned int& indent) {
		if (node.children.size() == 0) {
			printf("|");
			for (unsigned int i = 0; i < indent; i++) printf("-");
			printf("%s\n", node.name);
		}
	}

	void _printSummary(const ASTNode& node, unsigned int indent) const {
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
	AST(std::vector<ASTNode> nodes) {
		this->nodes = nodes;
	}

	void printSummary() {
		for (const auto& node : this->nodes) {
			_printSummary(node, 0);
		}
	}
};


int main(void) {
	basicIntegralBinaryExpression<FLOAT32, ADDITION> is;
	AST ast{{is}};
	ast.printSummary();
	return 0;
}

