#ifndef RADIO_RELAY_EXCEPTIONS_H
#define RADIO_RELAY_EXCEPTIONS_H

#include <exception>
#include <string>

// Base exception class for RadioRelay hierarchy
class RelayException : public std::exception {
protected:
    std::string m_message;

public:
    explicit RelayException(const std::string& message) : m_message(message) {}
    virtual ~RelayException() noexcept override = default;

    virtual const char* what() const noexcept override {
        return m_message.c_str();
    }
};

// Exception for invalid input/validation values
class InvalidDataException : public RelayException {
public:
    explicit InvalidDataException(const std::string& details)
        : RelayException("InvalidDataException: " + details) {}
};

// Exception for file stream errors
class FileException : public RelayException {
public:
    explicit FileException(const std::string& details)
        : RelayException("FileException: " + details) {}
};

// Exception for array bounds errors
class IndexOutOfBoundsException : public RelayException {
public:
    explicit IndexOutOfBoundsException(size_t index, size_t size)
        : RelayException("IndexOutOfBoundsException: index " + std::to_string(index) +
                         " is out of bounds for size " + std::to_string(size)) {}
};

#endif // RADIO_RELAY_EXCEPTIONS_H
