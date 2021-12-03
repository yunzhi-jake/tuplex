//--------------------------------------------------------------------------------------------------------------------//
//                                                                                                                    //
//                                      Tuplex: Blazing Fast Python Data Science                                      //
//                                                                                                                    //
//                                                                                                                    //
//  (c) 2017 - 2021, Tuplex team                                                                                      //
//  Created by Yunzhi Shao first on 11/20/2021                                                                        //
//  License: Apache 2.0                                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

#include <Context.h>
#include "TestUtils.h"

class GroupByTest : public PyTest {};

TEST_F(GroupByTest, GroupBy) {
    using namespace tuplex;
    auto opt = testOptions();
    Context c(opt);

    auto &ds1 = c.parallelize(
            {Row(1, 2, 1), Row(1, 2, 2), Row(2, 2, 3)},
            {"col0", "col1", "col2"});

    auto v1 = ds1.groupBy({0}).collectAsVector();
    ASSERT_EQ(v1.size(), 2);
    EXPECT_EQ(v1[0].toPythonString(), "(1,2,[1,2])");
    EXPECT_EQ(v1[1].toPythonString(), "(2,2,[3])");
}