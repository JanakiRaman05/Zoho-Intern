#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "notepad.pb.h"
#include "version.pb.h"
#include "Note pad Application.h"
#include "sha256.h"
std::string details[] = { "Added ","Remove","Update" };
#define Project_Location_detail  "C:\\Users\\janak\\Desktop\\ZOHO\\notepad\\Note pad Application\\Note pad Application\\list_of_projects\\";
int main()
{
    int ch, user_index = -1, count = 0, project_index = -1, line_number, change_count = 0, attempt;
    std::string login_id, line, location, project_name;
    char password[26];
    time_t my_time;
    users book;
    project_list proj_book;
    version_detail selected_version;
    // Main Menu 
Start:
    std::cout << "1.Login \t 2.Sign up \t 3.Exit  \n\nEnter the Option:- ";
    std::cin >> ch;
Main_menu:
    if (ch == 1)
    {
        // Logging in of Old User 
    log_id:
        attempt = 0;
    Safety:
        std::ifstream files_in;
        user_index = -1;
        // Retriving Old Files 
        files_in.open("List_Of_user.txt", std::ios_base::in | std::ios_base::binary);
        book.ParseFromIstream(&files_in);
        // If No User was Created
        if (book.bookuser_size() == 0) {
            std::cout << "\nNo Previous User Pls Sign up !!! ...";
            std::cout << "\n\nPress Enter to Continue.....";
            getch();
            ch = 2;
            goto Main_menu;
        }
        std::cout << "\nEnter the User Name : ";
        std::cin >> login_id;
        for (int i = 0; i < book.bookuser_size(); ++i) {
            const auto& person = book.bookuser(i);
            if (login_id == person.username()) {
                user_index = i;
                break;
            }
        }
        if (user_index == -1) {
            std::cout << "\n Wrong User Name !!! \n" << std::endl;
            goto log_id;
        }
        // Password Entry
    log_id_password:
        std::cout << "\nEnter the Password (Limit 25 characters) : ";
        for (count = 0;; ++count) {
            password[count] = getch();
            if (password[count] == '\r') {
                break;
            }
            std::cout << "*";
        }
        if (count > 24) {
            goto log_id_password;
        }
        password[count + 1] = '\0';
        // Loging in of User
        if (SHA256(password) == book.bookuser(user_index).password()) {
            std::cout << "\n\nLogged in Sucessfully !!! ";
            std::cout << "\n\nPress Enter to Continue.....";
            getch();
            files_in.close();
            goto Projects_Menu;
        }
        // Reverting to login page
        else {
            std::cout << " \n\nLog in Failed Try Again !!! " << std::endl;
            attempt = attempt + 1;
            if (attempt > 4) {
                std::cout << "\n\nLogin attempt Reached !!! ... Try Again Later !!! ... \n\n";
                std::exit(0);
            }
            goto Safety;
        }
    }
    else if (ch == 2) {
        // Sign of New User
        count = 0;
        std::string email, name, location;
    Rename_id:
        system("cls");
        std::cout << "Sign up Page : - \n\n";
        std::cout << "\nEnter the User Name :- ";
        std::cin >> login_id;
        std::ifstream files_in;
        files_in.open("List_Of_user.txt", std::ios_base::in | std::ios_base::binary);
        book.ParseFromIstream(&files_in);
        for (int i = 0; i < book.bookuser_size(); ++i) {
            const auto& person = book.bookuser(i);
            if (login_id == person.username()) {
                std::cout << "User Name Aready exist ";
                goto Rename_id;
            }
            count += 1;
        }
        files_in.close();
        // Password Management 
    sign_id_password:
        std::cout << "Enter the Password (Limit 25 characters) :- ";
        for (attempt = 0;; ++attempt) {
            password[attempt] = getch();
            if (password[attempt] == '\r') {
                break;
            }
            std::cout << "*";
        }
        if (attempt > 24) {
            std::cout << "\nPassword Limit Reached !!! ... Reset Password \n";
            goto sign_id_password;
        }
        password[attempt + 1] = '\0';
        // Details Of New User
        std::cout << "\nEnter the Name Of User :- ";
        std::cin >> name;
        std::cout << "Enter the Email :- ";
        std::cin >> email;
        std::cout << "Enter the location :- ";
        std::cin >> location;
        // Stroring New User Details 
        user* new_user = book.add_bookuser();
        new_user->set_id(count + 1);
        new_user->set_username(login_id);
        new_user->set_password(SHA256(password));
        new_user->set_email(email);
        new_user->set_name(name);
        new_user->set_location(location);
        std::ofstream file_out("List_Of_user.txt", std::ios_base::out | std::ios_base::binary);
        book.SerializeToOstream(&file_out);
        file_out.close();
        user_index = count;
        std::cout << "\nNew User Created Sucessfully !!! ... ";
        std::cout << "\n\nPress Enter to Continue.....";
        getch();
    }
    else if (ch == 3) {
        // Exiting the program
        std::cout << "Thanks for using ";
        std::exit(0);
    }
    else {
        // Handling Wrong Option 
        std::cout << "\n Wrong option !!! \n";
        std::cout << "\n\nPress Enter to Continue.....";
        getch();
        system("cls");
        goto Start;
    }
Projects_Menu:
    system("CLS");
    std::cout << "File Selection Menu :-\n\n1.Create New File \t 2.Old Projects \n\nEnter the Option:-  ";
    std::cin >> ch;
    if (ch == 1) {
        // Creating a New File
        std::string proj_name;
        std::ifstream files_in;
        files_in.open("List_Of_Project.txt", std::ios_base::in | std::ios_base::binary);
        proj_book.ParseFromIstream(&files_in);
    Project_name:
        std::cout << "\nEnter the Project Name : ";
        std::cin >> proj_name;
        for (int i = 0; i < proj_book.bookproject_size(); ++i) {
            const auto& proj = proj_book.bookproject(i);
            if (proj_name == proj.name()) {
                std::cout << "\nProject Name Already Exist !!! Rename Pls !!! \n";
                goto Project_name;
            }
        }
        files_in.close();
        //Project Pointer Declaration
        project_detail project;
        project_detail* new_project = proj_book.add_bookproject();
        //Adding in list of project 
        new_project->set_id(book.bookuser(user_index).id());
        new_project->set_creator(book.bookuser(user_index).name());
        new_project->set_name(proj_name);
        //Creating seprate file 
        project.set_id(book.bookuser(user_index).id());
        project.set_creator(book.bookuser(user_index).name());
        project.set_name(proj_name);
        //Adding lines
        std::cin.ignore();
        while (1) {
            std::cout << "Enter the line  : ";
            std::getline(std::cin, line);
            ch = line[0];
            if (ch == NULL) {
                break;
            }
            project.add_line(line);
        }
        //Adding in list of project 
        std::ofstream file_project("List_Of_Project.txt", std::ios_base::out | std::ios_base::binary);
        proj_book.SerializePartialToOstream(&file_project);
        file_project.close();
        //Creating seprate file 
        location = Project_Location_detail;
        location = location + proj_name + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        project.SerializePartialToOstream(&file_out);
        file_out.close();
        // Creating version file for project
        location = Project_Location_detail;
        location = location + "version_list_of_" + proj_name + ".txt";
        std::ofstream file_version(location, std::ios_base::out | std::ios_base::binary);
        selected_version.clear_change();
        selected_version.clear_line_change();
        selected_version.clear_line_number();
        selected_version.set_proj_id(proj_name);
        selected_version.SerializePartialToOstream(&file_version);
        file_version.close();
        // Selecting Current Project
        project_index = proj_book.bookproject_size() - 1;
        std::cout << "\n\nFile Created Successfully !!! .... \n";
        std::cout << "\nPress Enter to Continue.....";
        getch();
    }
    else if (ch == 2) {
        // OLd Projects Display 
    Reselect_project:
        std::cout << "\n Old Projects List :- ";
        std::ifstream files_in;
        files_in.open("List_Of_Project.txt", std::ios_base::in | std::ios_base::binary);
        proj_book.ParseFromIstream(&files_in);
        count = 0;
        for (int i = 0; i < proj_book.bookproject_size(); ++i) {
            const auto& proj = proj_book.bookproject(i);
            if (book.bookuser(user_index).id() != proj.id()) {
                continue;
            }
            count = 1;
            std::cout << "\n\nProject name : " << proj.name() << std::endl;
            std::cout << "Project creator : " << proj.creator() << std::endl;
            std::cout << "Project id : " << proj.id() << std::endl;
        }
        files_in.close();
        //  If User Has No Previous Project
        if (count == 0) {
            std::cout << "\n\n\tYou have No Previous Project !!!\n\nPlease Create One !!!\n\n";
            std::cout << "\nPress Enter to Continue.....";
            getch();
            goto Projects_Menu;
        }
        // Selection of Selected Project
        std::cout << "\n\nChoose the project ( Enter the project name ) : ";
        std::cin >> project_name;
        project_index = -1;
        for (int i = 0; i < proj_book.bookproject_size(); ++i) {
            const auto& proj = proj_book.bookproject(i);
            if (book.bookuser(user_index).id() != proj.id()) {
                continue;
            }
            if (project_name == proj.name()) {
                project_index = i;
            }
        }
    }
    if (project_index == -1) {
        std::cout << "\nWrong project Name !!!!\n\n";
        goto Reselect_project;
    }
    // Displaying The Main Menu Option
    project_detail s_project;
    std::fstream files_in;
    std::ofstream files_version_write;
Option_menu:
    system("CLS");
    // Opening Selected Project
    const auto& selected_proj = proj_book.bookproject(project_index);
    location = Project_Location_detail;
    location = location + selected_proj.name() + ".txt";
    files_in.open(location, std::ios_base::in | std::ios_base::binary);
    s_project.ParseFromIstream(&files_in);
    files_in.close();
    // Opening Selected Version
    //std::fstream files_version_open;
    location = Project_Location_detail;
    location = location + "version_list_of_" + selected_proj.name() + ".txt";
    files_in.open(location, std::ios_base::in | std::ios_base::binary);
    selected_version.ParseFromIstream(&files_in);
    files_in.close();
    change_count = selected_version.change_size();
    std::cout << "Selected Project :- " << selected_proj.name();
    std::cout << "\n\nFile Editing Option :\n\n\t1.ADD\n\t2.Update\n\t3.Remove\n\t4.Display\n\t5.logout\n\t6.Change details";
    std::cout << "\n\t7.Revert change Based on Lines\n\t8.Revert change Based on Version\n\t9.Exit :- \n\nEnter the Option :- ";
    std::cin >> ch;
    std::cout << "\n";
    if (ch == 1) {
        //Adding line At End
        std::cout << "Enter the line to be appended ";
        std::cin.ignore();
        std::getline(std::cin, line);
        s_project.add_line(line);
        // Storing The Changes Made
        selected_version.add_change(1);
        selected_version.add_line_change(line);
        selected_version.add_line_number(s_project.line_size() - 1);
        my_time = time(NULL);
        selected_version.add_change_time(ctime(&my_time));
        std::cout << "\nThe Line Was Added\n"; 
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close();  
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 2) {
        //Updating
    Update_Menu:
        std::cout << " 1.Single line\t2.Entire Document \n\nEnter the Option:- ";
        std::cin >> ch;
        if (ch == 1) {
            // Signle Line Update
            std::cout << "\nEnter the Updating Line Content:- ";
            std::cin.ignore();
            std::getline(std::cin, line);
            while (1) {
                std::cout << "\nEnter the line Number :- ";
                std::cin >> line_number;
                if (line_number < s_project.line_size()) {
                    break;
                }
                std::cout << "\nLine Number out of Range \n";
            }
            // Storing The Changes Made
            selected_version.add_change(3);
            selected_version.add_line_change(s_project.line(line_number));
            selected_version.add_line_number(line_number);
            s_project.set_line(line_number, line);
            my_time = time(NULL);
            selected_version.add_change_time(ctime(&my_time));
            std::cout << "\nSingle Line Updated ...\n";
        }
        else if (ch == 2) {
            //Multi line update
            s_project.clear_line();
            std::cin.ignore();
            std::cout << std::endl;
            while (1) {
                std::cout << "Enter the line  : ";
                std::getline(std::cin, line);
                if (line[0] == NULL) {
                    break;
                }
                s_project.add_line(line);
            }
            // Deleting all changes
            selected_version.clear_change();
            selected_version.clear_line_change();
            selected_version.clear_line_number();
            selected_version.clear_change_time();
            std::cout << "\nComplete file Updated ...\n";
        }
        else {
            // Handling Wrong Option
            std::cout << "\nWrong Option !!!\n";
            goto Update_Menu;
        } 
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close(); 
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 3) {
        // Removing 
    Remove_menu:
        std::cout << " 1.Single line\t2.Entire Document \n\nEnter the Option:- ";
        std::cin >> ch;
        if (ch == 1) {
            // Single Line Remove
            auto* a = s_project.mutable_line();
            while (1) {
                std::cout << "\nEnter the line Number :- ";
                std::cin >> line_number;
                if (line_number < s_project.line_size()) {
                    break;
                }
                std::cout << "\nLine Number out of Range \n";
            }
            // Storing The Changes Made
            selected_version.add_change(2);
            selected_version.add_line_change(s_project.line(line_number));
            selected_version.add_line_number(line_number);
            my_time = time(NULL);
            selected_version.add_change_time(ctime(&my_time));
            if (line_number != s_project.line_size() - 1) {
                for (int i = line_number; i + 1 < s_project.line_size(); ++i) {
                    s_project.set_line(i, s_project.line(i + 1));
                }
            }
            a->RemoveLast();
            std::cout << "\nSingle Line Removed !!! ... \n";
        }
        else if (ch == 2) {
            // Multi line remove
            s_project.clear_line();
            // Deleting all changes
            selected_version.clear_change();
            selected_version.clear_line_change();
            selected_version.clear_line_number();
            selected_version.clear_change_time();
            std::cout << "\nComplete File Removed !!! ... \n";
        }
        else {
            // Handling Wrong Option
            std::cout << "Wrong Option !!! \n";
            goto Remove_menu;
        }  
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close(); 
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 4) {
        // Displaying the contents  
        std::cout << "\nProject name : " << s_project.name() << std::endl;
        std::cout << "Project creator : " << s_project.creator() << std::endl;
        std::cout << "Project id : " << s_project.id() << std::endl;
        std::cout << "Project line size : " << s_project.line_size() << std::endl;
        if (s_project.line_size() == 0) {
            std::cout << "\nFile is Empty !!!\n";
        }
        else {
            for (int j = 0; j < s_project.line_size(); ++j) {
                std::cout << "line no : " << j << " :- " << s_project.line(j) << std::endl;
            }
        }
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 5) {
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close();
        // Flow of control to Login Id
        std::cout << "File Stored !!! ... \n";
        std::cout << "\nPress Enter to Continue.....";
        getch();
        system("cls");
        goto Start;
    }
    else if (ch == 6) {
        // Changes details
        std::cout << "Project Id : " << selected_version.proj_id() << "\n";
        if (selected_version.change_size() == 0) {
            std::cout << "\nNO Version Backup No Changes made  !!!  ... \n\n";
            std::cout << "\nPress Enter to Continue.....";
            getch();
            goto Option_menu;
        }
        for (int i = 0; i < selected_version.change_size(); ++i) {
            if (i % 5 == 0) {
                std::cout << "\nVersion " << (i / 5) + 1 << " : \n\n";
            }
            std::cout << "\tChange count " << i + 1 << "   ";
            std::cout << "change type : " << details[selected_version.change(i) - 1] << "   ";
            std::cout << "line number  : " << selected_version.line_number(i) << "   ";
            std::cout << "Line change value : " << selected_version.line_change(i) << "   ";
            std::cout << "Line Change Time : " << selected_version.change_time(i) << "\n";
        }
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 7) {
        // Reverting change Based On Lines
        while (1) {
            std::cout << "Enter the Number of Line To be Reverted :- ";
            std::cin >> line_number;
            if (line_number <= selected_version.change_size()) {
                break;
            }
            std::cout << "\nNumber of Line To be Reverted Wrong !!! ... \n\n";
        }
        change_count = selected_version.change_size() - 1;
        // Version Converting To Mutable
        auto* version_change = selected_version.mutable_change();
        auto* version_linenumber = selected_version.mutable_line_number();
        auto* version_linechange = selected_version.mutable_line_change();
        auto* version_change_time = selected_version.mutable_change_time();
        auto* selected_line = s_project.mutable_line();
        for (int i = 1; i <= line_number; ++i) {
            if (selected_version.change(change_count) == 1) {
                // If Line was Added  Last Line is Removed
                selected_line->RemoveLast(); 
            }
            else if (selected_version.change(change_count) == 2) {
                // If Line was Removed  It has to be Added
                s_project.add_line(selected_version.line_change(change_count));
                for (int i = s_project.line_size() - 1; i > selected_version.line_number(change_count); --i) {
                    selected_line->SwapElements(i, i - 1); 
                }
            }
            else if (selected_version.change(change_count) == 3) { 
                // If line was Updated  Setting it to Prevoius Content
                s_project.set_line(selected_version.line_number(change_count), selected_version.line_change(change_count));
            }
            // Removing Last Row In Selected Version
            version_change->RemoveLast();
            version_linechange->ReleaseLast();
            version_linenumber->RemoveLast();
            version_change_time->RemoveLast();
            change_count = change_count - 1;
        } 
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close(); 
        std::cout << "\nRevert SuccessFull  !!!  ...\n";
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 8) {
        // Reverting Change Based On Version
        change_count = 0;
        if (!selected_version.change_size()) {
            std::cout << "\nNO Version Backup No Changes made !!! ... \n\n";
            std::cout << "\nPress Enter to Continue.....";
            getch();
            goto Option_menu;
        }
        std::cout << "Version List :- \n";
        // Displaying The  Number Of Version
        for (int i = 0; i < selected_version.change_size(); ++i) {
            if (i % 5 == 0) {
                std::cout << "\n\tVersion " << (i / 5) + 1;
                change_count = change_count + 1;
            }
        }
        // Error Handling Version Number
        while (1) {
            std::cout << "\n\nEnter the version number :- ";
            std::cin >> ch;
            if (ch <= change_count) {
                break;
            }
            std::cout << "\nVersion Out of Bound Error  !!!  ... \n";
        }
        // Calculation of Number of lines to be Reverted
        if (selected_version.change_size() % 5 == 0) {
            line_number = (selected_version.change_size() % 5) + ((change_count - ch + 1) * 5);
        }
        else {
            line_number = (selected_version.change_size() % 5) + ((change_count - ch) * 5);
        }
        std::cout << "\nNumber of Lines Reverted = " << line_number << std::endl;
        // Removing Based on Line
        change_count = selected_version.change_size() - 1;
        auto* version_change = selected_version.mutable_change();
        auto* version_linenumber = selected_version.mutable_line_number();
        auto* version_linechange = selected_version.mutable_line_change();
        auto* version_change_time = selected_version.mutable_change_time();
        auto* selected_line = s_project.mutable_line();
        for (int i = 0; i < line_number; ++i) {
            if (selected_version.change(change_count) == 1) {
                // If line was added  Last line is Removed
                selected_line->RemoveLast();
            }
            else if (selected_version.change(change_count) == 2) {
                // If line was removed  It is to be Added
                s_project.add_line(selected_version.line_change(change_count));
                for (int i = s_project.line_size() - 1; i > selected_version.line_number(change_count); --i) {
                    selected_line->SwapElements(i, i - 1);
                }
            }
            else if (selected_version.change(change_count) == 3) {
                // If line was updated  Setting it to Prevoius content
                s_project.set_line(selected_version.line_number(change_count), selected_version.line_change(change_count));
            }
            // Removing last row in Selected version
            version_change->RemoveLast();
            version_linechange->ReleaseLast();
            version_linenumber->RemoveLast();
            version_change_time->RemoveLast();
            change_count = change_count - 1;
        } 
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        files_version_write.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_write);
        files_version_write.close();
        // Storing the txt file and Logging out 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close(); 
        std::cout << "\nRevert SuccessFull  !!!  ... \n";
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    else if (ch == 9) {
        // storing the version file 
        location = Project_Location_detail;
        location = location + "version_list_of_" + s_project.name() + ".txt";
        std::ofstream files_version_open;
        files_version_open.open(location, std::ios_base::out | std::ios_base::binary);
        selected_version.SerializePartialToOstream(&files_version_open);
        files_version_open.close();
        // Storing the txt file and Exit 
        location = Project_Location_detail;
        location = location + s_project.name() + ".txt";
        std::ofstream file_out(location, std::ios_base::out | std::ios_base::binary);
        s_project.SerializePartialToOstream(&file_out);
        file_out.close();
        std::cout << "\n\nThank You !!!....\n\n";
    }
    else {
        // Handling Wrong Option 
        std::cout << "\n Wrong option !!! \n";
        std::cout << "\nPress Enter to Continue.....";
        getch();
        goto Option_menu;
    }
    return 0;
}
