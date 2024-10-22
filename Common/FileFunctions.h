//
// Created by Flowey on 17/07/2024.
//

#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include "Common.h"
#include <vector>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

enum EParseMethods {
    FileName,        // Just the name of the file without extension
    Path,            // Relative path without extension
    CanonicalPath,   // Canonical path of the file
    RelativePath,    // Relative path of the file
    FileExt,         // Only the file extension
    DirectoryPath    // Directory path containing the file
};

inline string ParseFilename(const string &PATH, EParseMethods METHOD, const string &RELATIVE_TO = "") {
    string s;
    smatch match;
    switch (METHOD) {
    case FileName:
        // ([^\\/]+)(?=\.[^\\/]+$)
            
        s = regex_search(PATH, match, regex( R"(([^\\/]+)(?=\.[^\\/]+$))")) ? match[0].str() : "";
        return s;
        

    case Path:
        // [^\\/]+$ — for file name with path
        // s = regex_search(PATH, match, regex(R"([^\\/]+$)")) ? match[1].str() : "";
        // return s;

        //[^/]+/[^/]+(?=\.[^.]+$)   

        if (!RELATIVE_TO.empty()) {
            string c = ParseFilename(PATH, RelativePath, RELATIVE_TO);
            string j = regex_replace(c, regex(R"(\\)"), "/");
            
            s = regex_replace(j, regex(R"(\.[^\\/]+$)"), "");
            return s;
        }

        return ParseFilename(PATH, FileName);
            

    case CanonicalPath:
        s = filesystem::canonical(PATH).string();
        return !s.empty() ? s : "";

    case RelativePath:
        s = filesystem::relative(PATH, RELATIVE_TO).string();
        return !s.empty() ? s : "";

    case FileExt:
        // \.\w+$
        s = regex_search(PATH, match, regex(R"(\.\w+$)")) ? match.str() : "";
        return s;

    default:
        return filesystem::path(PATH).string();
    }
}

inline vector<string> GetFilesInDir(const string &path) {
    std::vector<std::string> files;

    try {
        std::vector<filesystem::path> directories{path};

        while (!directories.empty()) {
            filesystem::path currentDir = directories.back();
            directories.pop_back();

            for (const auto &entry : filesystem::directory_iterator(currentDir)) {
                if (entry.is_directory()) {
                    directories.push_back(entry.path());
                }
                else if (entry.is_regular_file()) {
                    files.push_back(entry.path().string());
                }
            }
        }
    } catch (const filesystem::filesystem_error &e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        throw; // Re-throw the exception
    }

    return files;
}

inline string GetFileType(const string &PATH) {
    string Type = ParseFilename(PATH, FileExt);

    if (CommonNetwork::ContentTypes.contains(Type)) {
        return CommonNetwork::ContentTypes[Type];
    }

    return "application/octet-stream";
}


inline string ReadFile(const string& PATH) { // canonical path
    if (!filesystem::exists(PATH) || !filesystem::is_regular_file(PATH))
        throw runtime_error("File does not exist or is not a regular file: " + PATH);

    string contentType = GetFileType(PATH);
    ifstream file;

    if (contentType.find("text/") != 0) {
        file.open(PATH, ios::binary);
    }
    else {
        file.open(PATH);
    }

    if (!file) throw runtime_error("Could not open file: " + PATH);

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

inline bool EndsWith(const std::string &str, const std::string &suffix) {
    if (suffix.length() > str.length()) return false;
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

#endif //FILEFUNCTIONS_H
