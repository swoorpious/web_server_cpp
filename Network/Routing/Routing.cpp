//
// Created by Flowey on 13/07/2024.
//

#include "Routing.h"
#include <filesystem>
#include <regex>
#include <sstream>

using namespace std;

RoutingBase::RoutingBase() {
    AddInitialRoutes();
}

Route RoutingBase::GetRoute(string &URL) {
    if (URL.empty())
        return Route(&URL, &ROUTE_NOT_FOUND, "GET");


    // for Pages
    // TODO: rewrite a better and more understandable code for this
    auto it = std::find_if(routes.begin(), routes.end(), [&URL](const Route &route) {
        return URL == route.ROUTE;
    });
        
    if (it != routes.end()) {
        return *it;
    }

    // resolve filename
    // see if URL matches any dir/file in WEBSITE_DIR
    try {
        string req = ParseFilename(WEBSITE_DIR + "\\" + URL, CanonicalPath);
        if (req.empty()) return Route();

        if (std::filesystem::is_regular_file(req)) {
            return Route(&URL, &req, "GET");
        }
    } catch (const exception &e) {
        // return Route(&URL, &ROUTE_NOT_FOUND, "GET");
    }

    return Route(&URL, &ROUTE_NOT_FOUND, "GET");


}

Route RoutingBase::ParseRequest(const char * REQUEST) {
    if (REQUEST == nullptr)
        return Route();

    const string req(REQUEST);
    istringstream iss(req);
    string METHOD, URL;
    iss >> METHOD >> URL;

    Route route;

    if (METHOD == "GET") {
        route = ParseGetRequest(URL);
    }

    return route;
}

void RoutingBase::AddInitialRoutes() {
    vector<string> files = GetFilesInDir(ROUTES_DIR);

    for (const string file : files) {        
        string FILENAME = "/" + ParseFilename(file, Path, ROUTES_DIR);
        string FILEPATH = ParseFilename(file, CanonicalPath);
        
        const Route s(&FILENAME, &FILEPATH, "GET");
        if (EndsWith(FILENAME, "/index")) {
            string j = FILENAME.substr(0, FILENAME.size() - 5);
            const Route r(&j, &FILEPATH, "GET");
            AddRoute(&r);
            continue;
        }

        // do not add a 404 route
        // instead use it as a fallback
        if (FILENAME == "/404") {
            ROUTE_NOT_FOUND = FILEPATH;
            continue;
        }
        
        AddRoute(&s);
    }
}


Route RoutingBase::ParseGetRequest(string& routeName) {
    // c'mon do something
    if (&routeName == nullptr)
        return Route();

    return GetRoute(routeName);
    
}

