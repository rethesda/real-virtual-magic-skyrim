#pragma once

#include <string>
#include <tuple>


// we pass this structure from user API as a json string
struct BrainFlowModelParams
{
    int metric;
    int classifier;
    std::string file;
    std::string other_info;

    BrainFlowModelParams (int metric, int classifier)
    {
        this->metric = metric;
        this->classifier = classifier;
        file = "";
        other_info = "";
    }

    // default copy constructor and assignment operator are ok, need less operator to use in map
    bool operator< (const struct BrainFlowModelParams &other) const
    {
        return std::tie (metric, classifier, file, other_info) <
            std::tie (other.metric, other.classifier, other.file, other.other_info);
    }
};
