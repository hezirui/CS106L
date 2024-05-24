/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <algorithm>

// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template <typename T>
double convert_f_to_c(T num) {
    return static_cast<double>(num - 32)*5/9;
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    // TODO: write get_forecast here!
    std::vector<double> return_vec;
    for(auto it = readings.begin();it != readings.end();it++){
        return_vec.push_back(fn(*it));
    }
    return  return_vec;
}


int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };
    // TODO: Convert temperatures to Celsius and output to output.txt
    std::ofstream ofs("C:\\Users\\admin\\CLionProjects\\CS106L\\MyAssignment\\Assignment4_weather_forecast\\output.txt");
    if(!ofs)
        std::cout<<"file not open"<<std::endl;
    ofs<<"Convert temperatures to Celsius:"<<'\n';
    for(const auto& vec : readings){
        for(const auto& t : vec){
            ofs<<std::fixed<<std::setprecision(2)<<convert_f_to_c(t)<<' ';
        }
        ofs<<'\n';
    }
    ofs << std::endl;

    // TODO: Find the maximum temperature for each day and output to output.txt
    ofs<<'\n'<<"max temperature： "<<'\n';
    std::vector<double> max,min,average;
    max = get_forecast(
            readings,
            [](std::vector<int> vec) ->double {
                return *std::max_element(vec.begin(),vec.end());
            }
            );
    for(auto it = max.begin();it != max.end();it++){
        ofs<<std::fixed<<std::setprecision(2)<<*it<<' ';
    }
    // TODO: Find the minimum temperature for each day and output to output.txt
    ofs<<'\n'<<"min temperature： "<<'\n';
    min = get_forecast(
            readings,
            [](std::vector<int> vec) ->double {
                return *std::min_element(vec.begin(),vec.end());
            }
    );
    for(auto it = min.begin();it != min.end();it++){
        ofs<<std::fixed<<std::setprecision(2)<<*it<<' ';
    }
    // TODO: Find the average temperature for each day and output to output.txt
    ofs<<'\n'<<"average temperature： "<<'\n';
    average = get_forecast(
            readings,
            [](std::vector<int> vec) ->double {
                return std::accumulate(vec.begin(),vec.end(),0.0)/vec.size();
            }
    );
    for(auto it = average.begin();it != average.end();it++){
        ofs<<std::fixed<<std::setprecision(2)<<*it<<' ';
    }
    return 0;
}