//
// Created by Flowey on 13/07/2024.
//

#include "Routing.h"
#include <filesystem>
#include <regex>

using namespace std;

RoutingBase::RoutingBase() {
    AddInitialRoutes();
}

void RoutingBase::AddInitialRoutes() {
    const vector<string> files = GetFilesInDir(ROUTES_DIR);
    
    for (const string file : files) {
        if (file == "index.html") {
            const Route s = Route();
            AddRoute(&s);

            continue;
        }
        
        regex pattern(R"((.*)\.html$)");
        string processedFilename = regex_replace(file, pattern, "$1");
        ranges::replace(processedFilename, '.', '_');

        Route s = Route("/" + processedFilename, file);
        AddRoute(&s);
    }
}

vector<string> RoutingBase::GetFilesInDir(const string &path) {
    try {
        vector<string> files;
        for (const auto& entry : filesystem::directory_iterator(path)) {
            const string l = canonical(entry.path()).string();
            files.push_back(l);
        }
    
        return files;
    } catch (const filesystem::filesystem_error& e) {
        throw e.what();
    }
}

string RoutingBase::ParseFilename() {
    return "";
}
