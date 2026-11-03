#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

string getCategory(const fs::path& file) {
    string ext = file.extension().string();
    transform(ext.begin(), ext.end(), ext.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });

    if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" ||
        ext == ".gif" || ext == ".bmp" || ext == ".webp")
        return "Images";

    if (ext == ".pdf" || ext == ".doc" || ext == ".docx" ||
        ext == ".txt" || ext == ".ppt" || ext == ".pptx" ||
        ext == ".xls" || ext == ".xlsx" || ext == ".csv")
        return "Documents";

    if (ext == ".mp4" || ext == ".mkv" || ext == ".avi" ||
        ext == ".mov" || ext == ".wmv")
        return "Videos";

    if (ext == ".mp3" || ext == ".wav" || ext == ".aac" ||
        ext == ".flac" || ext == ".ogg")
        return "Music";

    return "Others";
}

int main() {
    string input;
    cout << "Enter folder path to organize: ";
    getline(cin, input);

    if (input.empty()) {
        cerr << "Error: folder path cannot be empty.\n";
        return 1;
    }

    fs::path source = fs::u8path(input);

    try {
        if (!fs::exists(source) || !fs::is_directory(source)) {
            cerr << "Error: folder does not exist or is not a directory.\n";
            return 1;
        }

        const string categories[] = {
            "Images", "Documents", "Videos", "Music", "Others"
        };

        for (const auto& category : categories)
            fs::create_directories(source / category);

        size_t moved = 0;
        for (const auto& entry : fs::directory_iterator(source)) {
            if (!entry.is_regular_file())
                continue;

            fs::path file = entry.path();
            fs::path destinationDir = source / getCategory(file);
            fs::path destination = destinationDir / file.filename();

            if (fs::exists(destination)) {
                cerr << "Skipped (name already exists): "
                     << file.filename().string() << '\n';
                continue;
            }

            fs::rename(file, destination);
            cout << "Moved: " << file.filename().string()
                 << " -> " << getCategory(file) << '\n';
            ++moved;
        }

        cout << "\nOrganization completed. Files moved: " << moved << '\n';
    } catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << '\n';
        return 1;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
