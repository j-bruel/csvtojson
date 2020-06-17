//!
//! @author jbruel
//! @date 12/06/2020
//! @file CSVParser.cpp
//! @brief Askia parser according instruction from the technical test.
//!

#include "askia/CSVParser.hpp"

namespace askia
{

    std::vector<std::string>    CSVParser::parseRow(std::istream &in) const noexcept(false)
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