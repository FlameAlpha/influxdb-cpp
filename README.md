# influxdb-cxx

It is forked from [awegrzyn/influxdb-cxx](https://github.com/awegrzyn/influxdb-cxx), and I also modified some bug (about time and query) in this project, and transplant it to QT project

InfluxDB C++ client library
 - Writing points
 - Batch write
 - Data exploration
 - Supported transports
   - HTTP/HTTPS with Basic Auth


 ### Installation

 __Build requirements:__
Qt 5.12.2 MSVC2017 64bit 

__Integrated development environment:__
Qt Creator 4.8.2

__Dependencies:__
 cURL, boost 1.57+ 

## Quick start

### write

```cpp
// Provide complete URI
auto influxdb = influxdb::InfluxDBFactory::Get("http://localhost:8086/?db=test");
influxdb->write(Point{"test"}
  .addField("value", 10)
  .addTag("host", "localhost")
);
```


### Query

```cpp
// Available over HTTP only
auto influxdb = influxdb::InfluxDBFactory::Get("http://localhost:8086/?db=test");
/// Pass an IFQL to get list of points
std::vector<Point> points = idb->query("SELECT * FROM test");
```

## Transports

An underlying transport is fully configurable by passing an URI:
```
[protocol]://[username:password@]host:port[/?db=database]
```
<br>
List of supported transport is following:

| Name        | Dependency  | URI protocol   | Sample URI                            |
| ----------- |:-----------:|:--------------:| -------------------------------------:|
| HTTP        | cURL        | `http`/`https` | `http://localhost:8086/?db=<db>`      |
