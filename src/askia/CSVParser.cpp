//!
//! @author jbruel
//! @date 12/06/2020
//! @file CSVParser.cpp
//! @brief Askia parser according instruction from the technical test.
//!

#include "askia/CSVParser.hpp"
#include "askia/exception.hpp"
#include <fstream>
#include <iostream>

namespace askia
{

    void    CSVParser::pars(const char *filePath) const noexcept(false)
    {
        std::ifstream               csvInputFile(filePath);
        std::vector<std::string>    row;

        if (csvInputFile.fail())
            throw askia::exception("CSV input file not found.");
        while (csvInputFile.good())
        {
            row = parseRow(csvInputFile);
            for (const std::string &field : row)
                std::cout << "[" << field << "]";
            std::cout << std::endl;
        }
        csvInputFile.close();
    }

    std::vector<std::string>    CSVParser::parseRow(std::istream &in) const noexcept
    {
        std::string                 field;
        bool                        amIIntoQuotes = false;
        std::vector<std::string>    row;
        char                        currentReadingChar;

        while (in.good())
        {
            currentReadingChar = in.get();
            if (!amIIntoQuotes && currentReadingChar == '"')
                amIIntoQuotes = true;
            else if (amIIntoQuotes && currentReadingChar == '"')
            {
                if (in.peek() == '"')
                {
                    field += currentReadingChar;
                    field += static_cast<char>(in.get());
                    continue;
                }
                amIIntoQuotes = false;
            }
            else if (!amIIntoQuotes && currentReadingChar == mSeparator)
            {
                row.push_back(field);
                field.clear();
                continue;
            }
            else if (!amIIntoQuotes && (currentReadingChar == '\r' || currentReadingChar == '\n'))
            {
                row.push_back(field);
                return (row);
            }
            field += currentReadingChar;
        }
        return (row);
    }

}