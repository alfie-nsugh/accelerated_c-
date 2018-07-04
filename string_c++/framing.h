#ifndef GUARD_framing_h
#define GUARD_framing_h

//framing.h
#include <iostream>
#include <vector>
#include <algorithm>

std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&,
							const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&,
							const std::vector<std::string>&);

#endif
