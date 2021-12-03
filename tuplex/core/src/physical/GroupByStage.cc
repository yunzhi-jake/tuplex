//--------------------------------------------------------------------------------------------------------------------//
//                                                                                                                    //
//                                      Tuplex: Blazing Fast Python Data Science                                      //
//                                                                                                                    //
//                                                                                                                    //
//  (c) 2017 - 2021, Tuplex team                                                                                      //
//  Created by Yunzhi Shao first on 11/20/2021                                                                        //
//  License: Apache 2.0                                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

#include <physical/GroupByStage.h>

namespace tuplex {
    GroupByStage::GroupByStage(PhysicalPlan *plan,
                               IBackend *backend,
                               int64_t number,
                               std::vector<size_t> columnIndicesToGroupBy) : PhysicalStage::PhysicalStage(plan, backend, number),
                               _columnIndicesToGroupBy(std::move(columnIndicesToGroupBy)) {}
}