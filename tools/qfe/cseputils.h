#pragma once

#include <string>

namespace execplan
{
class ConstantColumn;
class SimpleFilter;
class ParseTree;
class SimpleColumn;
}  // namespace execplan
#include "calpontsystemcatalog.h"

namespace qfe
{
namespace utils
{
execplan::ConstantColumn* createConstCol(const std::string& valstr);

template <typename T>
execplan::ConstantColumn* createConstCol(const std::string& valstr, T val);

execplan::SimpleFilter* createSimpleFilter(boost::shared_ptr<execplan::CalpontSystemCatalog>& csc,
                                           const execplan::CalpontSystemCatalog::TableColName& tcn,
                                           const std::string& opstr, execplan::ConstantColumn* cc);

void appendSimpleFilter(execplan::ParseTree*& ptree, execplan::SimpleFilter* filter);

void updateParseTree(boost::shared_ptr<execplan::CalpontSystemCatalog>&,
                     execplan::CalpontSelectExecutionPlan*&, execplan::SimpleColumn*, const std::string&,
                     pair<int, string>);

}  // namespace utils
}  // namespace qfe
