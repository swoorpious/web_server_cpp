//
// Created by Flowey on 17/07/2024.
//

#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include <vector>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>


using namespace std;

enum EParseMethods {
    FileName,        // Just the name of the file without extension
    FileNameWithExt, // Name of the file with extension
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
        // s = regex_replace(PATH, regex(R"(([^\\/]+)(?=\.[^\\/]+$))"), "");
        s = regex_search(PATH, match, regex( R"(([^\\/]+)(?=\.[^\\/]+$))")) ? match[1].str() : "";
        return s;
        

    case FileNameWithExt:
        // [^\\/]+$
        s = regex_search(PATH, match, regex(R"([^\\/]+$)")) ? match[1].str() : "";
        return s;

    case CanonicalPath:
        s = filesystem::canonical(PATH).string();
        return !s.empty() ? s : "";    // PATH has to be canonical lol

    case RelativePath:
        s = filesystem::relative(PATH, RELATIVE_TO).string();
        return !s.empty() ? s : "";

    case DirectoryPath:
        s = filesystem::path(PATH).parent_path().string();
        return !s.empty() ? s : "";

    default:
        return filesystem::path(PATH).string();
    }
}

inline vector<string> GetFilesInDir(const string &path) {
    try {
        // const string dir_path = ParseFilename(path, DirectoryPath);
        vector<string> files;
        for (auto &entry : filesystem::directory_iterator(path)) {
            // const string l = ParseFilename(entry.path().string(), FileName);
            files.push_back(entry.path().string());
        }
        
        return /*RETURN_TO =*/ files;
    } catch (const filesystem::filesystem_error &e) {
        throw e.what();
    }
}

inline string ReadFile(const string& PATH) { // canonical path
    // if (filesystem::exists(PATH) || filesystem::is_regular_file(PATH))
    //     throw runtime_error("File does not exist or is not a regular file:" + PATH);
    //
    // vector<char> buffer(filesystem::file_size(PATH));
    // std::ifstream file(PATH, std::ios::binary);
    //
    // if (file.read(buffer.data(), buffer.size())) {
    //     return string(buffer.data(), buffer.size());
    // }
    //
    // throw std::runtime_error("Failed to read the file: " + PATH);


    std::ifstream file(PATH);
    if (!file) {
        throw std::runtime_error("Could not open file: " + PATH);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

#endif //FILEFUNCTIONS_H
