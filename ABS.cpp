#include <stdio.h>
#include <vector>

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

template<typename OperationType>
class basicIntegralBinaryExpression : public ASTNode {
protected:
	basicIntegralBinaryOperations type;	
	OperationType left_value;
	OperationType right_value;
public:
	basicIntegralBinaryExpression(const basicIntegralBinaryOperations type) {
		this.type = type;
	}
};

class AST final {
protected:
	std::vector<ASTNode> nodes;
	
	const static void printNode(const ASTNode& node, unsigned int indent) {
		if (node.children.size() == 0) {
			printf("|");
			for (int i = 0; i < indent; i++) printf("-");
			printf("%s\n", node.name);
		}
	}

	const void _printSummary(const ASTNode& node, unsigned int indent) {
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
		int indent = 0;
		for (const auto& node : this->nodes) {
			_printSummary(node, 0);
		}
	}
};


int main(void) {
	basicIntegralBinaryExpression<int> is{ADDITION};
	AST ast{{is}};
	printf("UWU\n");
	return 0;
}

