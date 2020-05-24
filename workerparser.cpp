#include <fstream>
#include <string>

#include "workerparser.h"

void WorkerParser::parse() {
    std::string tipo_trabajador;
    std::string cantidad;
    do {
        std::getline(stream, tipo_trabajador, DELIMITER);
        std::getline(stream, cantidad);
        quantities[tipo_trabajador] = std::stoi(cantidad);
    } while (!tipo_trabajador.empty()); 
}

size_t WorkerParser::get_quantity(const std::string type) const {
	// const std::string type -> copia, usar move
    return quantities.at(type);
}
