#include <cstdint>
#include <any>

enum IntegralTypes {
    INTEGRAL_REAL,
    INTEGRAL_INTEGER,
    INTEGRAL_FLOAT32,
    INTEGRAL_FLOAT64,
};

class basicType {};

template<typename T>
class StaticType : public basicType {
	bool initialized = false;
	T value;
};

class dynamicType : public basicType {
	bool initialized = false;
	std::any value;
};

template<typename T> 
class INTEGRAL : StaticType<T> {};

class INTEGRAL_INTEGER : public INTEGRAL<int64_t> {};
class INTEGRAL_FLOAT32 : public INTEGRAL<float> {};
class INTEGRAL_FLOAT64 : public INTEGRAL<double> {};

