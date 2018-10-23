#include "stdio.h"
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "boost/format.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/algorithm/string.hpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;
auto console = spdlog::stdout_color_mt("console");

void safeclose(FILE*fp) {
    if(fp) {
        printf("my close\r\n");
        fclose(fp);
    }
}
void test_file() {
    std::shared_ptr<FILE> fp( fopen("test.file", "a+t"), safeclose );
    fprintf( fp.get(), "a message\n" );
}

int main() {
   console->info("Hello, world");
    console->info("{}", (boost::format("%s %s") % "Hello" % 3).str());
    console->info("{}", boost::lexical_cast<string>(123));
    console->info("{}", boost::lexical_cast<int>("123"));
    console->info("{}", boost::lexical_cast<int>("05"));
    string stringtobesplit = "AA/BB-CC";
    vector<string> tokens;
    boost::split(tokens, stringtobesplit, boost::is_any_of("/-")); 
    for (auto &item : tokens)
    {
        console->info("{}", item);
    }

    test_file();

    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    std::cout << "before:";
    std::for_each(nums.begin(), nums.end(), [](const int& n) { std::cout << " " << n; });
    std::cout << '\n';

    std::map<string, string> mapStr;
    mapStr["test1"] = "1";
    mapStr["test2"] = "2";

    std::cout << "begin:";
    std::for_each(mapStr.begin(), mapStr.end(), [](const std::pair<string, string> &iter) { std::cout << iter.first << ":" << iter.second << " "; });
    std::cout << '\n';
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";

    Document d;
    d.Parse(json);
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    console->info("{}", buffer.GetString());

    return 0;
}
