#include <gtest/gtest.h>

#include "downstream_chain_a/downstream_chain_a.hpp"

TEST(DownstreamChainA, ValidChainedLabel)
{
  EXPECT_EQ(
    "chain: demo: elements=2",
    downstream_chain_a::chain_label("name: demo\nxml: \"<a><b/></a>\"\n"));
}

TEST(DownstreamChainA, InvalidChainedLabel)
{
  EXPECT_EQ(
    "chain_error: invalid",
    downstream_chain_a::chain_label("name: demo\nxml: \"<a>\"\n"));
}

TEST(DownstreamChainA, EmptyOrMalformedYaml)
{
  EXPECT_EQ(
    "chain_error: invalid",
    downstream_chain_a::chain_label("not_a_valid_mapping: [\n"));
}
