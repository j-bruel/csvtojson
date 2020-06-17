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

    askia::CSVContent   CSVParser::parse(const char *filePath) const noexcept(false)
    {
        std::ifstream       csvInputFile(filePath);
        askia::CSVContent   csvContent;
        askia::CSVRow       csvRow;

        if (filePath == nullptr || !std::strlen(filePath))
            throw askia::exception("CSV file path is NULL or empty. Impossible to parse the file.");
        if (csvInputFile.fail())
            throw askia::exception("CSV input file not found.");
        while (csvInputFile.good())
        {
            csvRow = parseRow(csvInputFile);
            if (!csvRow.empty())
                csvContent.push_back(csvRow);
        }
        csvInputFile.close();
        return (csvContent);
    }

    askia::CSVRow       CSVParser::parseRow(std::istream &csvInputFile) const noexcept
    {
        askia::CSVRow   row;
        askia::CSVField field;
        bool            amIIntoQuotes = false;
        char            currentReadingChar;

        while (csvInputFile.good()) // looping into the file char by char.
        {
            currentReadingChar = csvInputFile.get();
            if (!amIIntoQuotes && currentReadingChar == '"') // if not into quotes and current char is a quote.
                amIIntoQuotes = true;
            else if (amIIntoQuotes && currentReadingChar == '"') // if into quotes and current char is a quote.
            {
                if (csvInputFile.peek() == '"') // if next char is a quote too.
                {
                    field += currentReadingChar;
                    field += static_cast<char>(csvInputFile.get());
                    continue;
                }
                amIIntoQuotes = false;
            }
            else if (!amIIntoQuotes && currentReadingChar == mSeparator) // if not into quotes and current char is a separator.
            {
                addFieldIntoRow(row, field);
                field.clear();
                continue;
            }
            else if (!amIIntoQuotes && (currentReadingChar == '\r' || currentReadingChar == '\n')) // if not into quotes and end of the row.
            {
                addFieldIntoRow(row, field);
                return (row);
            }
            field += currentReadingChar;
        }
        addFieldIntoRow(row, field);
        return (row);
    }

    void    CSVParser::addFieldIntoRow(askia::CSVRow &row, const askia::CSVField &field) const noexcept
    {
        if (!field.empty() && field[0] != EOF)
            row.push_back(field);
    }

}