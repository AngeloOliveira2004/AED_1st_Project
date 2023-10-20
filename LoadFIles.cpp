//
// Created by jose-costa on 10/20/23.
//

#include "LoadFIles.h"

void LoadFIles::Load_Student_Classes(std::vector<Student> &students)
{

}


void LoadFIles::Load_Classes_Per_Uc(std::vector<Class> &classes)
{
    bool skip_header = true;
    Class class_;
    std::string uc;
    std::vector<std::string> ucs;
    std::unordered_map<std::string , std::vector<std::string>> visited;

    std::vector<Class> Result;

    std::ifstream file("/home/jose-costa/Documents/Uni/AED/Projeto/schedule/classes_per_uc.csv");

    if (!file.is_open())
    {
        std::cerr << "Failed to open the CSV file." << std::endl;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream lineStream(line);
        std::vector<std::string> tokens;
        std::string token;

        if(skip_header)
        {
            skip_header = false;
            continue;
        }
        while (getline(lineStream, token, ',')) {
            tokens.push_back(static_cast<string>(token));
        }

        ucs.push_back(tokens[0]);
        string className = tokens[1];
        NormaliseString(className);

        auto it = visited.find(className);

        if(it != visited.end())
        {
            visited[className].push_back(tokens[0]);
        }
        else
        {
            visited[className] = {tokens[0]};
        }
    }
    file.close();

    for(const auto& pair : visited)
    {
        class_.setClassCode(pair.first);
        class_.setUCs(pair.second);
        Result.push_back(class_);
    }

    classes = Result;
}

void LoadFIles::Load_Uc(std::vector<UC> &ucs)
{

}

void LoadFIles::NormaliseString(std::string &str)
{
   size_t pos = str.find('\r');
    // Check if '\r' was found
    if (pos != std::string::npos) {
        // Erase the '\r' and everything after it
        str.erase(pos);
    }
}