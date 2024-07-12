//
// Created by Flowey on 13/07/2024.
//

#ifndef ROUTING_H
#define ROUTING_H

#define ROUTES_DIR "Pages"

#include "../../Common/Common.h"

using namespace CommonRoute;

class RoutingBase {
public:
    RoutingBase();

    void AddRoute(const Route *route) { return this-> routes.push_back(*route); }
    vector<Route> GetRoutes() { return this->routes; }

    
private:
    std::vector<Route> routes;
    
};



#endif //ROUTING_H
