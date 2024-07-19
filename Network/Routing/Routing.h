//
// Created by Flowey on 13/07/2024.
//

#ifndef ROUTING_H
#define ROUTING_H



#include "../../Common/Common.h"
#include "../../Common/FileFunctions.h"

using namespace CommonNetwork;

class RoutingBase {
public:
    RoutingBase();

    void AddRoute(const Route *route) { return this->routes.push_back(*route); }
    // void AddRoutes (const vector<Route> &routes) { this->routes = routes; }
    Route GetRoute(string &URL);

    Route ParseRequest(const char * REQUEST);

protected:
    void AddInitialRoutes();
    // static void ParseRequest() {}
    vector<Route> GetAllRoutes() { return this->routes; }
    Route ParseGetRequest(string& routeName);

    string ROUTES_DIR = "..\\Website\\Pages";
    string WEBSITE_DIR = "..\\Website";

    string ROUTE_NOT_FOUND;

private:
    std::vector<Route> routes;
    
};



#endif //ROUTING_H
