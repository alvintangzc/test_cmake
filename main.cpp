#include "stdio.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"
#include <iostream>

#include "easylogging++.h"

#include "boost/format.hpp"

using namespace rapidjson;

INITIALIZE_EASYLOGGINGPP

int main() {
    LOG(INFO) << "Hello, world";
    std::cout << boost::format("%s %s") % "Hello" % 3 << std::endl;
    // 1. 把 JSON 解析至 DOM。
    const char* json = "{\"project\\t123\":\"rapidjson\",\"stars\":10}";
    Document d;

    if (d.Parse(json).HasParseError())
    {
        printf("%s\r\n",rapidjson::GetParseError_En(d.GetParseError()));
        return 1;
    }
    // 2. 利用 DOM 作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. 把 DOM 转换（stringify）成 JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    printf("%s\r\n", buffer.GetString());
    return 0;
}
