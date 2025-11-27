#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

// Map for Category Type to Full Name
const map<char, string> CATEGORY_MAP = {
    {'A', "Competitions"},
    {'B', "Entertainment"},
    {'C', "Social Gatherings"},
    {'D', "Dinners"},
    {'E', "Processions"},
    {'F', "Training Workshops"},
    {'G', "Exams"}
};

// Function to validate a 3-character event code
bool isValidCode(const string& code) {
    if (code.length() != 3) {
        return false;
    }
    char category = code[0];
    string subcategory = code.substr(1);

    // 1. Check Category Letter (A-G)
    if (CATEGORY_MAP.find(category) == CATEGORY_MAP.end()) {
        return false;
    }

    // 2. Check Subcategory Number (01, 02, 03, 04)
    if (subcategory != "01" && subcategory != "02" && subcategory != "03" && subcategory != "04") {
        return false;
    }

    return true;
}

// Function to solve a single test case
void solve() {
    string S;
    cin >> S;

    if (S.empty()) return;

    // --- 1. Parse and Validate all Event Codes ---
    vector<string> all_codes;
    bool error_found = false;
    string first_error_code = "";

    for (int i = 0; i < S.length(); i += 3) {
        if (i + 3 > S.length()) {
            // String length is not a multiple of 3, implies malformed code at the end.
            // Although the constraint says $0 < |S| < 1001$, and typical ICPC problems
            // guarantee a valid structure if not an invalid code itself, we handle this just in case.
            // For simplicity based on samples, we assume malformed codes are always length 3.
            // The sample A01A02A3D02F09 shows "A3D" is the error, which is length 3.
            // If the input was "A01A01A", the error is not explicitly defined, but we'll prioritize
            // the explicit check of the 3-char code.
            break;
        }

        string code = S.substr(i, 3);
        if (!isValidCode(code)) {
            error_found = true;
            first_error_code = code;
            break;
        }
        all_codes.push_back(code);
    }

    // --- 2. Error Output ---
    if (error_found) {
        cout << "-1 " << first_error_code << endl;
        return;
    }

    // --- 3. Sliding Window to find Longest Unique Sequence ---
    // Key: Event code, Value: Index in all_codes (not needed for this specific problem, set is better)
    set<string> seen_codes;
    int max_length = 0;
    vector<string> longest_sequence;
    int start = 0; // Start of the current window

    for (int end = 0; end < all_codes.size(); ++end) {
        string current_code = all_codes[end];

        // Shrink the window if a duplicate is found
        while (seen_codes.count(current_code)) {
            seen_codes.erase(all_codes[start]);
            start++;
        }

        // Expand the window
        seen_codes.insert(current_code);
        int current_length = end - start + 1;

        // Check for new longest sequence and apply tie-breaker
        if (current_length > max_length) {
            max_length = current_length;
            longest_sequence.clear();
            for (int i = start; i <= end; ++i) {
                longest_sequence.push_back(all_codes[i]);
            }
        } else if (current_length == max_length) {
            // Tie-breaker: choose the one that starts with the smallest event alphabetically
            if (all_codes[start] < longest_sequence[0]) {
                longest_sequence.clear();
                for (int i = start; i <= end; ++i) {
                    longest_sequence.push_back(all_codes[i]);
                }
            }
        }
    }

    // --- 4. Count Event Categories ---
    map<string, int> category_counts;
    for (const string& code : longest_sequence) {
        char category_char = code[0];
        string category_name = CATEGORY_MAP.at(category_char);
        category_counts[category_name]++;
    }

    // --- 5. Final Output ---
    stringstream result_ss;

    // 1. Length of the sequence
    result_ss << max_length;

    // 2. List of event codes
    for (const string& code : longest_sequence) {
        result_ss << " " << code;
    }

    // 3. Count of each event type category (in order A, B, C, D, E, F, G implicitly)
    for (const auto& pair : CATEGORY_MAP) {
        string category_name = pair.second;
        if (category_counts.count(category_name) && category_counts[category_name] > 0) {
            result_ss << " " << category_counts[category_name] << " " << category_name;
        }
    }

    cout << result_ss.str() << endl;
}

// Main function in ICPC format
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem statement says the first line contains the number of test cases.
    if (!(cin >> t)) return 0; // Handle case where input fails

    while (t--) {
        solve();
    }

    return 0;
}