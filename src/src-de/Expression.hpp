#include <vector>

template<typename T, typename S> 
class Expression {
protected:
	size_t num_operands;
	size_t num_operators;
	std::vector<T> operands;
	std::vector<S> operators;
public:
	Expression(const size_t& num_operands, const size_t& num_operators, 
    //this is inheriently unsafe, but it exists
	std::vector<T> operands, std::vector<S> operators) {
		this->num_operands = num_operands;
		this->num_operators = num_operators;
		this->operands = operands;
		this->operators = operators;
	}
};
