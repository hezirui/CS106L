/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <algorithm>
#include <numeric>


// write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]

template<typename T>
requires std::is_arithmetic_v<T> // concept，出现于C++20，用于保证T是数字类型
double convert_f_to_c(T temp)
{
    return static_cast<double>(temp - 32) * 5 / 9;
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn)
{
    // write get_forecast here!
    std::vector<double> result;
    for (auto &weather_of_the_day: readings)
    {
        result.push_back(fn(weather_of_the_day));
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> readings = {
            {70, 75, 80, 85, 90},
            {60, 65, 70, 75, 80},
            {50, 55, 60, 65, 70},
            {40, 45, 50, 55, 60},
            {30, 35, 40, 45, 50},
            {50, 55, 61, 65, 70},
            {40, 45, 50, 55, 60}
    };

    // Convert temperatures to Celsius and output to output.txt

    
    // Find the maximum temperature for each day and output to output.txt
    // 使用匿名函数和stl中的函数来完成
    auto maximum = get_forecast(readings,
                                [](const std::vector<int> &wea) -> double
                                {
                                    return *std::max_element(wea.begin(), wea.end());
                                });

    // Find the minimum temperature for each day and output to output.txt
    auto minimum = get_forecast(readings,
                                [](const std::vector<int> &wea) -> double
                                {
                                    return *std::min_element(wea.begin(), wea.end());
                                });

    // Find the average temperature for each day and output to output.txt
    auto average = get_forecast(readings,
                                [](const std::vector<int> &wea) -> double
                                {
                                    return std::accumulate(wea.begin(), wea.end(), double(0)) /
                                           static_cast<double>(wea.size());
                                });

    return 0;
}