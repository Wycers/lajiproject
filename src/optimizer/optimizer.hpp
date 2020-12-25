#pragma once

#include <ir.hpp>
#include "cfg.h"

IRList optimize(IRList irs) {
    vector<CFG *> cfgs;

    auto last = irs.begin();
    for (auto i = irs.begin(); i != irs.end(); ++i) {
        if (i + 1 == irs.end() || typeid(**(i + 1)) == typeid(FUNCTION_IR)) {
            if (last == i) {
                continue;
            }
            IRList tmp = std::vector<IR *>(last, i + 1);
            cfgs.push_back(new CFG(tmp));
            last = i + 1;
        }
    }

    for (auto cfg: cfgs) {
        cfg->print(cfg->name);
    }

    for (auto cfg: cfgs) {
        cfg->optimize();
    }

    return irs;
}