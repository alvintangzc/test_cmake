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

    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    console->info("{}", buffer.GetString());

    return 0;
}
