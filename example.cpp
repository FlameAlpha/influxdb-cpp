#include <iostream>
#include "InfluxDBFactory.h"
#include "Point.h"
int main(){
    auto influxdb = influxdb::InfluxDBFactory::Get("http://admin:admin@localhost:8086/?db=mydb");
    influxdb->write(influxdb::Point{ "cpu" }
        .addTag("host", "localhost")
        .addTag("region", "china")
        .addField("north_latitude", 36)
        .addField("east_longitude", 114)
    );

    std::cout << "write over!" << std::endl;
    auto points = influxdb->query("SELECT * FROM cpu");
    std::cout << "query over!" << std::endl;
    std::cout << "name : " << points.back().getName() <<std::endl
                << "field : "<<points.back().getFields() << std::endl
                << "timestamp : " << std::chrono::duration_cast<std::chrono::microseconds>(points.back().getTimestamp().time_since_epoch()).count()  << std::endl;
}
