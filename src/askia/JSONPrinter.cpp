//!
//! @author jbruel
//! @date 17/06/2020
//! @file JSONPrinter.cpp
//! @brief A simple json printer according Asking instruction.
//!

#include "askia/JSONPrinter.hpp"
#include "askia/exception.hpp"
#include <fstream>

namespace askia
{

    void    JSONPrinter::print(const char *outputFilePath, const CSVContent &csvContent, bool isHeader) noexcept(false)
    {
        if (outputFilePath == nullptr || strlen(outputFilePath) == 0)
            throw askia::exception("Output json file path is not set.");
        if (isHeader && csvContent.size() < 2)
            throw askia::exception("To generate a json file with a header, the csv input file must contain at least one row of data.");

        std::ofstream  jsonOutputFileStream(outputFilePath);

        jsonOutputFileStream << "[\n" << std::endl;
        if (!csvContent.empty())
            isHeader ? object(jsonOutputFileStream, csvContent[0], csvContent) : array(jsonOutputFileStream, csvContent);
        jsonOutputFileStream << "]\n" << std::endl;
    }

    void    JSONPrinter::array(std::ofstream &jsonOutputFileStream, const CSVContent &csvContent) noexcept(false)
    {

    }

    void    JSONPrinter::object(std::ofstream &jsonOutputFileStream, const CSVRow &header, const CSVContent &csvContent) noexcept(false)
    {

    }

}