//!
//! @author jbruel
//! @date 12/06/2020
//! @file Parser.cpp
//! @brief Askia parser according instruction from the technical test.
//!

#include "askia/Parser.hpp"
#include "jsoncons_ext/csv/csv.hpp"
#include <fstream>

namespace askia
{

    void Parser::read(const char *csvInputFilePath, bool hasHeader) noexcept(false)
    {
        std::ifstream   inputStream(csvInputFilePath);

        if (!inputStream.is_open())
            throw std::runtime_error("ERROR: Impossible to open the file : " + std::string(csvInputFilePath));
        mJsonFileResult = jsoncons::csv::decode_csv<jsoncons::json>(inputStream,
                                                                    jsoncons::csv::csv_options().assume_header(hasHeader));
        if (mJsonFileResult.empty())
            throw std::runtime_error("ERROR: Invalid CSV file or invalid option.");
    }

    void Parser::print(const char *jsonOutputFilePath) const noexcept(false)
    {
        if (!isValid())
            throw std::runtime_error("ERROR: Impossible to generate a json output file without loading a csv input file.");

        std::ofstream   outputStream(jsonOutputFilePath);

        if (!outputStream.is_open())
            throw std::runtime_error("ERROR: Impossible to open the file : " + std::string(jsonOutputFilePath));
        outputStream << jsoncons::pretty_print(mJsonFileResult) << std::endl;
    }
}