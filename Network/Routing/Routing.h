//
// Created by Flowey on 13/07/2024.
//

#ifndef ROUTING_H
#define ROUTING_H

// #define ROUTES_DIR "X:/Projects/web_server_cpp/Website/Pages"
#define ROUTES_DIR "..\\Website\\Pages"

#include "../../Common/Common.h"

using namespace CommonRoute;

class RoutingBase {
public:
    RoutingBase();

    void AddRoute(const Route *route) { return this->routes.push_back(*route); }
    vector<Route> GetRoutes() { return this->routes; }

    
    void AddRoutes (const vector<Route> &routes) { this->routes = routes; }
    void AddInitialRoutes();
    
protected:
    static vector<string> GetFilesInDir(const string &path);
    static string ParseFilename();
    static void ParseRequest() {}

private:
    std::vector<Route> routes;
    
};



#endif //ROUTING_H
