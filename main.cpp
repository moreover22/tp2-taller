#include <iostream>
#include <string>

#include "inventory.h"
#include "profitpointscounter.h"
#include "resource.h"
#include "gathererhandler.h"
#include "producerhandler.h"
#include "mapparser.h"
#include "workerparser.h"

#define WORKERS_FILE_INDEX 1
#define MAP_FILE_INDEX 2

#define ERROR 1
#define SUCCESS 0

bool parse_workers(const char * path_file, GathererHandler& gatherers, 
                                                ProducerHandler& producers) {
    std::ifstream stream_worker(path_file, std::ios::in);
    if (!stream_worker.is_open())
        return false;
    WorkerParser worker_parser(stream_worker);
    worker_parser.parse();    
    gatherers.create_gatherers(worker_parser);
    producers.create_producers(worker_parser);
    return true;
}

bool parse_map(const char * path_file, GathererHandler& gatherers) {    
    std::ifstream stream_mapa(path_file, std::ios::in);
    if (!stream_mapa.is_open()) 
        return false;
    MapParser map_parser(stream_mapa);
    map_parser.parse(gatherers);
    return true;
}

int main(int argc, const char** argv) {
    Inventory inventory;
    ProfitPointsCounter pp_counter;
    GathererHandler gatherers(inventory);
    ProducerHandler producers(inventory, pp_counter);
    
    if (!parse_workers(argv[WORKERS_FILE_INDEX], gatherers, producers)) {
        std::cerr << "No se pudo abrir el archivo de trabajadores" << std::endl;
        return ERROR;
    }

    if (!parse_map(argv[MAP_FILE_INDEX], gatherers)) {
        std::cerr << "No se pudo abrir el archivo de mapa" << std::endl;
        return ERROR;
    }
    gatherers.join();
    inventory.close();
    producers.join();
    inventory.show();
    printf("\n");
    pp_counter.show();
    return SUCCESS;
}
