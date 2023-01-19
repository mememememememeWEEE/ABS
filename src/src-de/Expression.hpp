#include <memory>

template<typename T, typename S> 
class Expression {
protected:
	size_t num_operands;
	size_t num_operators;
	std::unique_ptr<T> operands;
	std::unique_ptr<S> operators;
public:
	Expression(size_t num_operands, size_t num_operators, 
	T* operands, S* operators) {
        //this is inheriently unsafe, but it exists
		this->num_operands = num_operands;
		this->num_operators = num_operators;
        this->operands = std::make_unique(operands);
        this->operators = std::make_unique(operators);
	}
};