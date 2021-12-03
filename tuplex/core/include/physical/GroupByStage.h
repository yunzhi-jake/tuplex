//--------------------------------------------------------------------------------------------------------------------//
//                                                                                                                    //
//                                      Tuplex: Blazing Fast Python Data Science                                      //
//                                                                                                                    //
//                                                                                                                    //
//  (c) 2017 - 2021, Tuplex team                                                                                      //
//  Created by Yunzhi Shao first on 11/20/2021                                                                        //
//  License: Apache 2.0                                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

#ifndef TUPLEX_GROUPBYSTAGE_H
#define TUPLEX_GROUPBYSTAGE_H

#include "PhysicalStage.h"

namespace tuplex {
    class GroupByStage : public PhysicalStage {
    private:
        std::vector<size_t> _columnIndicesToGroupBy;
        std::shared_ptr<ResultSet> _rs;
        int64_t _outputDataSetID;

    public:
        GroupByStage() = delete;
        GroupByStage(PhysicalPlan *plan, IBackend *backend, int64_t stage_number, std::vector<size_t> columnIndicesToGroupBy);

        ~GroupByStage() override = default;

        EndPointMode outputMode() const override { return EndPointMode::MEMORY; }
        EndPointMode inputMode() const override { return EndPointMode::MEMORY; }

        std::shared_ptr<ResultSet> resultSet() const override { return _rs;}
        void setResultSet(const std::shared_ptr<ResultSet> &rs) { _rs = rs; }

        std::vector<size_t> getColumnIndicesToGroupBy() { return _columnIndicesToGroupBy; }
        int64_t outputDataSetID() const { return _outputDataSetID; }
    };
}

#endif //TUPLEX_GROUPBYSTAGE_H