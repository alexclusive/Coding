#include <iostream>
#include <string>
#include <filesystem>
#include <boost/algorithm/string.hpp> // For string manipulation
#include <matroska/KaxInfoData.h>
#include <ebml/EbmlHeader.h>
#include <ebml/EbmlStream.h>
using namespace std;

double getDurationMkv(const string& filepath) {
	try {
		ifstream mkvFile(filepath, ios::binary);

		if (!mkvFile) {
			cerr << "Error opening file: " << filepath << endl;
			return 0;
		}

		libmatroska::KaxSegment mkvSegment;
		libebml::EbmlStream stream(mkvFile);
		libebml::EbmlHeader header;

		if (!header.Read(stream) || !mkvSegment.Read(stream, header)) {
			cout << "Error reading MKV file: " << filepath << endl;
			return 0;
		}

		libmatroska::KaxInfoData& infoData = *static_cast<libmatroska::KaxInfoData*>(mkvSegment.Find(libmatroska::ClassInfos[libmatroska::KaxInfo].first));
		double durationSec = static_cast<double>(infoData[libmatroska::KaxDuration]) / 1000000000.0;
		// maybe get hour / min / sec separately
		if (durationSec == 0) {
			// bad duration, will need to get manually
		}
		// convert to Time object from TimeAdd
		return durationSec; // change return to Time object

	} catch (const exception& ex) {
		cout << "Exception: " << ex.what() << endl;
		return 0;
	}
}

bool isMkvFile(const string& filepath) {
	string extension = fs::path(filepath).extension().string();
	boost::algorithm::to_lower(extension); // Convert extension to lowercase for case-insensitive comparison
	return extension == ".mkv";
}

double getDirectoryDuration(const string& filepath, string indent = "") {
	// make timeAdder object
	double totalDuration = 0;
	for (const auto& entry : fs::directory_iterator(filepath)) {
		string filename = entry.path().filename().string();
		cout << indent << "Reading directory: " << filename;
		indent += "\t";

		if (entry.is_directory()) {
			totalDuration += getDirectoryDuration(entry.path().string(), indent);
		} else if (isMkvFile(filename)) {
			totalDuration += getDurationMkv(entry.path().string());
		} else {
			cout << indent << "Unknown file: " << 
		}
	}
	// return timeAdder total Time objectfilename
	return totalDuration;
}

int main() {
	string animePath = "./"
	getDirectoryDuration(animePath);
}