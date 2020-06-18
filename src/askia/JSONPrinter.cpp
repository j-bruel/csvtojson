//!
//! @author jbruel
//! @date 17/06/2020
//! @file JSONPrinter.cpp
//! @brief A simple json printer according Asking instruction.
//!

#include "askia/JSONPrinter.hpp"
#include "askia/exception.hpp"
#include <fstream>
#include <iomanip>

namespace askia
{

    void    JSONPrinter::print(const char *outputFilePath, const CSVContent &csvContent, bool isHeader) const noexcept(false)
    {
        if (outputFilePath == nullptr || strlen(outputFilePath) == 0)
            throw askia::exception("Output json file path is not set.");
        if (isHeader && csvContent.size() < 2)
            throw askia::exception("To generate a json file with a header, the csv input file must contain at least one row of data.");

        std::ofstream  jsonOutputFileStream(outputFilePath);

        jsonOutputFileStream << "[" << std::endl;
        if (!csvContent.empty())
            isHeader ? object(jsonOutputFileStream, csvContent[0], csvContent) : array(jsonOutputFileStream, csvContent);
        jsonOutputFileStream << "]" << std::endl;
    }

    void    JSONPrinter::array(std::ofstream &jsonOutputFileStream, const CSVContent &csvContent) const noexcept
    {
        for (size_t i = 0; i < csvContent.size(); ++i)
        {
            if (csvContent[i].empty())
                continue;
            jsonOutputFileStream << "\t[";
            for (size_t j = 0; j < csvContent[i].size(); ++j)
            {
                jsonOutputFileStream << stringFormatting(csvContent[i][j]);
                if (j + 1 < csvContent[i].size())
                    jsonOutputFileStream << ", ";
            }
            jsonOutputFileStream << ']';
            if (i + 1 < csvContent.size())
                jsonOutputFileStream << ',';
            jsonOutputFileStream << std::endl;
        }
    }

    void    JSONPrinter::object(std::ofstream &jsonOutputFileStream, const CSVRow &header, const CSVContent &csvContent) const noexcept
    {
        if (csvContent.size() <= 1)
            return ;
        for (size_t i = 1; i < csvContent.size(); ++i)
        {
            if (csvContent[i].empty())
                continue;
            jsonOutputFileStream << "\t{" << std::endl;
            for (size_t j = 0; j < header.size(); ++j)
            {
                jsonOutputFileStream << "\t\t\t" << stringFormatting(header[j]) << ": ";
                jsonOutputFileStream << (j < csvContent[i].size() ? stringFormatting(csvContent[i][j]) : "\"\"");
                if (j + 1 < header.size())
                    jsonOutputFileStream << ',' << std::endl;
            }
            jsonOutputFileStream << std::endl << "\t}";
            if (i + 1 < csvContent.size())
                jsonOutputFileStream << ',';
            jsonOutputFileStream << std::endl;
        }
    }

    std::string JSONPrinter::stringFormatting(const std::string &str) const noexcept
    {
        if (isNumeric(str)) // no formatting if the value is a number.
            return (str);

        std::stringstream ss;

        ss << std::quoted(str); // Quotes handling and sub quotes handling.
        return (std::regex_replace(ss.str(), std::regex("\n"), std::string("\\n"))); // Using regex replace new line by \n characters.
    }

}