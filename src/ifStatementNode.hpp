#include "abstractSyntaxTree.hpp"

class Statement {

};

class ifStatementNode final : public ASTNode {
protected:
    Statement left_statement; 
    Statement right_statement;

    ASTNode* result_true;
    ASTNode* result_false;
};