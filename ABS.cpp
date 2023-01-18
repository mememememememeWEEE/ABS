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
	basicIntegralBinaryOperations type;	
	OperationType left_value;
	OperationType right_value;
};

class AST final {
private:
	std::vector<ASTNode> nodes;
	
	const static void printNode(const ASTNode& node, unsigned int indent) {
		if (node.children.size() == 0) {
			printf("|");
			for (int i = 0; i < indent; i++) printf("-");
			printf("%s\n", node.name);
		}
	}

public:
	void printSummary() const {
		int indent = 0;
		for (auto node : nodes) {
			printNode(node, 0);
		}
	}
};


int main(void) {
	printf("UWU\n");
	return 0;
}

