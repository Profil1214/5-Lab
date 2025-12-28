#pragma once

#include <iostream>
#include <limits>
#include <string>

//! \brief Класс для валидации пользовательского ввода
class InputValidator
{
public:
    //! \brief Получает корректное целое число от пользователя
    //! \param prompt Сообщение для пользователя (опционально)
    //! \return Введенное целое число
    static int GetInt(const std::string& prompt = "");
};