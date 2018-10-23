#include "stdio.h"
#include <iostream>

#include "easylogging++.h"

#include "boost/format.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/algorithm/string.hpp"

using namespace std;
INITIALIZE_EASYLOGGINGPP

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
    LOG(INFO) << "Hello, world";
    LOG(INFO) << boost::format("%s %s") % "Hello" % 3;
    LOG(INFO) << boost::lexical_cast<std::string>(123);
    LOG(INFO) << boost::lexical_cast<int>("123");
    LOG(INFO) << boost::lexical_cast<int>("05");
    string stringtobesplit = "AA/BB-CC";
    vector<string> tokens;
    boost::split(tokens, stringtobesplit, boost::is_any_of("/-")); 
    for (auto &item : tokens)
    {
        LOG(INFO) << item;
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
    return 0;
}
