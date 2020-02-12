///
/// \author Adam Wegrzynek
///

#ifndef INFLUXDATA_POINT_H
#define INFLUXDATA_POINT_H

#include <vector>
#include <string>
#include <chrono>
#include <variant>
#include <sstream>
#include <chrono>
namespace influxdb
{
/// \brief Represents a class to handle multi fields
template <typename Value=double>
class field{
public:
    field(){
        size = 0;
    }

    void push_back(std::string name, Value value){
        this->name.push_back(name);
        this->value.push_back(value);
        size++;
    }

    std::string getName(unsigned long long int n){
        return name[n];
    }

    Value getValue(unsigned long long int n){
        return value[n];
    }

    std::string operator[](unsigned long long int n) {
        if(n < size){
            std::stringstream stream;
            std::string all;
            stream << name[n];
            stream >> all;
            return all+"="+value[n];
        }
    }
private:
    int size;
    std::vector<std::string> name;
    std::vector<Value> value;
};
/// \brief Represents a point
class Point
{
  public:
    /// Constructs point based on measurement name
    Point(const std::string& measurement);

    /// Default destructor
    ~Point() = default;

    /// Adds a tags
    Point&& addTag(std::string_view key, std::string_view value);

    /// Adds filed
    Point&& addField(std::string_view name, std::variant<int, long long int, std::string, double> value);

    /// Generetes current timestamp
    static auto getCurrentTimestamp() -> decltype(std::chrono::system_clock::now());

    /// Converts point to Influx Line Protocol
    std::string toLineProtocol() const;

    /// Sets custom timestamp
    Point&& setTimestamp(std::chrono::time_point<std::chrono::system_clock> timestamp);

    /// Name getter
    std::string getName() const;

    /// Timestamp getter
    std::chrono::time_point<std::chrono::system_clock> getTimestamp() const;

    /// Fields getter
    std::string getFields() const;

  protected:
    /// A value
    std::variant<long long int, std::string, double> mValue;

    /// A name
    std::string mMeasurement;

    /// A timestamp
    std::chrono::time_point<std::chrono::system_clock> mTimestamp;

    /// Tags
    std::string mTags;

    /// Fields
    std::string mFields;
};

} // namespace influxdb

#endif // INFLUXDATA_POINT_H
