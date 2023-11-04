/**
 * @file UI.h
 * @brief Header file for the UI class, the user interface of a scheduling application.
 */

#ifndef PROJETO_UI_H
#define PROJETO_UI_H

#include "stdafx.h"
#include "Schedule.h"
#include "Restoring.h"

/**
 * @class UI
 * @brief Represents the user interface for a scheduling application.
 */
class UI {
public:
    /**
     * @brief Default constructor for the UI class.
     */
    UI();

    /**
     * @brief Displays the main menu and handles user interactions.
     */
    void menu_start();

    /**
     * @brief Static function for clearing the screen.
     */
    static void clear_screen();

    /**
     * @brief Displays the main options menu for the application.
     */
    void menu_options();

    /**
     * @brief Displays the schedule-related menu and allows users to interact with schedules.
     */
    void menu_schedule();

    /**
     * @brief Performs loading operations for UI and related components.
     * @param ui A reference to the UI object.
     */
    void loading_stuff(UI& ui);

    /**
     * @brief Displays the menu for managing students.
     */
    void menu_students();

    /**
     * @brief Displays the menu for managing students in specific UCs.
     */
    void menu_studentsInNucs();

    /**
     * @brief Displays the menu for managing occupation-related data.
     */
    void menu_occupation();

    /**
     * @brief Displays and manages user requests for changes.
     */
    void menu_requests();

    /**
     * @brief Processes user requests for changes based on a given list of requests.
     * @param requests_ A list of variant objects representing requests.
     */
    void process_requests(std::vector<std::variant<Student, UC, char>> requests_);

    /**
     * @brief Placeholder for a method named requests_ (Note: The method name contains a trailing underscore).
     */
    void requests_();

    /**
     * @brief Saves global alterations made to the scheduling application.
     */
    void save_global_alterations();

    /**
     * @brief Restores previous changes made to the scheduling application.
     */
    void restore_changes();

    /**
     * @brief Validates user input within a specified range.
     * @param op A character variable to validate.
     * @param lower_bound The lower bound of the valid range.
     * @param upper_bound The upper bound of the valid range.
     * @return true if the input is valid, false otherwise.
     */
    bool validate_input(char &op, const char lower_bound, const char upper_bound);

private:
    // Private Data Members

    Schedule mySchedule;  /**< Represents the scheduling system. */
    std::vector<Student> students; /**< A collection of student data. */
    std::vector<Class> classes; /**< A collection of class data. */
    std::vector<UC> ucs; /**< A collection of UC (University Course) data. */
    std::vector<Schedule> schedules; /**< A collection of schedules. */
    std::pair<std::unordered_map<std::string, unordered_set<std::string>>, std::unordered_map<std::pair<std::string, std::string>, int, PairHash>> AttendancePair; /**< Represents attendance data. */
    bool ChangesMade = false; /**< Flag to track whether changes have been made. */
    Restoring restore; /**< Handles restoration of changes. */
    std::vector<Restoring> restore_value; /**< Maintains a history of restoration points. */
    std::list<std::vector<std::variant<Student, UC, char>>> requests; /**< A list of user requests for changes. */
};

#endif // PROJETO_UI_H
