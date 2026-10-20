#include "downstream_chain_a/downstream_chain_a.hpp"

#include <string>

#include "downstream_bin_a/downstream_bin_a.hpp"

namespace downstream_chain_a
{

std::string chain_label(const std::string & yaml_document)
{
  std::string result = downstream_bin_a::label_from_yaml(yaml_document);
  if (result == "invalid") {
    return "chain_error: invalid";
  }
  return "chain: " + result;
}

}  // namespace downstream_chain_a
