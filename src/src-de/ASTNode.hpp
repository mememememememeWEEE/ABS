#include <vector>
#include <string>

class ASTNode {
protected:
	ASTNode* parent;
	std::vector<ASTNode*> children;

public:
	std::string name;
	friend class AST;

	ASTNode() {this->children={};};
	virtual std::string getName() = 0;
};