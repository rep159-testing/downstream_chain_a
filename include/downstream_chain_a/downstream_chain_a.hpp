#ifndef DOWNSTREAM_CHAIN_A__DOWNSTREAM_CHAIN_A_HPP_
#define DOWNSTREAM_CHAIN_A__DOWNSTREAM_CHAIN_A_HPP_

#include <string>

namespace downstream_chain_a
{

/// Process a YAML document through the full chained hierarchy:
/// downstream_chain_a -> downstream_bin_a -> upstream_c -> upstream_b -> upstream_a
std::string chain_label(const std::string & yaml_document);

}  // namespace downstream_chain_a

#endif  // DOWNSTREAM_CHAIN_A__DOWNSTREAM_CHAIN_A_HPP_
