//!
//! @author jbruel
//! @date 12/06/2020
//! @file main.cpp
//! @brief Main function for the Askia technical test.
//!

#include "askia/CSVParser.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>

//!
//! @brief Print the application on the standard output.
//! @param appPath Application path for the help.
//!
static void showHelp(const char *appPath)
{
    std::cout << "Usage: " << appPath << " <input_csv_file_path> <output_json_file_path> [--header]" << std::endl;
    std::cout << "This application convert csv file to json file." << std::endl;
    std::cout << std::endl;
    std::cout << "<input_csv_file_path>   CSV file path to read and translate to json format." << std::endl;
    std::cout << "<output_json_file_path> JSON file path use has output." << std::endl;
    std::cout << "--header:               Specified then the first line of the CSV file is considered as the header ";
    std::cout << "line and the JSON output file should contain objects with the appropriate corresponding key, ";
    std::cout << "if no 'header' option is specified then there will be no header line in the CSV file and the ";
    std::cout << "JSON output should contain arrays." << std::endl;
}

//! @todo std::filesystem
//! @todo Read system into parser
//! @todo last line not read from file.
//! @todo own exception
//! @todo Re-implement option features
//! @todo json printer
int         main(int argc, const char * const *argv)
{
    askia::CSVParser   parser;

/*    if (argc < 3) {
        showHelp(argv[0]);
        return (EXIT_FAILURE);
    }*/
    try {
        std::ifstream               in("../sample/email.csv");
        std::vector<std::string>    row;

        if (in.fail())
        {
            std::cerr << "File not found." << std::endl;
            return (EXIT_FAILURE);
        }
        while(in.good())
        {
            parser.setFieldSeparator(',');
            row = parser.parseRow(in);
            for (const std::string &field : row)
                std::cout << "[" << field << "]";
            std::cout << std::endl;
        }
        in.close();
//        parser.read(argv[1], (argc >= 4 && std::string(argv[3]) == "--header"));
//        parser.print(argv[2]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}