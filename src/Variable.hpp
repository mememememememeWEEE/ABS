#include "BasicTypes.hpp"
#include <type_traits>

template<typename T> 
concept _cvar = std::is_base_of_v<basicType, T>;
template <_cvar VarType>
class Variable {
    VarType value;
    bool isConstant;
};