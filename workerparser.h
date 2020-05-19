#ifndef WORKERPARSER_H
#define WORKERPARSER_H

#include <unordered_map>
#include <string>

class WorkerParser {
private:
    const char DELIMITER = '=';
    std::unordered_map<std::string, size_t> quantities; 
    std::ifstream& stream;
public:
    explicit WorkerParser(std::ifstream& stream): stream(stream) {}
    void parse();
    size_t get_quantity(const std::string type) const;
};

#endif
