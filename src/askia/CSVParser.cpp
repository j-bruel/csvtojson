//!
//! @author jbruel
//! @date 12/06/2020
//! @file CSVParser.cpp
//! @brief Askia parser according instruction from the technical test.
//!

#include "askia/CSVParser.hpp"
#include "askia/exception.hpp"
#include <fstream>

namespace askia
{

    askia::CSVContent   CSVParser::pars(const char *filePath) const noexcept(false)
    {
        std::ifstream       csvInputFile(filePath);
        askia::CSVContent   csvContent;

        if (csvInputFile.fail())
            throw askia::exception("CSV input file not found.");
        while (csvInputFile.good())
            csvContent.push_back(parseRow(csvInputFile));
        csvInputFile.close();
        return (csvContent);
    }

    askia::CSVRow       CSVParser::parseRow(std::istream &csvInputFile) const noexcept
    {
        askia::CSVRow   row;
        std::string     field;
        bool            amIIntoQuotes = false;
        char            currentReadingChar;

        while (csvInputFile.good())
        {
            currentReadingChar = csvInputFile.get();
            if (!amIIntoQuotes && currentReadingChar == '"')
                amIIntoQuotes = true;
            else if (amIIntoQuotes && currentReadingChar == '"')
            {
                if (csvInputFile.peek() == '"')
                {
                    field += currentReadingChar;
                    field += static_cast<char>(csvInputFile.get());
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