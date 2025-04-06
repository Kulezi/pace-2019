#include "vc_lib.h"
#include "mis_config.h"
#include "configuration_mis.h"
#include "exact_mis.h"
std::vector<bool> getVC(std::vector<std::vector<int>> graph) {
    MISConfig mis_config;
    configuration_mis().standard(mis_config);

    return getExactMISCombined(graph, mis_config);

}