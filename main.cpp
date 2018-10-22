#include "stdio.h"
#include <iostream>

#include "easylogging++.h"

#include "boost/format.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/algorithm/string.hpp"

using namespace std;
INITIALIZE_EASYLOGGINGPP

int main() {
    LOG(INFO) << "Hello, world";
    LOG(INFO) << boost::format("%s %s") % "Hello" % 3 << std::endl;
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
   return 0;
}
