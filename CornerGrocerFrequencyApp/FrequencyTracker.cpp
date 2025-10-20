#include "FrequencyTracker.h"
#include <fstream>
#include <stdexcept>
#include <limits>

void FrequencyTracker::LoadFromFile(const std::string& filename) {
	std::ifstream in(filename);
	if (!in.is_open()) {
		throw std::runtime_error("Could not open file: " + filename);
	}

	std::string word;
	while (std::getline(in, word)) {
		// Remove carriage return chars if present
		if (!word.empty() && word.back() == '\r') {
			word.pop_back();
		}

		// Increment frequency count for this item
		if (!word.empty()) {
			++freq_[word];
		}
	}
}

void FrequencyTracker::WriteBackup(const std::string& filename) const {
	std::ofstream out(filename);
	if (!out.is_open()) {
		throw std::runtime_error("Could not open file for writing: " + filename);
	}

	// Write each item and its count
	for (auto it = freq_.begin(); it != freq_.end(); ++it) {
		out << it->first << " " << it->second << '\n';
	}
}

int FrequencyTracker::GetCount(const std::string& item) const {
	// Get the item from the map
	auto it = freq_.find(item);
	// Return count or 0 if not found
	return (it == freq_.end()) ? 0 : it->second;
}

void FrequencyTracker::PrintAll(std::ostream& os) const {
	// Print each item and its count
	for (auto it = freq_.begin(); it != freq_.end(); ++it) {
		os << it->first << ": " << it->second << '\n';
	}
}

void FrequencyTracker::PrintHistogram(std::ostream& os, char symbol) const {
	// Print each item followed by the symbol * repeated count times
	for (auto it = freq_.begin(); it != freq_.end(); ++it) {
		os << it->first << " ";
		for (int i = 0; i < it->second; ++i) {
			os << symbol;
		}
		os << '\n';
	}
}