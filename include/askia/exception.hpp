//!
//! @file exception.hpp
//! @author jbruel
//! @date 17/06/20
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_EXCEPTION_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_EXCEPTION_HPP

# include <exception>
# include <string>
# include <utility>

//!
//! @namespace jbr::reg
//!
namespace askia
{

    //!
    //! @class exception
    //! @brief Custom exception class.
    //!
    class exception : public std::exception
    {
    private:
        std::string mMsg; //!< Exception message

    public:
        //!
        //! @brief Custom exception.
        //! @param msg Exception message.
        //!
        explicit exception(std::string &&msg) : mMsg(std::move(msg)) {}
        //!
        //! @brief Exception throw destructor.
        //!
        ~exception() noexcept override = default;

    public:
        //!
        //! @brief What exception information.
        //! @return What message.
        //!
        [[nodiscard]]
        const char  *what() const noexcept override { return (mMsg.c_str()); }
    };

}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_EXCEPTION_HPP
