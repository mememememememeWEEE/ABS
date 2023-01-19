#pragma once

enum basicIntegralBinaryOperations {
	ADDITION,
	SUBTRACTION,
	MULTIPLACATION,
	DIVISION,
	REMAINDER,
};

class basicCommonIntegralType {
public:
};

class INTEGER final : public basicCommonIntegralType {
public:
    long long value;
    INTEGER() {}

    INTEGER(const long long& value) {
        this->value = value;
    }

    INTEGER& operator=(const long long&& value) noexcept {
        if (this->value == value) return *this;
        else this->value = value;
    }
};

class FLOAT32 final : public basicCommonIntegralType {
public:
    float value;
    FLOAT32() {};

    FLOAT32(const float& value) {
        this->value = value;
    }

    FLOAT32& operator=(const long long&& value) noexcept {
        if (this->value == value) return *this;
        else this->value = value;
    }
};

class FLOAT64 final : public basicCommonIntegralType {
public:
    double value;
    FLOAT64() {};

    FLOAT64(const double& value) {
        this->value = value;
    }

    FLOAT64& operator=(const long long&& value) noexcept {
        if (this->value == value) return *this;
        else this->value = value;
    }
};

