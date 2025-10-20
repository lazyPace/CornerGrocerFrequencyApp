#ifndef FREQUENCY_TRACKER_H
#define FREQUENCY_TRACKER_H

#include <map>
#include <string>
#include <iostream>

class FrequencyTracker {
public:
	// Load all items from a text file into internal frequency map
	void LoadFromFile(const std::string& filename);

	// Writes "item count" pairs to frequency.dat (backup file)
	void WriteBackup(const std::string& filename = "frequency.dat") const;

	// Return the count for a single item; 0 if not found
	int GetCount(const std::string& item) const;

	// Prints each item and its count
	void PrintAll(std::ostream& os = std::cout) const;

	// Print text histogram
	void PrintHistogram(std::ostream& os = std::cout, char symbol = '*') const;

private:
	// Map to store item frequencies
	std::map<std::string, int> freq_;

};

#endif // FREQUENCY_TRACKER_H
