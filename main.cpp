#include <iostream>
#include <unordered_map>

#include "inventory.h"
#include "resource.h"
#include "thread.h"
#include "blockingqueue.h"
#include "recolector.h"
#include "producer.h"
#include "profitpointscounter.h"
#include "recolectorhandler.h"
#include "producerhandler.h"
#include "mapparser.h"
#include "workerparser.h"

#define WORKERS_FILE_INDEX 1
#define MAP_FILE_INDEX 2

#define ERROR 1

int main(int argc, const char** argv) {
    Inventory inventario;

    RecolectorHandler agricultores(inventario);
    RecolectorHandler leniadores(inventario);
    RecolectorHandler mineros(inventario);

    std::unordered_map<std::string, RecolectorHandler*> recolectores {
        { "Agricultores", &agricultores },
        { "Leniadores", &leniadores },
        { "Mineros", &mineros }
    };

    std::unordered_map<Resource, RecolectorHandler*> recolectores_por_recurso {
        { Resource::Trigo, &agricultores },
        { Resource::Madera, &leniadores },
        { Resource::Carbon, &mineros },
        { Resource::Hierro, &mineros }
    };

    // ProducerHandler cocineros(inventario);
    // ProducerHandler carpinteros(inventario);
    // ProducerHandler armeros(inventario);

    // std::unordered_map<std::string, ProducerHandler*> productores {
    //     { "Cocineros", &cocineros },
    //     { "Carpinteros", &carpinteros },
    //     { "Armeros", &armeros }
    // };

    std::ifstream stream_worker(argv[WORKERS_FILE_INDEX], std::ios::in);
    if (!stream_worker.is_open()) {
        std::cerr << "No se pudo abrir el archivo de trabajadores" << std::endl;
        return ERROR;
    }
    
    WorkerParser worker_parser(stream_worker);
    worker_parser.parse();
    
    for (auto& recolector: recolectores) {
        size_t cantidad = worker_parser.get_quantity(recolector.first);
        recolector.second->create_recolecotors(cantidad);
    }
    
    // for (auto& productor: productores) {
    //     size_t cantidad = worker_parser.get_quantity(productor.first);
    //     productor.second->create_producers(cantidad);
    // }

    std::ifstream stream_mapa(argv[MAP_FILE_INDEX], std::ios::in);
    if (!stream_mapa.is_open()) {
        std::cerr << "No se pudo abrir el archivo de mapa" << std::endl;
        return ERROR;
    }
   
    MapParser map_parser(stream_mapa);
    map_parser.parse(recolectores_por_recurso);

    for (auto& recolector: recolectores_por_recurso) {
        recolector.second->queue_done();
    }

    // for (auto& productor: productores) {
    //     productor.second->join();
    // }

    for (auto& recolector: recolectores) {
        recolector.second->join();
    }
    
    inventario.show();
}
