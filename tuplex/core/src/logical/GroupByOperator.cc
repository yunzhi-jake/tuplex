//--------------------------------------------------------------------------------------------------------------------//
//                                                                                                                    //
//                                      Tuplex: Blazing Fast Python Data Science                                      //
//                                                                                                                    //
//                                                                                                                    //
//  (c) 2017 - 2021, Tuplex team                                                                                      //
//  Created by Yunzhi Shao first on 11/20/2021                                                                        //
//  License: Apache 2.0                                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

#include <logical/GroupByOperator.h>

#include <utility>

namespace tuplex {

    GroupByOperator::GroupByOperator(LogicalOperator *parent,
                                     std::vector<size_t> columnIndicesToGroupBy,
                                     std::vector<std::string> columnNames) : LogicalOperator(parent),
                                     _columnIndicesToGroupBy(std::move(columnIndicesToGroupBy)),
                                     _columnNames(std::move(columnNames)) {
        // take schema from parent node
        setSchema(this->parent()->getOutputSchema());
    }

    bool GroupByOperator::good() const {
        return true;
    }

    std::vector<Row> GroupByOperator::getSample(size_t num) const {
        return {};
    }

    std::vector<std::string> GroupByOperator::columns() const {
        std::vector<std::string> newColumnNames(_columnIndicesToGroupBy.size() + 1);
        for (size_t i = 0; i < _columnIndicesToGroupBy.size(); ++i) {
            newColumnNames[i] = _columnNames[_columnIndicesToGroupBy[i]];
        }
        newColumnNames.back() = "";

        return newColumnNames;
    }

    LogicalOperator *GroupByOperator::clone() {
        auto copy = new GroupByOperator(parent()->clone(), _columnIndicesToGroupBy, _columnNames);

        copy->setDataSet(getDataSet());
        copy->copyMembers(this);
        assert(getID() == copy->getID());
        return copy;
    }
}