#include "LoadFIles.h"
/**
 * @class LoadFiles
 * @brief A class for loading data from CSV files.
 */


/**
     * @brief Loads the respective classes for Ucs of a given Student from a CSV file.
     * @param students The vector of Student objects to be populated.
     * @param AttendencePair The map for attendance data.
     */
void LoadFiles::Load_Student_Classes(std::vector<Student>& students , std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>>& AttendencePair) {
    bool skip_first = true;
    std::unordered_set<int> visited;
    std::vector<pair<std::string , std::string>> classes_to_ucs_;

    std::ifstream file("schedule/students_classes.csv");

    if (!file.is_open()) {
        std::cerr << "Failed to open the CSV file." << std::endl;
    }

    std::string line;
    getline(file, line);

    Student currentStudent;

    while (getline(file, line)) {
        std::istringstream lineStream(line);
        std::vector<std::string> tokens;
        std::string token;

        while (getline(lineStream, token, ',')) {
            tokens.push_back(token);
        }

        int studentId = std::stoi(tokens[0]);
        std::string studentName = tokens[1];
        std::string ucCode = tokens[2];
        std::string classCode = tokens[3];
        NormaliseString(classCode);

        if(AttendencePair.first.find(classCode) != AttendencePair.first.end())
        {
            AttendencePair.first[classCode].insert(studentName);
        }
        else
        {
            AttendencePair.first[classCode] = {studentName};
        }

        if(AttendencePair.second.find(make_pair(ucCode , classCode)) != AttendencePair.second.end())
        {
            AttendencePair.second[make_pair(ucCode , classCode)] += 1;
        }
        else
        {
            AttendencePair.second[make_pair(ucCode , classCode)] = 0;
        }

        if (skip_first) {
            skip_first = false;
            currentStudent.setId(studentId);
            currentStudent.setName(studentName);
            classes_to_ucs_.push_back(std::make_pair(classCode , ucCode));
        }

        if (visited.find(studentId) == visited.end()) {
            // This is a new student, add the currentStudent to the result and reset
            currentStudent.setClassesToUcs(classes_to_ucs_);
            students.push_back(currentStudent);

            // Create a new student
            currentStudent = Student();
            currentStudent.setId(studentId);
            currentStudent.setName(studentName);
            visited.insert(studentId);
            classes_to_ucs_.clear();
            classes_to_ucs_.push_back(std::make_pair(classCode , ucCode));
        }
        else
        {
            // Add class-UC pairs to the current student
            classes_to_ucs_.push_back(std::make_pair(classCode , ucCode));
        }

    }

    // Add the last student
    currentStudent.setClassesToUcs(classes_to_ucs_);
    students.push_back(currentStudent);

    file.close();
}

/**
     * @brief Loads all the classes available for each UC.
     * @param classes The vector of Class objects to be populated.
     */
void LoadFiles::Load_Classes_Per_Uc(std::vector<Class> &classes)
{
    bool skip_header = true;
    Class class_;
    std::string uc;
    std::vector<std::string> ucs;
    std::unordered_map<std::string , std::vector<std::string>> visited;

    std::vector<Class> Result;

    std::ifstream file("schedule/classes_per_uc.csv");

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

/**
     * @brief Loads the Date of each class for every UC.
     * @param ucs The vector of UC objects to be populated.
     */
void LoadFiles::Load_Uc(std::vector<UC> &ucs)
{
    bool skip_header = true;

    std::ifstream file("schedule/classes.csv");

    if (!file.is_open()) {
        std::cerr << "Failed to open the CSV file." << std::endl;
    }
    std::string line;
    while (getline(file, line)) {
        vector<std::string> values;
        std::string value;
        std::istringstream iss(line);

        if(skip_header)
        {
            skip_header = false;
            continue;
        }

        while (getline(iss, value, ',')) {
            values.push_back(static_cast<string>(value));
        }

        string temp = values[5];
        NormaliseString(temp);
        Date dateObject;
        dateObject.Day = values[2];
        dateObject.Duration.first = std::stod(values[3]);
        dateObject.Duration.second = std::stod(values[4]) + dateObject.Duration.first;
        UC uc(values[1], temp, values[0] , 0 , dateObject);
        ucs.push_back(uc);
    }
}

/**
     * @brief Normalizes a string by removing the '\r' character, solving issues in the previous loader functions.
     * @param str The string to be normalized.
     */
void LoadFiles::NormaliseString(std::string &str)
{
    size_t pos = str.find('\r');
    if (pos != std::string::npos) {
        str.erase(pos);
    }
}