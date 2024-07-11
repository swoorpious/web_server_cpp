//
// Created by Flowey on 12/07/2024.
//

// https://www.geeksforgeeks.org/routing-tables-in-computer-network/

#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>

namespace Routing {
    struct Route {
        std::string ROUTE;                            // destination name
        std::string (*RESPONSE)(const std::string &); // takes in std::string& request
    };

    struct Query { };
}


#endif //ROUTE_H
