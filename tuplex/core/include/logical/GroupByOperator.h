//--------------------------------------------------------------------------------------------------------------------//
//                                                                                                                    //
//                                      Tuplex: Blazing Fast Python Data Science                                      //
//                                                                                                                    //
//                                                                                                                    //
//  (c) 2017 - 2021, Tuplex team                                                                                      //
//  Created by Yunzhi Shao first on 11/20/2021                                                                        //
//  License: Apache 2.0                                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

#ifndef TUPLEX_GROUPBYOPERATOR_H
#define TUPLEX_GROUPBYOPERATOR_H

#include "LogicalOperator.h"
#include "LogicalOperatorType.h"

namespace tuplex {
    class GroupByOperator : public LogicalOperator {
    private:
        std::vector<size_t> _columnIndicesToGroupBy;
        std::vector<std::string> _columnNames;

    public:
        GroupByOperator(LogicalOperator *parent, std::vector<size_t> columnIndicesToGroupBy, std::vector<std::string> columnNames);

        std::string name() override { return "groupBy"; }

        LogicalOperatorType type() const override { return LogicalOperatorType::GROUPBY; }

        bool good() const override;

        std::vector<Row> getSample(size_t num) const override;

        bool isActionable() override { return false; }

        bool isDataSource() override { return false; }

        Schema getInputSchema() const override { return parent()->getOutputSchema(); }

        std::vector<std::string> columns() const override;

        LogicalOperator *clone() override;

        std::vector<size_t> getColumnIndicesToGroupBy() { return _columnIndicesToGroupBy; }
    };
}

#endif //TUPLEX_GROUPBYOPERATOR_H